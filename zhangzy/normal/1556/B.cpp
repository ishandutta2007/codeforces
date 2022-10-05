#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N=1e5+5;
const ll inf=1e16+7;
using namespace std;

int n,a[N];

ll calc(int c){
    int cnt=0;
    rep(i,1,n)cnt+=a[i]==c;
    if(cnt!=(n+1)/2)return inf;
    cnt=0;ll res=0;
    rep(i,1,n)if(a[i]==c){
        ++ cnt;
        int pos=cnt*2-1;
        if(i>pos)res+=i-pos;else res+=pos-i;
    }
    return res;
}

void Solve(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]),a[i]&=1;
    ll res=min(calc(0),calc(1));
    if(res==inf)puts("-1");else printf("%lld\n",res);
}

int main() {
    int T;
    scanf("%d",&T);
    for(;T--;)Solve();
    return 0;
}