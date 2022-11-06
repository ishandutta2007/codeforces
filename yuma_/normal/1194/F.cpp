#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAX_N=10001;



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

int main() {
	ios::sync_with_stdio(false);
	init();
	int N;
	ll T;cin>>N>>T;
	vector<ll>as(N);
	for(int i=0;i<N;++i)cin>>as[i];
	//sort(as.begin(),as.end());
	Mod answer=0;
	ll sum=0;
	int pre=-1;
	Mod pre_per=Mod(0);
	Mod val=1;
	for(int i=0;i<N;++i){
		val=val/Mod(2);
		sum+=as[i];
		if(sum+i+1<=T){
			answer+=Mod(1);
		}else if(sum<=T){
			int nex=T-sum;
			//cout<<nex<<endl;
			Mod nex_per(0);
			if(pre==-1){
				Mod plus=0;
				for(int x=i+1;x>=nex+1;--x){
					plus+=comb(i+1,x);
				}
				//cout<<plus<<endl;
				nex_per+=Mod(1)-plus*val;
				//cout<<nex_per<<endl;
			}else{
				nex_per=pre_per-comb(i,pre)*val;
				//cout<<Mod(32)*nex_per<<endl;
				Mod plus=0;
				for(int x=pre;x>=nex+1;--x){
					plus+=comb(i+1,x);
				}
				//cout<<plus.num<<endl;
				nex_per-=plus*val;
			}
			//cout<<(Mod(16)*nex_per).num<<endl;
			answer+=nex_per;
			pre=nex;
			pre_per=nex_per;

		}else{

		}
	}
	cout<<answer.num<<endl;
	return 0;
}