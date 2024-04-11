#include<bits/stdc++.h>
#define ll long long
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
int n,m;
#define maxn 200005
char str[maxn];
int N;
int f[maxn];
int p[maxn];
int fa[maxn],sz[maxn];
bool cmp(int A,int B) {return f[A]<f[B];}
bool vis[maxn];
inline int find(int v) {return fa[v]==v?v:fa[v]=find(fa[v]);}
void uni(int x,int y) {
    sz[find(x)]+=sz[find(y)];
    fa[find(y)]=fa[find(x)];
}
ll tr1[maxn],tr2[maxn];
inline void add(int x) {
    for(int i=x+n;i;i-=i&-i) tr1[i]++,tr2[i]+=x;
}
inline ll query1(int x) {
    ll ans=0;
    for(int i=x+n;i<=2*n;i+=i&-i) ans+=tr1[i];
    return ans;

}
inline ll query2(int x) {
    ll ans=0;
    for(int i=x+n;i<=2*n;i+=i&-i) ans+=tr2[i];
    return ans;
}
void solve() {
    n=rd();
    scanf("%s",str+1);
    p[0]=0;
    for(int i=1;i<=n;i++) {
        f[i]=f[i-1]+(str[i]=='('?1:-1);
        p[i]=i;
    }
    ll sum=0;
    std::sort(p,p+1+n,cmp);
    for(int i=0;i<=n+1;i++) {
        fa[i]=i,sz[i]=1;vis[i]=0;
    }
    for(int i=n;i>=0;i--) {
        // printf("%d %d\n",p[i],f[p[i]]);
        int L=1,R=1;
        if (p[i]>0&&vis[p[i]-1]) {
            // printf("%d\n",p[i]-1);
            L=sz[find(p[i]-1)]+1;
        }
        if (vis[p[i]+1]) {
            R=sz[find(p[i]+1)]+1;
        }
        if (vis[p[i]+1]) {
            R=sz[find(p[i]+1)]+1;
        }
        sum-=1ll*(1ll*R*L-1)*f[p[i]];
        if (p[i]>0&&vis[p[i]-1]) {
            uni(p[i],find(p[i]-1));
        }
        if (vis[p[i]+1]) {
            uni(p[i],find(p[i]+1));
        }
        vis[p[i]]=1;
    }
    // printf("%d\n",sum);
    for(int i=0;i<=n;i++) {
        sum+=f[p[i]]*i;
    }
    // printf("%d\n",sum);
    ll pre=0;
    printf("%lld\n",sum);
    
}
int main() {
    int T=rd();
    for(int i=1;i<=T;i++) {
        solve();
    }
}