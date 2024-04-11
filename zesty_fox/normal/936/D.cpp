#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

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
#define mp make_pair
#define pb push_back

const int N=2e6+10;

int n,m1,m2,t,x1[N],x2[N];

int b[N][2],sum[N][2],vis[N][2],tot;
vi lsh;
void discrete(){
    for(int i=1;i<=m1;i++) lsh.pb(x1[i]+1),lsh.pb(x1[i]);
    for(int i=1;i<=m2;i++) lsh.pb(x2[i]+1),lsh.pb(x2[i]);
    lsh.pb(n+1),lsh.pb(0);sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
    auto getrk = [&](int x) {return lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin();};
    for(int i=1;i<=m1;i++) vis[getrk(x1[i])][0]=1;
    for(int i=1;i<=m2;i++) vis[getrk(x2[i])][1]=1;
    tot=lsh.size()-1;
}

int f[N][2];
pii fr[N][2];

void upd(pii to,pii from,int val){
    if(val<0) return;
    int x=to.fi,y=to.se;
    if(val>f[x][y]) f[x][y]=val,fr[x][y]=from;
}

vi res1;
vector<pii> res2;

int main(){
    n=rdi(),m1=rdi(),m2=rdi(),t=rdi();
    for(int i=1;i<=m1;i++) x1[i]=rdi();
    for(int i=1;i<=m2;i++) x2[i]=rdi();
    discrete();
    
    memset(f,0xc0,sizeof(f));
    f[0][0]=f[0][1]=0;
    for(int i=1;i<=tot;i++){
        for(int j:{0,1}){
            int nxt=f[i-1][j]+lsh[i]-lsh[i-1]-1;
            if(vis[i][j]){
                if(nxt>=t) upd({i,j},{i-1,j},nxt-t+1);
            }
            else upd({i,j},{i-1,j},nxt+1);
        }
        if(i<tot){
            for(int j:{0,1}){
                if(vis[i][j]) continue;
                int nxt=min(f[i][j^1],t);
                if(f[i][j]<nxt) upd({i,j},{i,j^1},nxt);
            }
        }
    }

    if(f[tot][0]<0&&f[tot][1]<0) return puts("No"),0;
    pii now=f[tot][0]>=0?(pii){tot,0}:(pii){tot,1};
    while(now.fi){
        if(fr[now.fi][now.se].se!=now.se) res1.pb(lsh[now.fi]),now=fr[now.fi][now.se];
        else{
            int pre=now.fi,s=0;
            while(pre&&fr[pre][now.se].se==now.se) s+=vis[pre--][now.se];
            int pos=lsh[pre],val=f[pre][now.se];
            if(val<t) pos+=t-val,val=t;
            while(s--) res2.pb({pos,now.se}),val-=t,pos+=t;
            now={pre,now.se};
        }
    }
    if(now.se) res1.pb(0);
    sort(res1.begin(),res1.end());
    sort(res2.begin(),res2.end());
    cout<<"Yes"<<'\n';
    cout<<res1.size()<<'\n';
    for(auto x:res1) cout<<x<<' ';
    cout<<'\n'<<res2.size()<<'\n';
    for(auto x:res2) cout<<x.fi<<' '<<x.se+1<<'\n';
    cout<<'\n';
    return 0;
}