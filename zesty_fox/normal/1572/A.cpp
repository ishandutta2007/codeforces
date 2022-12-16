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

const int N=200010,INF=0x3f3f3f3f;
int n,dep[N],in[N];
vi e[N];
queue<int> q;
void solve(){
	n=rdi();
	for(int i=1;i<=n;i++) e[i].clear(),dep[i]=0,in[i]=0;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++){
		int k=rdi();in[i]=k;
		for(int j=1;j<=k;j++) e[rdi()].pb(i);
		if(!k) q.push(i),dep[i]=1;
	}
	int ans=0,cnt=0;
	while(!q.empty	()){
		int x=q.front();q.pop();
		ans=max(ans,dep[x]),cnt++;
		for(auto y:e[x]){
			in[y]--;
			if(y>x) dep[y]=max(dep[x],dep[y]);
			else dep[y]=max(dep[y],dep[x]+1);
			if(!in[y]) q.push(y);
		}
	}
	if(cnt<n) puts("-1");
	else printf("%d\n",ans);
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}