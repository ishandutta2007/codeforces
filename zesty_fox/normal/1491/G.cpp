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
#define mp make_pair
#define pb push_back

inline int abs(int x){return x>=0?x:-x;}

const int N=200010;
int n,a[N],pos[N];
vector<pii> res;
void operate(int x,int y){
    swap(pos[abs(a[x])],pos[abs(a[y])]);
    swap(a[x],a[y]);
    a[x]=-a[x],a[y]=-a[y];
    res.pb(mp(x,y));
}

vi lp[N];
int siz[N],lpcnt,vis[N];

void operate_two_loops(int id1,int id2){
    operate(lp[id1].back(),lp[id2].back());
    for(int i=0;i<siz[id2]-1;i++) operate(lp[id1].back(),lp[id2][i]);
    for(int i=0;i<siz[id1];i++) operate(lp[id2].back(),lp[id1][i]);
    for(auto tmp:lp[id1]) vis[tmp]=1;
    for(auto tmp:lp[id2]) vis[tmp]=1;
}

void operate_one_loop(int id){
    if(siz[id]==2){
		for(int i=1;i<=n;i++){
			if(vis[i]){
				lp[++lpcnt]={i},siz[lpcnt]=1;
				return operate_two_loops(id,lpcnt);
			}
		}
		return;
	}
	operate(lp[id].back(),lp[id][0]);
	for(int i=1;i<siz[id]-1;i++) operate(lp[id][0],lp[id][i]);
	operate(lp[id][1],lp[id].back());
	operate(lp[id][0],lp[id].back());
	for(auto tmp:lp[id]) vis[tmp]=1;
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),pos[a[i]]=i;
    {
        int vis[N]={0};
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            int now=i;++lpcnt;
            while(!vis[now]) lp[lpcnt].pb(now),vis[now]=1,now=a[now];
            siz[lpcnt]=lp[lpcnt].size();
        }
    }
    
    vi loops;
    for(int i=1;i<=lpcnt;i++){
		if(siz[i]>1) loops.pb(i);
		else vis[lp[i][0]]=1;
	}
    for(int i=loops.size()-1;i>=0;i-=2){
		if(i) operate_two_loops(loops[i],loops[i-1]);
		else operate_one_loop(loops[i]);
	}
    
    printf("%lu\n",res.size());
    for(auto tmp:res) printf("%d %d\n",tmp.fi,tmp.se);
    return 0;
}