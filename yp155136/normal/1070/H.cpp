#include <bits/stdc++.h>
using namespace std;

const int N = 600006;

vector<int> v[N];

string ss[N];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    map<string,int> mp;
    int id = 0;
    for (int i=0;i<n;++i) {
        string s;
        cin >> s;
        ss[i] = s;
        int sz = (int)s.size();
        set<string> st;
        for (int l=0;l<sz;++l) {
            string t = "";
            for (int r=l;r<sz;++r) {
                t.push_back(s[r]);
                st.insert(t);
            }
        }
        for (string t:st) {
            if (mp.find(t) == mp.end()) {
                mp[t] = (++id);
            }
            int _ = mp[t];
            v[_].push_back(i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (mp.find(s) == mp.end()) cout << "0 -" << endl;
        else {
            int id = mp[s];
            cout << (int)v[id].size() << ' ' << ss[ v[id][0] ] << endl;
        }
    }
}