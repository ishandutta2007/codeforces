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
int main() { 
	ld R,x1,y1,x2,y2;cin>>R>>x1>>y1>>x2>>y2;

	x2-=x1;
	y2-=y1;

	ld dis=sqrt(x2*x2+y2*y2);
	if(dis>R){
		ld ansx=x1;
		ld ansy=y1;
		ld ansd=R;
		cout<<setprecision(10)<<fixed<<ansx<<" "<<ansy<<" "<<ansd<<endl;
	}else if(dis<1e-9){
		ld x3=0;
		ld y3=R;

		
		ld ansx=(x2+x3)/2;
		ld ansy=(y2+y3)/2;
		ld ansd=(dis+R)/2;

		ansx+=x1;
		ansy+=y1;

		cout<<setprecision(10)<<fixed<<ansx<<" "<<ansy<<" "<<ansd<<endl;
	}else{
		ld x3=-x2*R/dis;
		ld y3=-y2*R/dis;

		ld ansx=(x2+x3)/2;
		ld ansy=(y2+y3)/2;
		ld ansd=(dis+R)/2;

		ansx+=x1;
		ansy+=y1;

		cout<<setprecision(10)<<fixed<<ansx<<" "<<ansy<<" "<<ansd<<endl;
	}
	return 0;

	//int N,M;cin>>N>>M;
	//vector<int>as(N),bs(N);
	//for(int i=0;i<N;++i){
	//	cin>>as[i];
	//}
	//for(int i=0;i<N;++i){
	//	cin>>bs[i];
	//}

}