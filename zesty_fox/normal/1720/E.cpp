// LUOGU_RID: 96657046
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=510,M=N*N;

int n,k,a[N][N],cnt[M],pos[N];

int sum;
void add(int c,int v){
    if(cnt[c]) --sum;
    cnt[c]+=v;
    if(cnt[c]) ++sum;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) add(a[i][j]=rdi(),1);
    if(sum<=k) {cout<<k-sum<<'\n';return 0;}
    bool fl=0;
    for(int i=1;i<=n;i++){
        auto build = [&](){
            fill(cnt+1,cnt+n*n+1,0),sum=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) add(a[i][j],1);
        };
        build();pos[1]=0;
        for(int j=1;j<=n;j++){
            while(pos[j]<n-max(i,j)+1&&sum>k){
                int r=++pos[j];
                for(int k=i;k<=i+r-1;k++) add(a[k][j+r-1],-1);
                for(int k=j;k<j+r-1;k++) add(a[i+r-1][k],-1);
            }
            if(sum==k||sum==k-1) fl=1;
            pos[j+1]=max(pos[j]-1,0);
            if(pos[j]){
                int r=pos[j];
                for(int k=i;k<=i+r-1;k++) add(a[k][j],1);
                for(int k=j+1;k<=j+r-1;k++) add(a[i+r-1][k],1);
            }
        }
    }
    cout<<(fl?1:2)<<'\n';
    return 0;
}