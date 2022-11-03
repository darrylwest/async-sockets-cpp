#include "../async-sockets/include/tcpsocket.hpp"
#include <iostream>

using namespace std;

int main() {

    string host = "plaza.local";
    int port = 28800;

    // Initialize socket.
    TCPSocket tcpSocket([](int errorCode, std::string errorMessage){
        cout << "Socket creation error:" << errorCode << " : " << errorMessage << endl;
    });

    // Start receiving from the host.
    tcpSocket.onMessageReceived = [](string message) {
        cout << message << endl;
        cout << flush;

        return 0;
    };

    // If you want to use raw bytes instead of std::string:
    /*
    tcpSocket.onRawMessageReceived = [](const char* message, int length) {
        cout << "Message from the Server: " << message << "(" << length << ")" << endl;
    };
    */
    
    // On socket closed:
    tcpSocket.onSocketClosed = [](int errorCode){
        cout << "Connection closed: " << errorCode << endl;
    };

    // Connect to the host.
    tcpSocket.Connect(host, port, [&] {
        cout << "Connected to the server successfully." << endl;

        // Send String:
        tcpSocket.Send("get /keys/redis_farm_key");
    },
    [](int errorCode, std::string errorMessage){
        // CONNECTION FAILED
        cout << errorCode << " : " << errorMessage << endl;
    });

    // You should do an input loop so the program will not end immediately:
    // Because socket listenings are non-blocking.
    string input;
    // should replace with a timeout sleep...
    getline(cin, input);

    tcpSocket.Close();

    return 0;
}
