#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, s, t, x[5050], a[5050], b[5050], c[5050], d[5050], e[5050][5];
ll f[5050][2555];

void Umn(auto &x,auto y){
    x=min(x,y);
}

int main(){
    cin>>n>>s>>t;
    for (int i=1;i<=n;++i) cin>>x[i];
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i) cin>>b[i];
    for (int i=1;i<=n;++i) cin>>c[i];
    for (int i=1;i<=n;++i) cin>>d[i];
    for (int i=1;i<=n;++i){
        e[i][1]= (-x[i]+b[i]) + (-x[i]+d[i]);
        e[i][2]= (-x[i]+b[i]) + ( x[i]+c[i]);
        e[i][3]= ( x[i]+a[i]) + (-x[i]+d[i]);
        e[i][4]= ( x[i]+a[i]) + ( x[i]+c[i]);
    }
    memset(f,33,sizeof f);
    if (s==1) f[1][1]=-x[1]+d[1];
    else if (t==1) f[1][0]=-x[1]+b[1];
    else f[1][1]=e[1][1];
    for (int i=2;i<=n;++i)
        for (int j=0;j<=n/2+5;++j){
            int k=j-(s<i)+(t<i);
            if (!j&&!k) continue;
            if (i==s){
                Umn(f[i][j+1],f[i-1][j]+(-x[i]+d[i]));
                if (k) Umn(f[i][j],f[i-1][j]+(x[i]+c[i]));
            }else if (i==t){
                Umn(f[i][j],f[i-1][j]+(-x[i]+b[i]));
                if (j) Umn(f[i][j-1],f[i-1][j]+(x[i]+a[i]));
            }else{
                Umn(f[i][j+1],f[i-1][j]+e[i][1]);
                if (k) Umn(f[i][j],f[i-1][j]+e[i][2]);
                if (j) Umn(f[i][j],f[i-1][j]+e[i][3]);
                if (j&&k) Umn(f[i][j-1],f[i-1][j]+e[i][4]);
            }
        }
    cout<<f[n][0]<<endl;
}