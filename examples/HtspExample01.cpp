#include <iostream>
#include <string>
#include <networking/Select.h>
#include <htsp/Htsp.h>
#include <htsp/HtspMessage.h>

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

    Flix::HtspMessage htspMessage;
    htspMessage.appendString("method", "hello");
    htspMessage.appendSigned64("htspversion", 31);
    htspMessage.appendString("clientname", "libhtsp");
    htspMessage.appendString("clientversion", "unknown");

    htsp.sendMessage(htspMessage);

    Flix::Select select;
    select.addReadDescriptor(htsp.getDescriptor());
    select.setTimeout(10);

    if (select.execute() <= 0)
    {
        cerr << "Reading from server timed out! Aborting." << endl;
        return 3;
    }

    Flix::HtspMessages htspMessages;
    try
    {
        htsp.receiveMessages(htspMessages);
    }
    catch (std::string& e)
    {
        cerr << "Could not receive from host (" << e << ")! Aborting." << endl;
        return 4;
    }

    cout << "htspMessages=" << htspMessages.size() << endl;
    for (auto& htspMessage: htspMessages)
    {
        cout << htspMessage << endl;
    }

    htsp.disconnect();
    return 0;
}
