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

const int N=1e6+10,M=5e6+10,INF=0x3f3f3f3f;

int n,m,L[M],R[M];

short fac[(int)(M*6.79)];
int val[(int)(M*6.79)];

void init(int n){
    for(int i=2;i*i<=n;i++)
        for(int j=i*i;j<=n;j+=i) L[j]++;
    int sum=0;
    for(int i=1;i<=n;i++){
        int s1=sum;sum+=L[i];
        L[i]=R[i]=s1;
    } 
    for(int i=2;i*i<=n;i++)
        for(int j=i*i;j<=n;j+=i) fac[R[j]]=i,val[R[j]]=j/i,++R[j];
    for(int x=2;x<=n;x++){
        for(int j=L[x];j<R[x];j++){
            int to=x/fac[j];
            int pos=lower_bound(fac+L[to],fac+R[to],fac[j])-fac;
            if(pos==R[to]) continue;
            val[j]=min(val[j],val[pos]);
        }
        for(int j=R[x]-2;j>=L[x];j--) val[j]=min(val[j],val[j+1]);
    }
}

int mx[M];
bitset<M> vis;

void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++){
        int x=rdi(),lst=0;
        if(vis[x]) continue;
        vis[x]=1;
        for(int j=L[x];j<R[x];j++)
            mx[lst+1]=max(mx[lst+1],val[j]),lst=fac[j];
        mx[lst+1]=max(mx[lst+1],x),lst=x,mx[lst+1]=INF;
    }

    int ans=INF;
    for(int i=1;i<=m;i++){
        mx[i]=max(mx[i],mx[i-1]);
        ans=min(ans,mx[i]-i);
    }
    cout<<ans<<'\n';

    for(int i=0;i<=m+1;i++) mx[i]=vis[i]=0;
}

int main(){
    init(M-10);
    int T=rdi();
    while(T--) solve();
    return 0;
}