#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



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

#define MAX_MOD_N 102400

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
int to_num(char ch) {
	int num;
	if ('a' <= ch&&ch <= 'z') {
		num = 0 + (ch - 'a');
	}
	else {
		num = 26 + (ch - 'A');
	}
	return num;
}
vector<int>to_v(string& st) {
	vector<int>v(52);
	for (int i = 0; i < st.size(); ++i) {
		char ch(st[i]);
		
		v[to_num(ch)]++;
	}
	return v;
}

void sub(vector<long long int>&dp, int x) {
	vector<long long int>ans_dp(dp.size());
	for (int i = 0; i < dp.size(); ++i) {
		if (i + x < dp.size()) {
			dp[i+x]-=dp[i];
			if(dp[i+x]<0)dp[i+x]+=mod;
		}
	}
	
}
const int MAX_S=100001;
int main() {
	init();
	vector<int>v(52);
	string st;
	int N=0;
	{
		char chs[100010];scanf("%s",chs);
		st=chs;
		N=st.size();
		v=to_v(st);
	}
	vector<long long int>dp(MAX_S+1);
	dp[0]=1;
	{
		for (int ch = 0; ch < 52; ++ch) {
			for (int l_cnt =MAX_S; l_cnt >=0; --l_cnt) {
				if (v[ch]&&l_cnt + v[ch] <= MAX_S) {
					dp[l_cnt+v[ch]]+=dp[l_cnt];
					if(dp[l_cnt+v[ch]]>=mod)dp[l_cnt+v[ch]]-=mod;
				}
			}
		}
	}

	Mod ini=fact[N/2]*fact[N/2];
	for (int i = 0; i < 52; ++i) {
		if(v[i])ini/=fact[v[i]];
	}

	vector<vector<long long int>>answers(52,vector<long long int>(52));
	for (int a = 0; a < 52; ++a) {
		for (int b = a; b < 52; ++b) {
			if (a == b) {
				answers[a][b]=dp[N/2];
			}
			else {
				vector<long long int>ini_dp(dp);
				int x=N / 2 - v[a] - v[b];
				sub(ini_dp,v[a]);
				sub(ini_dp,v[b]);

				answers[a][b]=ini_dp[N/2];
				if(N/2-v[a]-v[b]>=0)answers[a][b]+=ini_dp[N/2-v[a]-v[b]];

				answers[a][b]%=mod;
			}
		}
	}
	int Q;cin>>Q;
	while (Q--) {
		int x,y;scanf("%d %d",&x,&y);
		x--;y--;
		int x_num=to_num(st[x]);
		int y_num=to_num(st[y]);

		if(x_num>y_num)swap(x_num,y_num);
		long long int answer=answers[x_num][y_num];
		answer*=ini.num;
		answer%=mod;
		printf("%lld\n",answer);
	}

	return 0;
}