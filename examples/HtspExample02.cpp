#include <iostream>
#include <stdexcept>
#include <string>
#include <networking/Select.h>
#include <htsp/Htsp.h>
#include <htsp/HtspMethodAuthenticate.h>

using namespace std;

void printUsage(const string& programName)
{
    cerr << "USAGE: " << programName << " HOST[:PORT] [USERNAME]" << endl;
    cerr << endl;
    cerr << "Arguments:" << endl;
    cerr << "  HOST     Hostname of TVheadend server" << endl;
    cerr << "  PORT     TCP port of HTSP service (default: " << Flix::Htsp::getDefaultTcpPort() << ")" << endl;
    cerr << "  USERNAME Username to use for authentication" << endl;
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
    }

    Flix::HtspMethodAuthenticateResponse authenticateResponse;
    try
    {
        Flix::HtspMethodAuthenticate methodAuthenticate({ username, password }, helloResponse.challenge);
        htsp.execute(methodAuthenticate);
        authenticateResponse = methodAuthenticate.getResponse();
        cout << "authenticate: accessGranted = " << std::string(authenticateResponse.accessGranted ? "yes" : "no") << endl;
    }
    catch (std::exception& e)
    {
        cerr << "Could not execute method \"authenticate\" (" << e.what() << ")!" << endl;
    }

    htsp.disconnect();
    return 0;
}
