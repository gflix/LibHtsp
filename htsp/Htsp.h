#ifndef HTSP_HTSP_H_
#define HTSP_HTSP_H_

#include <string>
#include <networking/tcp/TcpClient.h>
#include "HtspMessage.h"

namespace Flix {

class Htsp {
public:
    Htsp();
    virtual ~Htsp();

    void connect(const std::string& host, int port);
    void disconnect(void);

    bool isConnected(void) const;

    void appendReceivedData(const std::string& receivedData);
    void resetReceiveBuffer(void);
    bool hasMessage(void) const;
    void getHtspMessages(HtspMessages& messages);

    static std::string getPackageInfo(void);

private:
    TcpClient tcpClient;
    std::string receiveBuffer;

    size_t getLength(const std::string& value) const;
};

} /* namespace Flix */

#endif /* HTSP_HTSP_H_ */
