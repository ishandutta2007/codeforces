#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=505;

int n,a[N],f[N][N][N];

template<typename T>
void ckmax(T &a,T b) {if(a<b) a=b;}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++)
        a[i]=rdi();
    memset(f,0xc0,sizeof(f));
    f[1][1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            static int mx[N];
            mx[0]=f[i][j][0];
            for(int k=1;k<=n;k++){
                auto &v=f[i][j][k];
                mx[k]=max(mx[k-1],v);
                if(v<0) continue;
                ckmax(f[i+1][j][k],v+a[k]);
            }
            for(int mid=i;mid<=n&&mid-i<=j;mid++)
                ckmax(f[i+1][j-(mid-i)+1][mid],mx[mid-1]+a[mid]);
        }
    }
    int ans=INT_MIN;
    for(int j=0;j<=n;j++)
        for(int k=1;k<=n;k++)
            ans=max(ans,f[n+1][j][k]);
    cout<<ans<<'\n';
    return 0;
}