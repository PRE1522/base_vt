#include <iostream>
#include <string>
#include "Socket.h"

using namespace std;

int main() {
        try {
                Connection conn = PortListener(8080).waitForConnection();

                while(1) {
                        printf("> Client: \n");
                        printf("%s\n", conn.re().c_str());
                        printf("> Server: ");
                        string s = "";
                        while(s == "") {
                                getline(cin, s);
                        }
                        conn.se(s);
                }


                close(conn.getSocket());
        } catch (runtime_error &e) {
                cerr << e.what() << endl;
                return EXIT_FAILURE;
        }
        return 0;
}