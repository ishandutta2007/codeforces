#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    multiset<int> st_f,st_b;
    int ans=0;
    while (n--) {
        string s;
        cin >> s;
        pii p = make_pair(0,0);
        for (char i:s) {
            if (i=='(') {
                ++p.F;
            }
            else {
                if (p.F > 0) {
                    --p.F;
                }
                else {
                    ++p.S;
                }
            }
        }
        if (p.F == 0 && p.S == 0) {
            ++ans;
        }
        else if (p.F == 0) {
            /*if (st_f.find(p.S) != st_f.end()) {
                ++ans;
                st_f.erase(st_f.find(p.S));
            }
            else if (p.S == 0) {
                st_f.insert(p.F);
            }*/
            st_b.insert(p.S);
        }
        else if (p.S == 0) {
            st_f.insert(p.F);
        }
    }
    ans /=2;
    for (int i:st_b) {
        if (st_f.find(i) != st_f.end()) {
            ++ans;
            st_f.erase(st_f.find(i));
        }
    }
    cout << ans << endl;
}