#include<bits/stdc++.h>
using namespace std;
 
int weight[2510];
int u[2510], v[2510];
int W[6][6];
int d[6], k;
int stp = 0;
vector<pair<int,int>> must;
#define eb emplace_back
typedef long long ll;
 
struct DSU {
	int p[51], sz[51];
	DSU(int n = 0) {
		for(int i=1;i<=n;i++)
			sz[p[i] = i] = 1;
	}
	int F(int x) {
		return x == p[x] ? x : p[x] = F(p[x]);	
	}
	bool U(int x, int y) {
		x = F(x), y = F(y);
		if(x == y)	return false;
		if(sz[x] > sz[y])	swap(x, y);
		p[x] = y;
		return true;
	}
	bool I(int x, int y) {
		x = F(x), y = F(y);
		if(x == y)	return false;
		return true;
	}
};
 
struct PM {
	int cd[6];
	int bin[3000];
	void init() {
		for(int i=0;i<stp;i++) {
			if(u[i] <= k)
				bin[i] = u[i];
			if(v[i] <= k)
				bin[i] = v[i];
		}
	}
	void prepare(vector<int> cur_indep) {
		for(int i=1;i<=k;i++)
			cd[i] = d[i];
		for(auto [x, y] : must)
			cd[x] --, cd[y] --;
		for(int x:cur_indep)
			cd[bin[x]]--;
	}
	bool indep(int in) {
		return bin[in] == 0 || cd[bin[in]] > 0;
	}
}M1;

struct GM {
	int id[3000];
	DSU D;
	void prepare(vector<int> cur_indep, int ban) {
		for(int i=0;i<cur_indep.size();i++)
			id[cur_indep[i]] = i;
		D = DSU(50);
		for(auto [x, y] : must)
			D.U(x, y);
		for(int i=0;i<cur_indep.size();i++) {
			if(i == ban)	continue;
			int x = u[cur_indep[i]], y = v[cur_indep[i]];
			D.U(x, y);
		}
	}
	bool indep(int in) {
		return D.I(u[in], v[in]);
	}
}M2;
vector<int> sorted;
struct MIN_M_I {
	int n;
	const int base = 500;
	const int inf = 1e9;
	vector<int> cur_indep, in_indep;
	int comp[3000];
	MIN_M_I(int n):n(n), in_indep(n){}
	bool augment() {
		int N = 0;
		vector<int> rev;
		for(int i=0;i<n;i++)
			if(in_indep[i])
				comp[i] = N++, rev.eb(i);
		comp[n] = N++, rev.eb(n);
		comp[n + 1] = N++, rev.eb(n + 1);
		vector<long long> from(n), to(n);
		{
			M1.prepare(cur_indep), M2.prepare(cur_indep, -1);
			for(int i=0;i<n;i++)	if(!in_indep[i]) {
				if(M1.indep(i)) to[i] |= 1LL << comp[n];
				if(M2.indep(i))	from[i] |= 1LL << comp[n + 1];
			}
		}
		for(int i=0;i<n;i++)
			if(in_indep[i]) {
				M2.prepare(cur_indep, comp[i]);
				M1.cd[M1.bin[i]]++;
				for(int j=0;j<n;j++)
					if(!in_indep[j]) {
						if(M1.indep(j))	to[j] |= 1LL << comp[i];
						if(M2.indep(j))	from[j] |= 1LL << comp[i];
					}
				M1.cd[M1.bin[i]]--;
			}
		for(int i=0;i<n;i++)	for(int j=0;j<n;j++)	if(in_indep[i] && !in_indep[j]) {
		}
		vector<vector<int>> td(N, vector<int>(N, inf));
		vector<vector<int>> jmp(N, vector<int>(N, inf));
		vector<long long> todo(N, (1LL << N) - 1);
		for(int j:sorted) {
			for(int i=0;i<N;i++) {
				if((to[j] >> i) & 1) {
					long long mask = todo[i] & from[j];
					while(mask != 0) {
						int bit = __builtin_ctzll(mask);
						todo[i] ^= 1LL << bit;
						mask ^= 1LL << bit;
						td[i][bit] = (weight[j] - weight[rev[bit]]) * base + 2;
						jmp[i][bit] = j;
					}
				}
			}
		}
		vector<int> dist(N, inf), p(N, -1);vector<tuple<int,int,int>> e;
		dist[comp[n]] = 0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(i != j && td[i][j] != inf)
					e.eb(i, j, td[i][j]);
		for(int t=0;t<=N;t++) {
			bool up = false;
			for(auto &[u, v, w] : e)
				if(dist[u] != inf && dist[v] > dist[u] + w)	p[v] = u, dist[v] = dist[u] + w, up = true;
			if(!up)	break;
		}
		if(dist[N - 1] == inf)	return false;
		int x = N - 1;
		while(x != N - 2) {
			if(x != N - 1)
				in_indep[rev[x]] ^= 1;
			in_indep[jmp[p[x]][x]] ^= 1;
			x = p[x];
		}
		cur_indep.clear();
		for(int i=0;i<n;i++)	if(in_indep[i])	cur_indep.eb(i);
		return true;
	}
	vector<int> solve(){
		while(augment());
		return cur_indep;
	}
};
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n >> k;
	for(int i=1;i<=k;i++)
		cin >> d[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) {
			if(i <= k && j <= k) {
				cin >> W[i][j];
			}
			else {
				cin >> weight[stp];
				u[stp] = i, v[stp] = j;
				stp++;
			}
		}
	sorted = vector<int>(stp);
	iota(sorted.begin(), sorted.end(), 0);
	sort(sorted.begin(), sorted.end(), [&](const int& a, const int& b) {
		return weight[a] < weight[b];
	});
	vector<pair<int,int>> todo;
	int ans = 1e9;
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
			todo.eb(i, j);
	int N = todo.size();
	M1.init();
	for(int i=0;i<(1<<N);i++) {
		DSU D(k);
		must.clear();
		vector<int> cd(k + 1);
		bool ok = true;
		int cost = 0;
		for(int j=0;j<N;j++)
			if((i >> j) & 1) {
				if(!D.U(todo[j].first, todo[j].second)) {
					ok = false;
					break;
				}
				cd[todo[j].first]++, cd[todo[j].second]++;
				cost += W[todo[j].first][todo[j].second];
				must.eb(todo[j]);
			}
		for(int j=1;j<=k;j++)
			if(cd[j] > d[j])
				ok = false;
		if(ok) {
			auto MI = MIN_M_I(stp);
			auto res = MI.solve();
			if(res.size() + must.size() == n - 1) {
				for(int x:res)
					cost += weight[x];
				ans = min(ans, cost);
			}
		}
	}
	cout << ans << endl;
}