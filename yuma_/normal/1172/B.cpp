#include <bits/stdc++.h>
using namespace std;


using ll=long long ;
using Graph=vector<vector<int>>;

const int mod =998244353;
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
Mod mod_pow(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
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

#define MAX_MOD_N 202400

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

void dfs(int now,int from,const Graph&g,vector<int>&ch_cnts){
	ch_cnts[now]=1;
	for(auto e:g[now]){
		if(e==from)continue;
		dfs(e,now,g,ch_cnts);
		ch_cnts[now]+=ch_cnts[e];
	}
}

Mod dp(int now,int from,const Graph&g,const vector<int>&ch_cnts){
	//cout<<now<<endl;
	Mod answer=1;
	if(from==-1){
		answer=Mod(int(g.size()));
		answer*=fact[g[now].size()];
	}else{
		answer*=fact[g[now].size()];
	}
	for(auto e:g[now]){
		if(e!=from){
			answer*=dp(e,now,g,ch_cnts);
		}
	}
	//cout<<now<<" "<<answer.num<<endl;
	return answer;
}
int main()
{
	init();
	int N;cin>>N;
	vector<vector<int>>edges(N);
	for(int i=0;i<N-1;++i){
		int u,v;
		scanf("%d %d",&u,&v);
		edges[u-1].push_back(v-1);
		edges[v-1].push_back(u-1);
	}
	//cout<<0<<endl;
	vector<int>ch_cnts(N);
	dfs(0,-1,edges,ch_cnts);
	//cout<<1<<endl;
	Mod answer=dp(0,-1,edges,ch_cnts);
	cout<<answer.num<<endl;
}