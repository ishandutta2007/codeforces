#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
#define up(it,vec) for(auto it=vec.begin();it!=vec.end();it++)
#define dn(it,vec) for(auto it=vec.rbegin();it!=vec.rend();it++)
// #define int long long

ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}

int a[1000010];
int c[1000010];
ll d[1000010];
inline bool cmp(int a,ll b,int c,ll d){
    return b*c>=d*a;
}
int read()        
{        
    int s = 0, f = 1;        
    char ch = getchar();        
    while(!isdigit(ch)) {        
        if(ch == '-') f = -1;        
        ch = getchar();        
    }        
    while(isdigit(ch)) {        
        s = s * 10 + ch - '0';        
        ch = getchar();        
    }        
    return s * f;        
}     
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int p=0;
    for(int i=1;i<=n;i++){
        c[++p]=1;
        d[p]=a[i];
        while(p>=2&&cmp(c[p-1],d[p-1],c[p],d[p])){
            c[p-1]+=c[p];
            d[p-1]+=d[p];
            p--;
        }
    }
    for(int i=1;i<=p;i++){
        double tmp=(double)d[i]/c[i];
        // cout<<c[i].first<<" "<<c[i].second<<endl;
        for(int j=1;j<=c[i];j++){
            printf("%.9lf\n",tmp);
        }
    }
}