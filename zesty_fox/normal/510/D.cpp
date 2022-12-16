#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
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
#define mp make_pair
#define pb push_back

const int N=310;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,l[N],c[N];

__gnu_pbds::gp_hash_table<int,ll> dis;
__gnu_pbds::gp_hash_table<int,__gnu_pbds::null_type> vis;
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void dij(int st){
    dis.clear(),vis.clear();
    while(!q.empty()) q.pop();
    
    dis[l[st]]=c[st];
    q.push(mp(dis[l[st]],l[st]));
    while(!q.empty()){
        int x=q.top().se;q.pop();
        if(vis.find(x)!=vis.end()) continue;
        vis.insert(x);
        for(int i=1;i<=n;i++){
            int y=__gcd(x,l[i]);
            if(dis.find(y)==dis.end()||dis[y]>dis[x]+c[i]){
                dis[y]=dis[x]+c[i];
                q.push(mp(dis[y],y));
            }
        }
    }
}

ll ans=INF;
int main(){
    n=rdi();
    for(int i=1;i<=n;i++) l[i]=rdi();
    for(int i=1;i<=n;i++) c[i]=rdi();
    for(int i=1;i<=n;i++){
        dij(i);
        if(dis.find(1)==dis.end()) continue;
        else ans=min(ans,dis[1]);
    }
    printf("%lld\n",ans==INF?-1:ans);
    return 0;
}