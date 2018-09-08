#ifndef HTSP_HTSP_H_
#define HTSP_HTSP_H_

#include <string>
#include <glisseo/network/tcp/TcpClient.h>
#include <htsp/GenericHtspClientMethod.h>
#include <htsp/GenericHtspMethod.h>
#include <htsp/HtspMessage.h>
#include <htsp/HtspMethodAuthenticate.h>
#include <htsp/HtspMethodEnableAsyncMetadata.h>
#include <htsp/HtspMethodHello.h>

namespace Flix {

class Htsp {
public:
    Htsp();
    virtual ~Htsp();

    void connect(const std::string& host, int port = getDefaultTcpPort());
    void disconnect(void);

    bool isConnected(void) const;
    int getDescriptor(void) const;

    HtspMethodAuthenticateResponse performMethodAuthenticate(
        const HtspMethodAuthenticateRequest& request);
    void performMethodEnableAsyncMetadata(
        const HtspMethodEnableAsyncMetadataRequest& request);
    HtspMethodHelloResponse performMethodHello(
        const HtspMethodHelloRequest& request);

    void execute(GenericHtspMethod& method);

    void sendMessage(const HtspMessage& message);
    void sendMessages(const HtspMessages& messages);
    void receiveMessages(HtspMessages& messages);

    void appendReceivedData(const std::string& receivedData);
    void resetReceiveBuffer(void);
    bool hasMessage(void) const;
    void getMessages(HtspMessages& messages);

    void getClientMethods(HtspMessages& messages, HtspClientMethods& clientMethods);

    static std::string getPackageInfo(void);
    static int getDefaultTcpPort(void);

private:
    Glisseo::TcpClient tcpClient;
    std::string receiveBuffer;

    std::string authenticationChallenge;

    size_t getLength(const std::string& value) const;
};

} /* namespace Flix */

#endif /* HTSP_HTSP_H_ */
