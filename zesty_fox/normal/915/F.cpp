#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1000010;
struct Edge{int to,nxt;}e[N<<1];
int head[N],tot,n;
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

int f[N],siz[N];
int find(int x){
    return x==f[x]?f[x]:f[x]=find(f[x]);
}

void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    f[y]=x,siz[x]+=siz[y];
}

int a[N],p[N],ins[N];
ll cntmx[N],cntmn[N],ans;
int main(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y);addedge(y,x);
    }

    for(int i=1;i<=n;i++) p[i]=i,f[i]=i,siz[i]=1;
    sort(p+1,p+n+1,[&](int x,int y){return a[x]<a[y];});
    for(int id=1;id<=n;id++){
        int x=p[id];ins[x]=1;
        int sumsiz=1;ll sum1=0;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(ins[y]){
                int siz1=siz[find(y)];
                sumsiz+=siz1,sum1+=(ll)siz1*(siz1+1)/2;
                merge(x,y);
            }
        }
        cntmx[x]=(ll)sumsiz*(sumsiz+1)/2-sum1;
    }

    reverse(p+1,p+n+1);
    for(int i=1;i<=n;i++) ins[i]=0,f[i]=i,siz[i]=1;
    for(int id=1;id<=n;id++){
        int x=p[id];ins[x]=1;
        int sumsiz=1;ll sum1=0;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(ins[y]){
                int siz1=siz[find(y)];
                sumsiz+=siz1,sum1+=(ll)siz1*(siz1+1)/2;
                merge(x,y);
            }
        }
        cntmn[x]=(ll)sumsiz*(sumsiz+1)/2-sum1;
    }

    for(int i=1;i<=n;i++) ans+=(cntmx[i]-cntmn[i])*a[i];
    cout<<ans<<endl;
    return 0;
}