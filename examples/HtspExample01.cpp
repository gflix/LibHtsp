#include <iostream>
#include <stdexcept>
#include <string>
#include <networking/Select.h>
#include <htsp/Htsp.h>

using namespace std;

void printUsage(const string& programName)
{
    cerr << "USAGE: " << programName << " HOST[:PORT]" << endl;
    cerr << endl;
    cerr << "Arguments:" << endl;
    cerr << "  HOST  Hostname of TVheadend server" << endl;
    cerr << "  PORT  TCP port of HTSP service (default: " << Flix::Htsp::getDefaultTcpPort() << ")" << endl;
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

    try
    {
        htsp.connect(hostname);
    }
    catch (std::exception& e)
    {
        cerr << "Could not connect to host \"" << hostname << "\" (" << e.what() << ")! Aborting." << endl;
        return 2;
    }

    try
    {
        Flix::HtspMethodHelloResponse response = htsp.performMethodHello({ 31, "libhtsp", "unknown" });
        cout << "hello: htspVersion = " << response.htspVersion << endl;
        cout << "        serverName = " << response.serverName << endl;
        cout << "     serverVersion = " << response.serverVersion << endl;
        cout << "    len(challenge) = " << response.challenge.size() << endl;
        cout << "          language = " << response.language << endl;
        cout << "serverCapabilities = " << endl;
        for (auto& serverCapability: response.serverCapabilities)
        {
            cout << "                     " << serverCapability << endl;
        }
        cout << "        apiVersion = " << response.apiVersion << endl;
    }
    catch (std::exception& e)
    {
        cerr << "Could not execute method \"hello\" (" << e.what() << ")!" << endl;
    }

    htsp.disconnect();
    return 0;
}
