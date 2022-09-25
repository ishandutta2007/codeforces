#include <iostream>
#include <set>
using namespace std;

int main() {

    string s;
    cin >> s;
    set<string> a;
    for (char c = 'a'; c <= 'z'; ++c) {
        for (int i = 0; i < (int)s.size() + 1; i++){
            string t = s.substr(0, i) + c + s.substr(i);
            a.insert(t);

        }
        
    }
    cout << a.size() << endl;
}