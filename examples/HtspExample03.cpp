#include <iostream>
#include <stdexcept>
#include <string>
#include <htsp/Htsp.h>
#include <htsp/HtspMethodAuthenticate.h>
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
    }
    catch (std::exception& e)
    {
        cerr << "Could not connect to host \"" << hostname << "\" (" << e.what() << ")! Aborting." << endl;
        return 2;
    }

    Flix::HtspMethodHelloResponse helloResponse;
    try
    {
        helloResponse = htsp.performMethodHello({ 31, "libhtsp", "unknown" });
        cout << "hello: " << helloResponse.serverName << "/" << helloResponse.serverVersion << endl;
    }
    catch (std::exception& e)
    {
        cerr << "Could not execute method \"hello\" (" << e.what() << ")!" << endl;
        return 3;
    }

    try
    {
        Flix::HtspMethodAuthenticate methodAuthenticate({ username, password }, helloResponse.challenge);
        htsp.execute(methodAuthenticate);
        if (!methodAuthenticate.getResponse().accessGranted)
        {
            throw std::runtime_error("access denied");
        }
    }
    catch (std::exception& e)
    {
        cerr << "Could not execute method \"authenticate\" (" << e.what() << ")!" << endl;
        return 4;
    }

    try
    {
        Flix::HtspMethodEnableAsyncMetadataRequest request { false };
        Flix::HtspMethodEnableAsyncMetadata methodEnableAsyncMetadata(request);
        htsp.execute(methodEnableAsyncMetadata);
    }
    catch (std::exception& e)
    {
        cerr << "Could not execute method \"enableAsyncMetadata\" (" << e.what() << ")!" << endl;
        return 5;
    }

    htsp.disconnect();
    return 0;
}
