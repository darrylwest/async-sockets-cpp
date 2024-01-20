#include "../async-sockets/include/udpsocket.hpp"
#include <iostream>

using namespace std;

int main() {
    // Our constants:
    const string IP = "10.0.1.237";
    const uint16_t PORT = 22200;

    // Initialize socket.
    UDPSocket udpSocket(true); // "true" to use Connection on UDP. Default is "false".
    udpSocket.Connect(IP, PORT);

    // Send String:
    cout << "send status" << endl;
    udpSocket.SendTo("status", IP, PORT);
    //udpSocket.SendTo("ABCDEFGH", IP, PORT); // If you want to connectless

    udpSocket.onRawMessageReceived = [&](const char* message, int length, string ipv4, uint16_t port) {
        cout << ipv4 << ":" << port << " => " << message << "(" << length << ")" << endl;
    };
    

    udpSocket.Close();

    return 0;
}
