////#include <stdio.h>
////#include <iostream>
////#include <math.h>
////#include <numeric>
////#include <vector>
////#include <map>
////#include <functional>
////#include <stdio.h>
////#include <array>
////#include <algorithm>
////#include <string>
////#include <assert.h>
////#include <stdio.h>
////#include <queue>
////#include<iomanip>
////using namespace std;
////
////
////using namespace std;
//////
//////#define N (1<<17) 
//////// update(l,r,v) := [l,r]vl. k,a,b
//////
//////struct NODE{
//////	int sum;//XVl. lQ]S.
//////	int lazy;	//xl
//////	NODE(){
//////		sum = lazy = 0;
//////	}
//////};
//////
//////NODE seg[2 * N];
//////
//////// inline!(x)
//////inline void lazy_evaluate_node(int k, int a, int b){
//////	seg[k].sum +=seg[k].lazy;
//////	if (k < N){ // 2*k(q) < 2*N (_) C[W. [m[h`.
//////		seg[2 * k].lazy += seg[k].lazy;	//N`.
//////		seg[2 * k + 1].lazy += seg[k].lazy;
//////	}
//////	seg[k].lazy = 0;
//////}
//////
//////inline void update_node(int k){ // kq]O. [Oouifv.
//////	seg[k].sum = min(seg[2 * k].sum , seg[2 * k + 1].sum);
//////}
//////
//////// update(l,r,v) := [l,r]XV. 1-indexed.
//////void update(int l, int r, int v, int k = 1, int a = 1, int b = N){
//////	lazy_evaluate_node(k, a, b); 	// Hm[hs`_.
//////
//////	if (b < l || r < a) //[a,b][l,r]
//////		return;
//////	if (l <= a && b <= r){ // [l,r][a,b]S
//////		seg[k].lazy += v;
//////		lazy_evaluate_node(k, a, b); //x]s.
//////		return;
//////	}
//////
//////	int m = (a + b) / 2;
//////	update(l, r, v, 2 * k, a, m);
//////	update(l, r, v, 2 * k + 1, m + 1, b);
//////	update_node(k);
//////}
//////
//////// get(l,r) := [l,r]NG. 1-indexed.
//////int get(int l, int r, int k = 1, int a = 1, int b = N){
//////	lazy_evaluate_node(k, a, b); // Hm[hs`_.
//////
//////	if (b < l || r < a) //[a,b][l,r]
//////		return 0;
//////
//////	if (l <= a && b <= r){ // [l,r][a,b]S
//////		return seg[k].sum;
//////	}
//////
//////	int m = (a + b) / 2;
//////	int vl = get(l, r, 2 * k, a, m);
//////	int vr = get(l, r, 2 * k + 1, m + 1, b);
//////	update_node(k);
//////	return min(vl , vr);
//////}
////
////
////int main() {
////	//int n;
////	//cin >> n;
////	//vector<int> aa(n);
////	//vector<pair<int,int>>aaa;
////	//for (int i = 0; i < n; ++i){
////	//	int a, b;
////	//	cin >> a >> b;
////	//	aaa.push_back(make_pair(a, b)); 
////	//	aa[a]++;
////	//	aa[b]--;
////	//}
////	//vector<int> ans;
////	//ans.push_back(aa[0]);
////	//int amin=99999999;
////	//for(int i=0;i<n;++i){
////	//	ans.push_back(ans[i] + aa[i]);
////	//}
////
////	//RMQ r;
////	//r.init(65536);
////	//for (int i = 0; i < 65536;++i){
////	//	r.update(i, ans[i]);
////	//}
////
////	//cout << r.query(0, 7) << endl; //1
////	//cout << r.query(3, 6) << endl; //2
////	//cout << r.query(1, 5) << endl; //1
////	//cout << r.query(5, 7) << endl; //4
////	//return 0;
////
////	vector<long long int>times;
////	for (int i = 0; i < 7; ++i){
////		long long int c;
////		cin >> c;
////		times.push_back(c);
////	}
////	if (times[0] == 0)cout << "YES" << endl;
////	else{
////		times[0]--;
////	}
////
////	{
////		vector<long long int> atimes(times);
////		while (1){
////			auto zero_it = find(atimes.begin(), atimes.end(), 0);
////			if (zero_it != atimes.end()){//5 3 2 0 4 4 2 
////				const int num = zero_it - atimes.begin();
////				int from = num;
////				while (1){
////					from = (from + 1) % 7;
////					if (from == num)break;
////					int to = (from + 1) % 7;
////					if (atimes[from] != 0 && atimes[to] == 0){
////						break;
////					}
////					if (atimes[from] > atimes[to]){
////						break;
////					}
////					long long int amin = min(atimes[from], atimes[to]);
////					atimes[from] -= amin;
////					atimes[to] -= amin;
////					if (atimes[from] == 0 && atimes[to] == 0){
////						break;
////					}
////				}
////				if (all_of(atimes.begin(), atimes.end(), [](const int aaa){return aaa == 0; })){
////					cout << "YES" << endl;
////					return 0;
////				}
////				else{
////					break;
////				}
////			}
////			else{
////				long long int aamin = atimes[0];
////				for (int i = 0; i < 7; ++i){
////					aamin = min(aamin, atimes[i]);
////				}
////				for (int i = 0; i < 7; ++i){
////					atimes[i] -= aamin;
////				}
////			}
////		}
////	}
////	{
////		vector<long long int> btimes(times);
////		for (int i = 0; i < 7; ++i){//times[i]
////			btimes = times;
////			int from = (i + 6) % 7;
////			while (1){
////				from = (from + 1) % 7;
////				if (from == (i + 6) % 7)break;
////				int to = (from + 1) % 7;
////				if (btimes[from] != 0 && btimes[to] == 0){
////					break;
////				}
////				if (btimes[from] > btimes[to]){
////					break;
////				}
////				long long int amin = min(btimes[from], btimes[to]);
////				btimes[from] -= amin;
////				btimes[to] -= amin;
////				if (btimes[from] == 0 && btimes[to] == 0){
////					break;
////				}
////			}
////			if (all_of(btimes.begin(), btimes.end(), [=](int a){return a == 0; })){
////				cout << "YES" << endl;
////				return 0;
////			}
////			else{
////				continue;
////			}
////		}
////	}
////	cout << "NO" << endl;
////	return 0;
////}
//////3 4 4 4 4 4 4
//
//#include<stdio.h>
//#include <iostream>
//#include <math.h>
//#include <numeric>
//#include <vector>
//#include <map>
//#include <functional>
//#include <stdio.h>
//#include <algorithm>
//#include <string>
//#include <assert.h>
//#include <stdio.h>
//#include <queue>
//#include<iomanip>
//#include<bitset>
//#include<stack>
//using namespace std;
//#include <array>
//
////7:10
////
////#define REP(i,n) for(int i=0;i<(int)n;++i)
////#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
////#define ALL(c) (c).begin(), (c).end()
////
////typedef int Weight;
////struct Edge {
////	int src, dst;
////	Weight weight;
////	Edge(int src, int dst, Weight weight) :
////		src(src), dst(dst), weight(weight) { }
////};
////bool operator < (const Edge &e, const Edge &f) {
////	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
////	e.src != f.src ? e.src < f.src : e.dst < f.dst;
////}
////typedef vector<Edge> Edges;
////typedef vector<Edges> Graph;
////
////typedef vector<Weight> Array;
////typedef vector<Array> Matrix;
////
////#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
////Weight maximumFlow(const Graph &g, int s, int t) {
////	int n = g.size();
////	Matrix flow(n, Array(n)), capacity(n, Array(n));
////	REP(u, n) for (auto e = g[u].begin(); e != g[u].end();++e)capacity[e->src][e->dst] += e->weight;
////
////	Weight total = 0;
////	while (1) {
////		queue<int> Q; Q.push(s);
////		vector<int> prev(n, -1); prev[s] = s;
////		while (!Q.empty() && prev[t] < 0) {
////			int u = Q.front(); Q.pop();
////			for (auto e = g[u].begin(); e != g[u].end(); ++e) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
////				prev[e->dst] = u;
////				Q.push(e->dst);
////			}
////		}
////		if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
////		Weight inc = 999999999;
////		for (int j = t; prev[j] != j; j = prev[j])
////			inc = min(inc, RESIDUE(prev[j], j));
////		for (int j = t; prev[j] != j; j = prev[j])
////			flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
////		total += inc;
////	}
////	return total;
////}
//#define REP(i,n) for(int i=0;i<(int)(n);i++)
//#define ALL(x) (x).begin(),(x).end()
//
//
//const int mod = 1000000007;
//
//struct Mod {
//	long long int num;
//	Mod() : num(0) { ; }
//	Mod(long long int n) : num((n % mod + mod) % mod) { ; }
//	operator long long int() { return num; }
//};
//
//Mod operator+(Mod a, Mod b) { return Mod((a.num + b.num) % mod); }
//Mod operator-(Mod a, Mod b) { return Mod((mod + a.num - b.num) % mod); }
//Mod operator*(Mod a, Mod b) { return Mod(((long long)a.num * b.num) % mod); }
//Mod operator+=(Mod &a, Mod b) { return a = a + b; }
//Mod operator-=(Mod &a, Mod b) { return a = a - b; }
//Mod operator*=(Mod &a, Mod b) { return a = a * b; }
//Mod operator^(Mod a, int n) {
//	if (n == 0) return Mod(1);
//	Mod res = (a * a) ^ (n / 2);
//	if (n % 2) res = res * a;
//	return res;
//}
//Mod inv(Mod a) { return a ^ (mod - 2); }
//Mod operator/(Mod a, Mod b) { return a * inv(b); }
//
//#define MAX_N 1024000
//
//Mod fact[MAX_N], factinv[MAX_N];
//void init() {
//	fact[0] = Mod(1); factinv[0] = 1;
//	REP(i, MAX_N - 1) {
//		fact[i + 1] = fact[i] * Mod(i + 1);
//		factinv[i + 1] = factinv[i] / Mod(i + 1);
//	}
//}
//Mod comb(int a, int b) {
//	return fact[a] * factinv[b] * factinv[a - b];
//}
//
//long long int memo[20];//n
//
//long long int powint(long long int a, int b){
//	if (b == 0)return 1;
//	if (b == 1)return a;
//	else{
//		long long int ans = 1;
//		long long int c = powint(a, b / 2);
//		ans *= c*c;
//		ans *= (b % 2) ? a : 1;
//		return ans;
//	}
//
//}
//
//
//int backnum[100000][20];
//
//struct Node{
//	Node(int aid):children(),ancs(){
//		id=(aid);
//		for (int i = 0; i < 20; ++i){
//			ancs[i] = -1;
//		}
//	}
//	int id;
//	vector<int>children;
//	array<int, 20>ancs;
//};
//
//
//
//
//
//using namespace std;
//
//typedef pair<int, int> pii;
//
//#define MAX_H 1510
//#define MAX_W 1510
//
//int H, W;
//int mat[MAX_H][MAX_W];
//
//int maximum_rectangle(){
//	int res = 0, h[MAX_W] = { 0 };
//	for (int i = 0; i < H; i++){
//		for (int j = 0; j < W; j++){
//			h[j] = (mat[i][j] == 0 ? h[j] + 1 : 0);
//		}
//		stack<pii> st;
//		st.push(pii(0, W));
//		for (int j = 0; j <= W; j++){
//			int k = j;
//			while (h[j] < st.top().first){
//				k = st.top().second;
//				res = max(res, st.top().first*(j - k));
//				st.pop();
//			}
//			if (st.top().first < h[j]){
//				st.push(pii(h[j], k));
//			}
//		}
//	}
//	return res;
//}
//
//
//#define REP(i,n) for(int i=0;i<(int)(n);i++)
//#define ALL(x) (x).begin(),(x).end()
//using namespace std;
//
//
//struct Edge{ int src, dest; };
//
//typedef vector<Edge> Edges;
//typedef vector<Edges> Graph;
//
//void add_edge(Graph &g, int src, int dest) {
//	g[src].push_back(Edge{ src, dest });
//	g[dest].push_back(Edge{ dest, src });
//}
//
//Mod zdd(const Graph &g, int s, int t) {
//	int N = g.size();
//	vector<vector<int>> tr(N);
//	vector<int> pos(N, -1);
//	queue<int> que;
//	pos[s] = 0; que.push(s);
//	int cnt = 0;
//	while (!que.empty()) {
//		int v = que.front(); que.pop();
//		for (Edge e : g[v]) {
//			int w = e.dest;
//			if (pos[w] != -1) continue;
//			que.push(w);
//			++cnt; pos[w] = cnt;
//		}
//	}
//	REP(i, N) assert(pos[i] != -1); // assert
//	REP(i, N) for (Edge e : g[i])
//		if (pos[e.src] < pos[e.dest])
//			tr[pos[e.src]].push_back(pos[e.dest]);
//	Mod res = 0;
//	map<pair<int, vector<int>>, Mod> memo;
//	for (int i : tr[0]) {
//		vector<int> init(N, -1);
//		init[0] = i; init[i] = 0;
//		memo[make_pair(1, init)] = Mod(1);
//	}
//	for (auto it = memo.begin(); (it->first).first < N; ++it) {
//		int v = (it->first).first;
//		vector<int> mate = (it->first).second;
//		Mod cnt = it->second;
//		if (mate[v] == -2) {
//			memo[make_pair(v + 1, mate)] += cnt;
//		}
//		else if (mate[v] == -1) {
//			mate[v] = -2;
//			memo[make_pair(v + 1, mate)] += cnt;
//			for (int a : tr[v]) {
//				for (int b : tr[v]) {
//					if (a == b) break;
//					if (mate[a] == -2 || mate[b] == -2 || mate[a] == b) continue;
//					vector<int> nx = mate;
//					nx[v] = -2;
//					if (nx[a] == -1) {
//						if (nx[b] == -1) { nx[a] = b; nx[b] = a; }
//						else { nx[a] = nx[b]; nx[nx[b]] = a; nx[b] = -2; }
//					}
//					else {
//						if (nx[b] == -1) { nx[b] = nx[a]; nx[nx[a]] = b; nx[a] = -2; }
//						else { swap(nx[nx[a]], nx[nx[b]]); nx[a] = -2; nx[b] = -2; }
//					}
//					memo[make_pair(v + 1, nx)] += cnt;
//				}
//			}
//		}
//		else {
//			if (v == pos[t]) res += cnt;
//			for (int a : tr[v]) {
//				if (mate[a] == -2) continue;
//				if (mate[a] == -1) {
//					vector<int> nx = mate;
//					nx[nx[v]] = a; nx[a] = nx[v]; nx[v] = -2;
//					memo[make_pair(v + 1, nx)] += cnt;
//				}
//				else {
//					if (mate[v] == a) continue;
//					vector<int> nx = mate;
//					nx[nx[a]] = nx[v]; nx[nx[v]] = nx[a];
//					nx[a] = -2; nx[v] = -2;
//					memo[make_pair(v + 1, nx)] += cnt;
//				}
//			}
//		}
//	}
//	return res;
//}
//
//
//int main() {
//for (int n = 1; n <= 3; ++n) {
//int N = n + 1;
//Graph g(N * N);
//REP(i,N) REP(j,N-1) add_edge(g, i*N+j, i*N+j+1);
//REP(i,N-1) REP(j,N) add_edge(g, i*N+j, (i+1)*N+j);
//Mod res = zdd(g, 0, N*N-1);
//cout << n << " x " << n << " : " << res << endl;
//}
//return 0;
//}
//
//#include<stdio.h>
//#include <iostream>
//#include <math.h>
//#include <numeric>
//#include <vector>
//#include <map>
//#include <functional>
//#include <stdio.h>
//#include <algorithm>
//#include <string>
//#include <assert.h>
//#include <stdio.h>
//#include <queue>
//#include<iomanip>
//#include<bitset>
//#include<stack>
//using namespace std;
//#include <array>
//
//int main(){
//	int n, m, q;
//	cin >> n >> m >> q;
//	vector<vector<int>>nums(n, vector<int>(m));
//
//	vector<vector<pair<int, int>>>maps(n,vector<pair<int,int>>(m));
//	for (int i = 0; i < n; ++i){
//		string st;
//		cin >> st;
//		for (int j = 0; j < st.size(); ++j){
//			nums[i][j] = st[j] - '0';
//		}
//	}
//	vector<pair<int, int>>tos(10);
//	for (int i = 0; i < 10; ++i){
//		int dy, dx;
//		cin >> dy >> dx;
//		tos.push_back(make_pair(dy, dx));
//	}
//	for (int i = 0; i < n; ++i){
//		for (int j = 0; j < m; ++j){
//			int nx = j + tos[nums[i][j]].second;
//			int ny = i + tos[nums[i][j]].first;
//			if (0 <= nx&&nx < n && 0 <= ny&&ny < m){
//				maps[i][j] = make_pair(ny, nx);
//			}
//			else{
//				maps[i][j] = make_pair(i, j);
//			}
//		}
//	}
//	for (int i = 0; i < q; ++i){
//		string st;
//		cin >> st;
//	}
//	return 0;
//}

