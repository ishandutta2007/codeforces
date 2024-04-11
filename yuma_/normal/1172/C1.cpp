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
Mod invs[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
		invs[i+1]=Mod(1)/Mod(i+1);
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
	int N,M;cin>>N>>M;
	vector<int>loves(N);
	for(int i=0;i<N;++i){
		scanf("%d",&loves[i]);
	}
	vector<ll>weights(N);
	for(int i=0;i<N;++i){
		scanf("%d",&weights[i]);
	}
	ll love_sum=0,hate_sum=0;
	for(int i=0;i<N;++i){
		if(loves[i])love_sum+=weights[i];
		else hate_sum+=weights[i];
	}
	vector<vector<Mod>>dp(2,vector<Mod>(M+1));
	dp[0][0]=1;
	//cout<<1<<endl;
	for(int i=0;i<M;++i){
		int cur=i%2;
		int tar=1-cur;

		for(int love_plus=0;love_plus<=i;++love_plus){
			int hate_plus=-(i-love_plus);
			ll now_love_sum=love_sum+love_plus;
			ll now_hate_sum=hate_sum+hate_plus;
			if(now_hate_sum<0)continue;
			Mod love_per=Mod(now_love_sum)*invs[now_love_sum+now_hate_sum];
			dp[tar][love_plus+1]+=love_per*dp[cur][love_plus];
			dp[tar][love_plus]+=(Mod(1)-love_per)*dp[cur][love_plus];
		}
		for(int x=0;x<=M;++x){
			dp[cur][x]=Mod(0);
		}
	}
	
	Mod total_love=0;
	Mod total_hate=0;
	for(int love_plus=0;love_plus<=M;++love_plus){
		Mod per=dp[M%2][love_plus];
		ll now_love_sum=love_sum+love_plus;
		ll now_hate_sum=hate_sum-(M-love_plus);
		if(now_hate_sum<0)continue;
		total_love+=per*now_love_sum;
		total_hate+=per*Mod(now_hate_sum);
	}
	vector<Mod>answers(N);
	for(int i=0;i<N;++i){
		if(loves[i]){

			answers[i]=total_love*Mod(weights[i])/Mod(love_sum);
		}else{
			answers[i]=total_hate*Mod(weights[i])/Mod(hate_sum);

		}
	}
	for(int i=0;i<N;++i){
		printf("%d\n",answers[i].num);
	}
	return 0;

}