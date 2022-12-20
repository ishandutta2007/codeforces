#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=110,INF=0x3f3f3f3f;

int n;
pii a[N];
i64 f[N][N][2],ans;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++)
        a[i].fi=rdi(),a[i].se=rdi();
    a[0].fi=-INF;sort(a+1,a+n+1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int p=0;p<2;p++){
                ans=max(ans,f[i][j][p]);
                int o=a[j].fi+p*a[j].se,mx=-INF,x,y;
                for(int k=i+1;k<=n;k++){
                    for(int q=0;q<2;q++){
                        int t=a[k].fi+q*a[k].se;
                        if(t>mx) mx=t,x=k,y=q;
                        f[k][x][y]=max(f[k][x][y],f[i][j][p]+min(t-o,a[k].se)+mx-t);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}