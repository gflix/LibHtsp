#include <iostream>
#include <string>
#include <networking/Select.h>
#include <htsp/Htsp.h>
#include <htsp/HtspMethodHello.h>

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
    catch (std::string& e)
    {
        cerr << "Could not connect to host \"" << hostname << "\" (" << e << ")! Aborting." << endl;
        return 2;
    }

    Flix::HtspMethodHello htspMethodHello({ 31, "libhtsp", "unknown" });

    try
    {
        htsp.execute(htspMethodHello);
    }
    catch (std::string& e)
    {
        cerr << "Could not execute method \"hello\" (" << e << ")!" << endl;
    }

    Flix::HtspMethodHelloResponse htspMethodHelloResponse = htspMethodHello.getResponse();
    cout << "hello: htspVersion = " << htspMethodHelloResponse.htspVersion << endl;
    cout << "        serverName = " << htspMethodHelloResponse.serverName << endl;
    cout << "     serverVersion = " << htspMethodHelloResponse.serverVersion << endl;

    Flix::HtspMessages htspMessages = htspMethodHello.getResponseMessages();
    cout << "htspMessages=" << htspMessages.size() << endl;
    for (auto& htspMessage: htspMessages)
    {
        cout << htspMessage << endl;
    }

    htsp.disconnect();
    return 0;
}
