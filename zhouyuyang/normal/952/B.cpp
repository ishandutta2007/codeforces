#include <bits/stdc++.h>
using namespace std;
int main(){
    bool grumpy = true;
    for (int i = 0; i < 6; i++) {
        cout << i << endl;
        string s;
        getline(cin, s);
        if (s == "cool" || s == "not bad" || s == "great" || s == "don't think so" || s == "don't touch me") {
            grumpy = false;
            break;
        }
    }
    if (grumpy) cout << "grumpy" << endl; else cout << "normal" << endl;
    return 0;
}