#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef long long ll;
ll l,r,mid,ans,n,k,p,o,cnt,cc,fa[maxn],s[maxn],last,now;
vector <int> h[maxn];

ll check(ll x){
    p=1; o=1; cnt=0; cc=0;
    for (int i=1;i<=n;i++){
        cc++; cnt+=o;
        if (cnt>k) return k+1;
        if (cc==p) cc=0,p=p*x,o++;
    }
    return cnt;
}

ll calc(ll x,ll o,ll n){
    ll ret=0;
    while (n){
        x=x*r;
        ll gt=min(n,x); o++;
        n-=gt; ret+=o*gt; 
    }
    return ret;
}

int main(){
    cin >> n >> k;
    if (k>n*(n+1)/2) {puts("No");return 0;}
    if (k==n*(n+1)/2) {
        puts("Yes");
        for (int i=1;i<n;i++) printf("%d ",i); puts("");
        return 0;
    }
    if (k<2*n-1) {puts("No");return 0;}
    l=1; r=n-1;
    while (r-l>1){
        mid=(l+r)>>1;
        if (check(mid)>k) l=mid; else r=mid;
    }
    last=1; now=1; o=2; k-=3;
    h[1].push_back(1);
    h[2].push_back(2);
    for (int i=3;i<=n;i++){
        if (now==last*r||calc(now,o,n-i+1)<=k) last=now,now=1,o++; else now++;
        k-=o; h[o].push_back(i); s[i]=o;
    }
    for (int i=2;i<=n;i++){
        assert(h[i].size()<=r*h[i-1].size());
        for (int j=0;j<h[i].size();j++)
            fa[h[i][j]]=h[i-1][j/r];
    }
    puts("Yes");
    for (int i=2;i<=n;i++) printf("%d ",fa[i]); puts("");
    return 0;
}