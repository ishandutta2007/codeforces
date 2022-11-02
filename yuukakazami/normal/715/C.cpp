#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)

const int MAX_N = 100000+10;
typedef long long ll;
typedef pair<int,int> PII;
int n,M;

int INV10;

struct Edge{
	int t,c;
};
vector<Edge> edge[MAX_N];

bool del[MAX_N];
int seq[MAX_N], pt, opt[MAX_N];
int size[MAX_N];

void dfs(int u, int par) {
	size[u] = 1, seq[pt++] = u;
	opt[u] = 0;
	for(auto e:edge[u])
		if (e.t != par && !del[e.t]) {
			dfs(e.t, u), size[u] += size[e.t];
			opt[u] = max(opt[u], size[e.t]);
		}
}

void dfs2(int u, int par, int val, int mul, vector<int>&ret) {
	ret.push_back(1LL*(M-val)*mul%M);

	for(auto e:edge[u])
		if (e.t != par && !del[e.t]) {
			dfs2(e.t, u, (1LL*val*10+e.c)%M, 1LL*mul*INV10%M, ret);
		}
}

void dfs3(int u, int par, int val, int mul, vector<int>&ret) {
	ret.push_back(val);
	for(auto e:edge[u])
		if (e.t != par && !del[e.t]) {
			dfs3(e.t, u, (val+1LL*e.c*mul)%M, 1LL*mul*10%M, ret);
		}
}

ll ans;

void solve(int rt) {
	pt = 0, dfs(rt, -1);
	int tot = size[rt];
	int minOpt = tot + 1, by = -1;
	for (int i = 0; i < tot; ++i) {
		int u = seq[i];
		opt[u] = max(opt[u], tot - size[u]);
		if (opt[u] < minOpt)
			minOpt = opt[u], by = u;
	}

	rt = by;
	// cout<<rt<<endl;

	int cnt = 0;
	del[rt] = true;

	static vector<int> qrys[MAX_N];
	static vector<int> data[MAX_N];

	qrys[cnt].push_back(0);
	data[cnt].push_back(0);
	++cnt;

	for(auto e:edge[rt])
		if (!del[e.t]) {
			dfs2(e.t, rt, e.c%M, INV10%M, qrys[cnt]);
			dfs3(e.t, rt, e.c%M, 10%M, data[cnt]);
			cnt++;
		}

	map<int,int> total;

	rep(it,0,cnt) for(auto e:data[it]) total[e]++;

	rep(it,0,cnt){
		map<int,int> inside;
		for(auto e:data[it]) inside[e]++;

		for(auto e:qrys[it]) {
			ans += total[e] - inside[e];
		}
	}

	rep(it,0,cnt) qrys[it].clear(),data[it].clear();
	total.clear();

	for(auto e:edge[rt])
		if (!del[e.t]) {
			solve(e.t);
		}
}


int _u;
void bf(int u, int par, int val) {
	if(val==0&&par!=-1) {++ans;} 
	for(auto e:edge[u])
		if (e.t != par) {
			bf(e.t,u,(1LL*val*10+e.c)%M);
		}
}


int main(){
	cin>>n>>M;

	rep(a,0,20) if((1LL*a*M+1)%10==0) {INV10 = (1LL*a*M+1)/10; break;}
	//assert(1LL*INV10*10%M==1);

	rep(it,0,n-1){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back((Edge){v,w});
		edge[v].push_back((Edge){u,w});
	}

	// rep(it,0,n-1){
	//  	int u,v,w;
	//  	v=it+1;
	//  	u=rand()%(it+1);
	//  	w=rand()%9+1;
	//  	//cout<<u<<" "<<v<<" "<<w<<endl;

	//  	edge[u].push_back((Edge){v,w});
	//  	edge[v].push_back((Edge){u,w});
	// }

	solve(0);
	cout<<ans<<endl;
	//ans=0;
	//rep(u,0,n) {_u=u;bf(u,-1,0);}
	//cout<<ans<<endl;
	return 0;
}