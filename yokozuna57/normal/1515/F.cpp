#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second
template <int N = 100010>
struct UF{
	int par[N];
	UF(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
		}
	}
	void init(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	void unit(int x,int y){
		if(same(x,y))return;
		x = find(x);
		y = find(y);
		par[y] = x;
	}
};
UF<300010> uf;

ll n,m,x;
ll a[300010];
list<pair<int,int>> G[300010];

int main(){
	scanf("%lld%lld%lld",&n,&m,&x);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v); u--; v--;
		G[u].push_back(mp(v,i));
		G[v].push_back(mp(u,i));
	}
	ll sum=0;
	for(int i=0;i<n;i++)sum+=a[i];
	if(sum<x*(n-1)){
		puts("NO");
		return 0;
	}
	puts("YES");
	vector<int> ret;
	queue<int> que;
	for(int i=0;i<n;i++)que.push(i);
	while(!que.empty()){
		int q=que.front(); que.pop();
		if(uf.find(q)!=q||a[q]<x)continue;
		while(!G[q].empty()){
			auto p=G[q].front(); G[q].pop_front();
			if(!uf.same(q,p.fr)){
				ret.push_back(p.sc);
				G[q].splice(G[q].end(),std::move(G[uf.find(p.fr)]));
				a[q]=a[q]+a[uf.find(p.fr)]-x;
				uf.unit(q,p.fr);
				que.push(q);
				break;
			}
		}
	}
	for(int i=0;i<n;i++)if(uf.find(i)==i)que.push(i);
	while(!que.empty()){
		int q=que.front(); que.pop();
		if(uf.find(q)!=q)continue;
		while(!G[q].empty()){
			auto p=G[q].front(); G[q].pop_front();
			if(!uf.same(q,p.fr)){
				ret.push_back(p.sc);
				G[q].splice(G[q].end(),std::move(G[uf.find(p.fr)]));
				a[q]=a[q]+a[uf.find(p.fr)]-x;
				uf.unit(q,p.fr);
				que.push(q);
				break;
			}
		}
	}
	for(int i=0;i<ret.size();i++){
		printf("%d\n",ret[i]);
	}
}