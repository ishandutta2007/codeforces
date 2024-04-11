#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

vector<int> va[27],vb[27];

int main () {
    int n; cin >> n;
    string a,b; cin >> a >> b;
    for (int i=0;i<n;++i) {
        if (a[i] == '?') va[0].push_back(i+1);
        else va[ a[i]-'a'+1 ].push_back(i+1);
        if (b[i] == '?') vb[0].push_back(i+1);
        else vb[ b[i]-'a'+1 ].push_back(i+1);
    }
    vector<pii> ans;
    for (int i=1;i<=26;++i) {
        while (va[i].size() && vb[i].size()) {
            ans.push_back(make_pair(va[i].back(),vb[i].back()));
            va[i].pop_back();
            vb[i].pop_back();
        }
    }
    for (int i=1;i<=26;++i) {
        while (va[0].size() && vb[i].size()) {
            ans.push_back(make_pair(va[0].back(),vb[i].back()));
            va[0].pop_back();
            vb[i].pop_back();
        }
    }
    for (int i=1;i<=26;++i) {
        while (vb[0].size() && va[i].size()) {
            ans.push_back(make_pair(va[i].back(),vb[0].back()));
            vb[0].pop_back();
            va[i].pop_back();
        }
    }
    while (va[0].size() && vb[0].size()) {
        ans.push_back(make_pair(va[0].back(),vb[0].back()));
        va[0].pop_back();
        vb[0].pop_back();
    }
    cout << ans.size() <<endl;
    for (pii p:ans) {
        cout << p.F << ' ' << p.S << endl;
    }
}