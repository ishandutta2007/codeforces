#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ll=long long ;
#define Whats(x) cout<<#x<<" is "<<(x)<<endl



const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const long long  int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}

//mod extend euclid 
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;


	return ans;
}
struct Edge {
	int from;
	int to;
	int ba_id;
	int val;
};
using Graph=vector<vector<Edge>>;
void add_edge(Graph&g, int s, int d) {
	g[s].push_back(Edge{ s,d,int(g[d].size()),1 });
	g[d].push_back(Edge{ d,s,int(g[s].size())-1,0 });
}

int dfs(Graph&g, const int now,vector<int>&comes) {
	if(now==g.size()-1)return 1;
	comes[now]=true;
	for (int i=0;i<g[now].size();++i){
		auto e=g[now][i];
		if (e.val== 1&&!comes[e.to]) {
			assert(g[e.to][e.ba_id].val==0);
			
			g[e.to][e.ba_id].val=1;
			g[now][i].val=0;

			if (dfs(g, e.to,comes)) {
				return 1;
			}
			else {
				g[e.to][e.ba_id].val=0;
				g[now][i].val=1;
			}
		}
	}
	return 0;
}
int main() {
	int N,M;cin>>N>>M;
	vector<int>vals(N),clubs(N);
	for(int i=0;i<N;++i)cin>>vals[i];
	for (int i = 0; i < N; ++i) {
		cin >> clubs[i];
		clubs[i]--;
	}
	int Q;cin>>Q;
	vector<int>qs(Q);
	vector<int>used(N);
	for (int i = 0; i < Q; ++i) {
		cin >> qs[i];
		qs[i]--;
		used[qs[i]] = true;
	}
	for (int i = 0; i < N; ++i) {
		if(!used[i])qs.push_back(i);
	}
	vector<int>anss(1);
	anss[0]=0;

	const int number=0;
	const int student = number + 5010;
	const int club= student+ N;
	const int goal=club+M;
	Graph g(goal+1);
	for (int i = 0; i < N; ++i) {
		
	}
	for (int i = 0; i < M; ++i) {
		add_edge(g,club+i,goal);
	}
	int next=0;
	for (int q = qs.size() - 1; q >= 0; --q) {
		int stu_id=qs[q];
		{

			add_edge(g, number + vals[stu_id], stu_id +student);
			add_edge(g, stu_id + student, club + clubs[stu_id]);
		}
		while (true) {
			vector<int>comes(g.size());
			if (dfs(g, number + next, comes)) {
				next++;
			}
			else {
				break;
			}
		}
		anss.push_back(next);
	}
	for (int i = 0; i < Q; ++i) {
		cout<<anss[anss.size()-2-i]<<endl;
	}
	
	return 0;
}