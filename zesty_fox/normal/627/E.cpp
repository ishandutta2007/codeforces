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

const int N=3010;

int r,c,n,k;
ll ans;
struct Point{int x,y,id;}p[N];

int pr[N],nx[N],nxk[N];
ll val[N];
ll solve(int up){
    static Point a[N];int cnt=0;
    for(int i=1;i<=n;i++) if(p[i].x>=up) a[++cnt]=p[i],a[cnt].id=cnt;
    sort(a+1,a+cnt+1,[](auto a,auto b){return a.y!=b.y?a.y<b.y:a.x<b.x;});
    for(int i=1;i<=cnt;i++){
        pr[a[i].id]=a[i-1].id,nx[a[i].id]=i+1<=cnt?a[i+1].id:0;
        nxk[a[i].id]=i+k-1<=cnt?a[i+k-1].id:0;
    }
    sort(a+1,a+cnt+1,[](auto a,auto b){return a.id<b.id;});
    
    auto calc = [&](int id){
        return nxk[id]?(ll)(a[id].y-a[pr[id]].y)*(c-a[nxk[id]].y+1):0;
    };
    
    ll cur=0;
    auto update = [&](int id){
        cur-=val[id];
        val[id]=calc(id);
        cur+=val[id];
    };

    for(int i=1;i<=cnt;i++) cur+=(val[i]=calc(i));

    auto del = [&](int id){
        cur-=val[id];
        if(pr[id]) nx[pr[id]]=nx[id];
        if(nx[id]) pr[nx[id]]=pr[id],update(nx[id]);
        int now=pr[id],cnt=0;
        while(now&&(++cnt)<k){
            nxk[now]=nx[nxk[now]];
            cur-=val[now],val[now]=calc(now),cur+=val[now];
            now=pr[now];
        }
    };

    ll sum=0;
    int pos=cnt;
    for(int dw=r;dw>=up;dw--){
        while(pos>=1&&a[pos].x>dw) del(pos--);
        if(pos<k) break;
        sum+=cur;
    }
    return sum;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    r=rdi(),c=rdi(),n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) p[i].x=rdi(),p[i].y=rdi();
    sort(p+1,p+n+1,[](auto a,auto b){return mp(a.x,a.y)<mp(b.x,b.y);});
    for(int up=1;up<=r;up++) ans+=solve(up);
    cout<<ans<<endl;
    return 0;
}