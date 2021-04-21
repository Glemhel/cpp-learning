//
// Created by mikhail on 21.04.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int ComputeDistance(const string& source, const string& destination) {
    return source.length() - destination.length();
}

class Route {
public:
    string GetSource() const {
        return source;
    }
// Прокрутите код, чтобы увидеть полностью на мобильных устройствах
    string GetDestination() const {
        return destination;
    }
    int GetLength() const {
        return length;
    }
    void SetSource(const string& new_source) {
        source = new_source;
        UpdateLength();
    }
    void SetDestination(const string& new_destination) {
        destination = new_destination;
        UpdateLength();
    }

private:
    void UpdateLength() {
        length = ComputeDistance(source, destination);
    }
    string source;
    string destination;
    int length;
};

void PrintRoute(const Route& route){
    cout << route.GetSource();
}


int main() {

    return 0;
}
