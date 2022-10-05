#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, mod;
int c[4004000];

int fuck;

void add(int x,int v){
    fuck=(fuck+v)%mod;
    c[x]=(c[x+1]+v)%mod;
}
ll que(int x){
    // ll t=0;
    // for (;x;x-=(x&-x)) t=(t+c[x])%mod;
    // return t;
    return (fuck+mod-c[x+1])%mod;
}
ll que(int l,int r){
    return (que(min(r,n))-que(l-1)+mod)%mod;
}

int f[4004000];

int main(){
    cin>>n>>mod;
    f[n]=1; add(n,1);
    ll now=1;
    for (int i=n-1;i>=1;--i){
        ll sum=0;
        for (int j=2;i*j<=n;++j){
            sum=(sum+que(i*j,(i+1)*j-1))%mod;
        }
        f[i]=(sum+now)%mod;
        add(i,f[i]);
        now=(now+f[i])%mod;
    }
    cout<<f[1]<<endl;
}