#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
using namespace std;
#include <array>

double dp[101][101010];

int main(){
	int a, b;
	cin >> a >> b;
	
	vector<int> ms;
	for (int i = 0; i < a; ++i){
		int s;
		cin >> s;
		ms.push_back(s);
	}
	if (b == 1){
		cout << 1 << endl;
		return 0;
	}
	int msum = accumulate(ms.begin(), ms.end(), 0);

	vector<vector<double>>dp(101, vector<double>(110000));
	dp[0][0] = 1;
	vector<double> sas(110000);
	for (int solved = 0; solved < a; ++solved){
		int ams = ms[solved];
		vector<double> sas(110000);
		for (int ps = 0; ps < 105000; ++ps){
			sas[ps + 1] += (1.0 / (b - 1))*dp[solved][ps];
			sas[ps + ams] += (-1.0 / (b - 1))*dp[solved][ps];
			sas[ps + ams + 1] += (1.0 / (b - 1))*dp[solved][ps];
			sas[ps + b + 1] += (-1.0 / (b - 1))*dp[solved][ps];
		}
		dp[solved+1][0] = 0;
		for (int ps = 0; ps < 105000; ++ps){
			dp[solved + 1][ps + 1] = dp[solved + 1][ps] + sas[ps + 1];
		}
	}
	double ans = 0;
	for (int s = msum-1; s >0; --s){
		ans += dp[a][s];
	}
	ans = 1 + ans*(b - 1);
	
	cout <<setprecision(29)<< ans << endl;
	return 0;
}