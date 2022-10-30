#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;

const int N=200005;

int n,ed;
bool vis[N];
ll lst,ans,l[N],r[N],t[N]; 
pair<ll,int> e[N<<1];
priority_queue<pair<ll,int> > Q;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld%lld%lld",l+i,r+i,t+i);
		e[++ed]={l[i],i<<1};
		e[++ed]={r[i]-t[i],i<<1|1};
		
	}
	sort(e+1,e+ed+1);
	for (int i=1,j=1;i<=ed;j=i) {
		ll now=e[i].fi;
		if (!Q.empty() && lst<=now) {
			lst-=Q.top().fi;
			ans++;
		}
		for (;e[j].fi==e[i].fi && !(e[j].se&1) && j<=ed;j++) Q.push({-t[e[j].se>>1],e[j].se>>1});
		if (!Q.empty()) {
			if (lst<=now) lst=now-Q.top().fi,ans++;
			if (now-Q.top().fi<lst) lst=now-Q.top().fi;
		}
		for (;e[j].fi==e[i].fi && (e[j].se&1) && j<=ed;j++) vis[e[j].se>>1]=1;
		i=j;
		ll nxt=e[i].fi;
		if (!nxt) break;
		while (!Q.empty() && vis[Q.top().se]) Q.pop();
		if (!Q.empty() && lst<=nxt) {
			ll tmp=(lst-nxt)/Q.top().fi;
			ans+=tmp;
			lst-=tmp*Q.top().fi;
		}
	}
	printf("%lld\n",ans);
}