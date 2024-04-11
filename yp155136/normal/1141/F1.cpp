#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int N = 1506;
int a[N];
int pre[N];

vector<pii> v[N*N];

int main () {
    int n; cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    map<int,int> mp;
    int ptr=0;
    for (int l=0;l<=n;++l) {
        for (int r=l+1;r<=n;++r) {
            int _ = pre[r] - pre[l];
            int ret=0;
            if (mp.find(_) != mp.end()) ret = mp[_];
            else {
                mp[_] = (++ptr);
                ret = ptr;
            }
            v[ret].push_back(make_pair(r,l+1));
        }
    }
    int mx_ans = -1;
    int mx_id = -1;
    for (int i=1;i<=ptr;++i) {
        vector<pii> vv = v[i];
        sort(vv.begin(),vv.end());
        int tmp=0;
        int saki=0;
        for (pii p:vv) {
            if (p.S > tmp) {
                tmp = p.F;
                ++saki;
            }
        }
        if (saki > mx_ans) {
            mx_ans = saki;
            mx_id = i;
        }
        v[i] = vv;
    }
    cout << mx_ans << endl;
    vector<pii> vv = v[(int)mx_id];
    int tmp=0;
    for (pii p:vv) {
        if (p.S > tmp) {
            tmp = p.F;
            cout << p.S << ' ' << p.F << endl;
        }
    }
}