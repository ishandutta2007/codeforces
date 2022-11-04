#include <bits/stdc++.h>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())
using namespace std;
typedef long long ll;
int n, m; ll t;
int s[300005]; char d[300005];
pair<int,int> o[300005];
int res[300005];
int main() {
    scanf("%d%d%lld", &n, &m, &t);
    FO(i,0,n) scanf("%d %c", s+i, d+i), s[i]--;
    FO(i,0,n) o[i] = make_pair(s[i],i);
    sort(o,o+n);
    vector<ll> p;
    ll nc = 0;
    FO(i,0,n) {
        int dir = d[i] == 'L' ? -1 : 1;
        ll pos = s[i] + dir * t;
        ll fp = ((pos%m)+m)%m;
        ll g = pos > 0 ? pos / m : (pos-m+1) / m;
        nc += g;
        p.push_back(fp);
    }
    nc = ((nc%n)+n)%n;
    sort(p.begin(),p.end());
    FO(i,0,n) res[o[i].second] = p[(i+nc)%n];
    FO(i,0,n) printf("%d%c", res[i]+1, " \n"[i+1==n]);
}