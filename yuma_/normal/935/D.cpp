#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long double ld;



const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod():num(0){
	}
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
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

Mod solve(int M,int now,vector<int>&as,vector<int>&bs){
	if(now==as.size()){
		return Mod(0);
	}else{
		
		Mod ans=0;
		Mod awin,draw,bwin;
		if(as[now]==0&&bs[now]==0){
			awin=Mod(M-1)/Mod(M)/Mod(2);
			draw=Mod(1)/Mod(M);
			bwin=Mod(M-1)/Mod(M)/Mod(2);
		}else if(as[now]==0){
			assert(bs[now]);
			 awin=Mod(bs[now]-1)/Mod(M);
			 draw=Mod(1)/Mod(M);
			 bwin=Mod(M-bs[now])/Mod(M);
		}else if(bs[now]==0){
			assert(as[now]);
			awin=Mod(M-as[now])/Mod(M);
			draw=Mod(1)/Mod(M);
			bwin=Mod(as[now]-1)/Mod(M);

		}else{
			if(as[now]==bs[now]){
				awin=Mod(0);
				draw=Mod(1);
				bwin=Mod(0);
			}else{
				if(as[now]<bs[now]){
					awin=Mod(1);
					draw=Mod(0);
					bwin=Mod(0);
				}else{
					awin=Mod(0);
					draw=Mod(0);
					bwin=Mod(1);
				}
			}
		}
		ans+=solve(M,now+1,as,bs)*draw;
		ans+=bwin;
		return ans;
	}
}
int main() { 
	
	int N,M;cin>>N>>M;
	vector<int>as(N),bs(N);
	for(int i=0;i<N;++i){
		cin>>as[i];
	}
	for(int i=0;i<N;++i){
		cin>>bs[i];
	}
	Mod ans=solve(M,0,as,bs);
	cout<<ans.num<<endl;
	return 0;

}