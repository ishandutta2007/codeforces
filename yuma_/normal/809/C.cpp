#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld=long double;



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


int x1, x2, yy, y2;
int K;
int cnt=0;

long long solve(int lu_num,long long int l, long long int r, long long int u, long long int d) {
	cnt++;
	if(r<=x1||x2<=l||d<=yy||y2<=u)return Mod(0);
	long long  ans = 0;
	bool lr_break = x1 <= l&&r <= x2;
	bool ud_break = yy <= u&&d <= y2;
	if (lr_break&&ud_break) {
		long long int sz=max((r-l),(d-u));
		long long int set_num=min((r-l),(d-u));
		//lu_num kara lu_num+sz-1 set_num 

		long long int  sum= (lu_num+lu_num + sz - 1)*sz/2;
		sum%=mod;
		long long int  n_sum=0;
		if (lu_num > K) {
			n_sum=0;
		}
		else if (lu_num + sz - 1 > K) {
			long long int minus = (K + 1 + lu_num + sz - 1)*(lu_num+sz-1-K-1+1) / 2;
			minus%=mod;
			n_sum = (mod + sum - minus) % mod;
		}
		else {
			n_sum=sum;
		}
		return (n_sum*set_num)%mod;
	}
	else if (lr_break) {
		ans+=solve(lu_num,l,r,u,(u+d)/2);
		ans+=solve(lu_num,l,r,(u+d)/2,d);
	}
	else if (ud_break) {
		ans+=solve(lu_num,l,(l+r)/2,u,d);
		ans+=solve(lu_num,(l+r)/2,r,u,d);
	}
	else {
		ans+=solve(lu_num,l,(l+r)/2,u,(u+d)/2);
		ans+=solve(lu_num+(r-l)/2,(l+r)/2,r,u,(u+d)/2);
		ans+=solve(lu_num+(r-l)/2,l,(l+r)/2,(u+d)/2,d);
		ans+=solve(lu_num,(l+r)/2,r,(u+d)/2,d);
	}
	ans%=mod;
	return ans;
}

int main() {
	int Q;cin>>Q;
	while (Q--) {
		scanf("%d %d %d %d %d",&x1,&yy,&x2,&y2,&K);
		x1--;yy--;
		long long int  answer=solve(1,0,(1<<30),0,(1<<30));
		int aans=answer%mod;
		const char ch='/'+1;
		printf("%d\n",aans);
	}
	return 0;
}