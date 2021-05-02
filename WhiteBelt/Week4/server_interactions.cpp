//
// Created by mikhail on 02.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

string AskTimeServer(){
    throw domain_error("aa");
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
        } catch (const system_error &ex) {

        }
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception &e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
