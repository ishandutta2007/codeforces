#include "bits/stdc++.h"
using namespace std;

#pragma warning(disable:4996)


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

#define MAX_MOD_N 1024000

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
int N;
string ast,bst;
//Mod solve(bool asame,bool bsame,int now,vector<int>&rests) {
//	if(now==N){
//		if (!asame&&!bsame) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//		}
//	else {
//		if (!asame&&!bsame) {
//			Mod ans=1;
//			int rest=N-now;
//			for (int i = 0; i < 26; ++i) {
//				ans*=comb(rest,rest-rests[i]);
//				rest-=rests[i];
//			}
//			return ans;
//		}
//		else {
//			Mod ans = 0;
//			for (int i = 0; i < 26; ++i) {
//				if (rests[i]) {
//					bool nextasame(false), nextbsame(false);
//					if (asame) {
//						if (ast[now] > 'a' + i) {
//							continue;
//						}
//						else if (ast[now] == 'a' + i) {
//							nextasame = true;
//						}
//					}
//					if (bsame) {
//						if (bst[now] < 'a' + i) {
//							continue;
//						}
//						else if (bst[now] == 'a' + i) {
//							nextbsame = true;
//						}
//					}
//					rests[i]--;
//					ans += solve( nextasame, nextbsame, now + 1, rests);
//					rests[i]++;
//				}
//			}
//			return ans;
//		}
//		
//	}
//}
Mod solve1(vector<int>rests,string& aast) {
	Mod sum=0;
	Mod now=1;
	for (int i = 0; i < N; ++i) {

		Mod perm = 0;
		perm = fact[N - i - 1];
		for (int j = 0; j < 26; ++j) {
			perm*=factinv[rests[j]];
		}
		for (int j = 0; j < aast[i]-'a'; ++j) {
			if (rests[j]) {
				Mod ans = 1;
				ans=perm;
				ans*=rests[j];
				sum+=ans;
			}
		}
		if (rests[aast[i] - 'a']) {
			rests[aast[i]-'a']--;
		}
		else {
			return sum;
		}
	}
	return sum;
}
int main() { 
	init();
	{
		/*scanf("%s", ast);
		scanf("%s", bst);*/
		cin>>ast>>bst;
	}
	N=string(ast).size();
	vector<int>rests(26);
	for (int i=0;i<N;++i){
		char ch=ast[i];
		rests[ch-'a']++;
	}
	Mod aa=solve1(rests,ast);
	Mod bb=solve1(rests,bst);
	Mod ans=bb-aa;
	cout<<ans-Mod(1)<<endl;
	return 0;
}