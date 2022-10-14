#include <iostream>
#include "Socket.h"
#include <string.h>
#include <fstream>

using namespace std;

int tran(string s) {
        s += "> re.txt";
        int x = system(s.c_str());
        return x;
}

int main(int argc, char const *argv[]) {
        try {
                Connection conn("127.0.0.1",8080);
                printf("> Client: Hello Server!");
                conn.se("Hello Server!");
                while(1) {
                        printf("> Server: ");
                        string s = conn.re();
                        printf("%s\n", s.c_str());
                        string buff = "";
                        int k = tran(s);
                        if (k == 0) {
                                ifstream ifs("re.txt");
                                if (ifs) {
                                        
                                        string ss = "";
                                        getline(ifs, ss);
                                        buff += ss;
                                        while (getline(ifs, ss)) {
                                                buff += "\n" + ss;
                                        }
                                }
                        }
                        printf("> Client: ");
                        if (buff == "") 
                        {
                                if ( k == 0 ) buff = "done!";
                                        else buff = "fail!";
                        }
                        printf("\n%s\n", buff.c_str());
                        conn.se(buff);
                }
                
                close(conn.getSocket());
                
        } catch (exception &e) {
                cerr << e.what() << endl;
                return EXIT_FAILURE;
        }
    return 0;
}