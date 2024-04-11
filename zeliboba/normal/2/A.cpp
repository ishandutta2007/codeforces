#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> vname(n);
    vector<int> vscore(n);
    map<string, int> totscore, curscore;
    for (int i = 0; i < n; ++i) {
        cin >> vname[i] >> vscore[i];
        totscore[vname[i]] += vscore[i];
    }
    int ma = 0;
    for (map<string, int>::iterator it = totscore.begin(); it != totscore.end(); ++it) {
        ma = max(ma, it->second);
    }
    for (int i = 0; i < n; ++i) {
        curscore[vname[i]] += vscore[i];
        if (curscore[vname[i]] >= ma && totscore[vname[i]] == ma) {
            cout << vname[i] << endl;
            return 0;
        }
    }
    return 0;
}