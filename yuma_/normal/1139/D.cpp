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
int main() {
	int M;cin>>M;
	vector<Mod>answers(M+1);
	answers[1]=0;

	vector<int>memo(1000);
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 10; ++j) {
			if(i&(1<<j))memo[i]++;
		}
	}
	for (int i = 2; i <= M; ++i) {
		auto mp=soinnsuu(i);
		vector<int>sos;
		for(auto m:mp)sos.emplace_back(int(m.first));
		int x=sos.size();

		vector<int>v(1<<x);
		for (int id = 0; id < (1 << x); ++id) {
			int num=1;
			for (int m = 0; m < x; ++m) {
				if (id&(1 << m)) {
					num*=sos[m];
				}
			}
			int xx=M/num;
			for (int nid = 0; nid < (1 << x); ++nid) {
				if ((id&nid) == nid) {
					if((memo[id]-memo[nid])%2==0)v[nid]+=xx;
					else v[nid]-=xx;
				}
			}
		}
		int rest=M-accumulate(v.begin(),v.end(),0);
		int same_num=0;
		for (int id = (1<<x)-1; id>=0;--id){
			int num = 1;
			for (int m = 0; m < x; ++m) {
				if (id&(1 << m)) {
					num *= sos[m];
				}
			}
			if(num==i)same_num+=v[id];
			else {


				answers[i] += answers[num] * v[id]/Mod(M-same_num);
			}
		}
		answers[i]+=Mod(M)/Mod(M-same_num);
	}
	Mod sum=accumulate(answers.begin()+1,answers.end(),Mod(0));
	cout<<(Mod(1)+sum/Mod(M)).num<<endl;
	return 0;
}