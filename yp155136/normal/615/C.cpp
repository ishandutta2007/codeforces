#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> piiii;
const ll mod1 = 1000000087;
const ll mod2 = 998244353;
const ll X1 = 880301;
const ll X2 = 1009;
#define F first
#define S second
const int N = 2106;

pii operator+(const pii &p1,const pii &p2) {
    return make_pair((p1.F+p2.F)%mod1,(p1.S+p2.S)%mod2);
}

pii operator-(const pii &p1,const pii &p2) {
    return make_pair((p1.F-p2.F+mod1)%mod1,(p1.S-p2.S+mod2)%mod2);
}

pii operator*(const pii &p1,const pii &p2) {
    return make_pair(p1.F*1ll*p2.F%mod1,p1.S*1ll*p2.S%mod2);
}

pii pre[N];
pii ppow[N];

vector<piiii> v;

const pii yuuki = make_pair(-1,-1);

bool hhave(pii p) {
    auto iter = lower_bound(v.begin(),v.end(),make_pair(p,yuuki));
    if (iter == v.end()) return false;
    if (iter->F != p) return false;
    return true;
}

pii get_range(pii p) {
    auto iter = lower_bound(v.begin(),v.end(),make_pair(p,yuuki));
    return iter->S;
}

pii hash_val(int L,int R) {
    return (pre[R] - pre[L-1]) * ppow[N-L-2];
}

int main () {
    ppow[0] = make_pair(1,1);
    for (int i=1;i<N;++i) {
        ppow[i] = (ppow[i-1]) * (make_pair(X1,X2));
    }
    string s; cin >> s;
    set<char> st;
    for (char i:s) st.insert(i);
    string t; cin >> t;
    for (char i:t) {
        if (st.find(i) == st.end()) {
            cout << -1 << endl;
            return 0;
        }
    }
    int n = (int)s.size();
    //L ~ R
    for (int i=1;i<=n;++i) {
        pre[i] = pre[i-1] + (make_pair(s[i-1],s[i-1])*ppow[i]);
    }
    for (int i=1;i<=n;++i) {
        for (int j=i;j<=n;++j) {
            pii val = (pre[j] - pre[i-1]) * ppow[N-i-2];
            v.push_back({val,{i,j}});
        }
    }
    reverse(s.begin(),s.end());
    for (int i=1;i<=n;++i) {
        pre[i] = pre[i-1] + (make_pair(s[i-1],s[i-1])*ppow[i]);
    }
    for (int i=1;i<=n;++i) {
        for (int j=i;j<=n;++j) {
            pii val = (pre[j] - pre[i-1]) * ppow[N-i-2];
            v.push_back({val,{n-i+1,n-j+1}});
        }
    }
    sort(v.begin(),v.end());
    t += "*";
    int m = (int)t.size();
    for (int i=1;i<=m;++i) {
        pre[i] = pre[i-1] + (make_pair(t[i-1],t[i-1])*ppow[i]);
    }
    vector<pii> ans;
    for (int i=1;i<=m;) {
        int j = i;
        while (hhave(hash_val(i,j))) ++j;
        ans.push_back(get_range(hash_val(i,j-1)));
        i = j;
        if (i == m) break;
    }
    cout << ans.size() << endl;
    for (pii p:ans) cout << p.F << ' ' << p.S << endl;
}