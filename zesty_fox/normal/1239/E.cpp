#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=53,M=50010;

int n,a[N],res[3][N];

bitset<N*M/2> pre[N][N/2],f[N][N/2];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=2*n;i++) a[i]=rdi();
    sort(a+1,a+2*n+1);
    res[1][1]=a[1],res[2][n]=a[2];

    int sum=0;
    for(int i=3;i<=2*n;i++) sum+=a[i];

    f[2][0]=1;
    for(int i=3;i<=2*n;i++){
        for(int j=0;j<=min(i-2,n-1);j++){
            if(j) pre[i][j]=(f[i-1][j-1]<<a[i]);
            f[i][j]=pre[i][j]|f[i-1][j];
        }
    }

    int now=sum/2;
    for(;now>=0;now--) if(f[2*n][n-1][now]) break;

    int pos1=2,pos2=1,cnt=0;
    for(int i=2*n;i>=3;i--){
        if(pre[i][n-1-cnt][now]) now-=a[i],res[1][pos1++]=a[i],cnt++;
        else res[2][pos2++]=a[i];
    }

    sort(res[1]+2,res[1]+n+1);sort(res[2]+1,res[2]+n,greater<int>());
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++) cout<<res[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}