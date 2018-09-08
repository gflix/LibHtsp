#include <iostream>
#include <stdexcept>
#include <string>
#include <glisseo/utils/Select.h>
#include <htsp/Htsp.h>
#include <htsp/HtspMethodEnableAsyncMetadata.h>

using namespace std;

void printUsage(const string& programName)
{
    cerr << "USAGE: " << programName << " HOST[:PORT] [USERNAME] [PASSWORD]" << endl;
    cerr << endl;
    cerr << "Arguments:" << endl;
    cerr << "  HOST      Hostname of TVheadend server" << endl;
    cerr << "  PORT      TCP port of HTSP service (default: " << Flix::Htsp::getDefaultTcpPort() << ")" << endl;
    cerr << "  USERNAME  Username to use for authentication" << endl;
    cerr << "  PASSWORD  Password to use for authentication" << endl;
    cerr << endl;
}

int main(int argc, char* argv[])
{
    string programName { argv[0] };
    if (argc < 2)
    {
        printUsage(programName);
        return 1;
    }

    Flix::Htsp htsp;
    string hostname { argv[1] };
    string username;
    string password;
    if (argc >= 3)
    {
        username = argv[2];
    }
    if (argc >= 4)
    {
        password = argv[3];
    }

    try
    {
        htsp.connect(hostname);

        Flix::HtspMethodHelloResponse helloResponse = htsp.performMethodHello({ 31, "libhtsp", "unknown" });
        cout << "hello: " << helloResponse.serverName << "/" << helloResponse.serverVersion << endl;

        if (!htsp.performMethodAuthenticate({ username, password }).accessGranted)
        {
            throw std::runtime_error("access denied");
        }
    }
    catch (std::exception& e)
    {
        cerr << "Could not authenticate to server (" << e.what() << ")!" << endl;
        return 2;
    }

    try
    {
        Flix::HtspMethodEnableAsyncMetadataRequest request { false };
        htsp.performMethodEnableAsyncMetadata(request);
    }
    catch (std::exception& e)
    {
        cerr << "Could not execute method \"enableAsyncMetadata\" (" << e.what() << ")!" << endl;
        return 3;
    }

    size_t totalMessageCount = 0;
    Flix::HtspMessages messages;
    Glisseo::Select htspSelect;
    htspSelect.addReadDescriptor(htsp.getDescriptor());
    htspSelect.setAutoReloadTimeout(true);
    htspSelect.setTimeout(5);
    while (htspSelect.execute() > 0)
    {
        htsp.receiveMessages(messages);
        totalMessageCount += messages.size();
        cout << "message count: " << messages.size() << ", total: " << totalMessageCount << endl;
    }

    htsp.disconnect();
    return 0;
}
