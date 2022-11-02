#include <bits/stdc++.h>
using namespace std;
int n;
map<string,int> cnt;
map<string, string> file;
int main() {
    int n;
    cin >> n;
    set<string> S;
    while (n--) {
        string s;
        cin >> s;
        int k = s.size();
        S.clear();
        for (int i = 0; i < k; i++)
        for (int j = i; j < k; j++) {
            string ss = s.substr(i, j - i + 1);
            if (!S.count(ss)) {
                cnt[ss]++;
                file[ss] = s; 
            }
            S.insert(ss);      
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (cnt.count(s)) {
            cout << cnt[s] << " " << file[s] << endl;
        }
        else cout << "0 -" << endl;
    }

}