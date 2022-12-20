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

const int N=200010;

int n,a[2][N],b[2][N];
i64 ans;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    int suma=0,sumb=0;
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++) a[i][j]=rdi(),suma+=a[i][j];
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++) b[i][j]=rdi(),sumb+=b[i][j];
    if(suma!=sumb) return puts("-1"),0;
    int sum[2]={0,0};
    for(int i=1;i<=n;i++){
        sum[0]+=a[0][i]-b[0][i],sum[1]+=a[1][i]-b[1][i];
        if(sum[0]<0&&sum[1]>0){
            int tmp=min(-sum[0],sum[1]);
            sum[0]+=tmp,sum[1]-=tmp,ans+=tmp;
        }
        else if(sum[0]>0&&sum[1]<0){
            int tmp=min(sum[0],-sum[1]);
            sum[0]-=tmp,sum[1]+=tmp,ans+=tmp;
        }
        ans+=abs(sum[0])+abs(sum[1]);
    }
    cout<<ans<<endl;
    return 0;
}