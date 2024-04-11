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

const int N=100010,INF=0x3f3f3f3f;
int n,m,x,bl[N];
struct Hill{int h,id;}h[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
void solve(){
    n=rdi(),m=rdi(),x=rdi();
    for(int i=1;i<=n;i++) h[i].h=rdi(),h[i].id=i;
    sort(h+1,h+n+1,[&](const Hill &a,const Hill &b){return a.h>b.h;});
    while(!q.empty()) q.pop();
    for(int i=1;i<=m;i++) q.push(mp(h[i].h,i)),bl[h[i].id]=i;
    int minx=INF,maxn=0;
    for(int i=m+1;i<=n;i++){
        auto tmp=q.top();q.pop();
        bl[h[i].id]=tmp.se;q.push(mp(tmp.fi+h[i].h,tmp.se));
    }
    for(int i=1;i<=m;i++){
        auto tmp=q.top();q.pop();
        minx=min(minx,tmp.fi),maxn=max(maxn,tmp.fi);
    }
    if(maxn-minx>x) puts("NO");
    else{
        puts("YES");
        for(int i=1;i<=n;i++) printf("%d ",bl[i]);
        puts("");
    }
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}