#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long double ld;



int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod():num(0){;}
	Mod(long long int n) : num(n) { ; }
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

long long int gcd(long long int l, long long int r) {
	assert(l > 0 && r > 0);
	if (l > r)return gcd(r, l);
	else {
		const long long int num = r%l;
		if (num) {
			return gcd(l, num);
		}
		else {
			return l;
		}
	}
}
struct Extended_Euclid {
	static pair<long long int, long long int> solve(long long int l, long long int r) {
		const long long int agcd = gcd(l, r);
		l /= agcd;
		r /= agcd;
		bool flag = false;
		if (l < r) {
			flag = true;
			swap(l, r);
		}
		int x1 = 1, y1 = 0, z1 = l;
		int x2 = 0, y2 = 1, z2 = r;
		while (z2 != 1) {
			const int q = (z1 - (z1%z2)) / z2;
			const int px = x1;
			const int py = y1;
			const int pz = z1;
			x1 = x2;
			y1 = y2;
			z1 = z2;
			x2 = px - q*x2;
			y2 = py - q*y2;
			z2 = pz - q*z2;
		}
		if (flag)swap(x2, y2);
		return make_pair(x2, y2);
	}
}exeu;

int main() { 
	long long int A,B,P,X;cin>>A>>B>>P>>X;
	mod=P;
	vector<long long int>ls(P),rs;
	iota(ls.begin(),ls.end(),0);
	rs.push_back(1);
	while(true){
		Mod next=Mod(rs.back())*Mod(A);
		if(next.num==1)break;
		else rs.push_back(next.num);
	}

	long long int roop_size=static_cast<long long int>(rs.size())*ls.size()/gcd(rs.size(),ls.size());

	long long int ans=0;

	vector<Mod>nums(min(X,10000ll)+1);
	for(int i=1;i<nums.size();++i){
		if(i>=100000)break;
		nums[i]=Mod(i)*mod_pow(A,i);
	}
	const auto base_p=exeu.solve(ls.size(),int(rs.size()));
	for(long long int i=0;i<rs.size();++i){
		long long int r(rs[i]);
		long long int l=Mod(B)/Mod(r);

		// a*x+l=b*y+r
		// a*x - b*y = r-l

		auto p=base_p;
		p.second*=-1;
		p.first*=i-l;
		p.second*=i-l;

		while(p.first<0){
			long long int sa=-p.first;
			long long int num=(sa-1)/rs.size()+1;
			p.first+=rs.size()*num;
			p.second+=ls.size()*num;
		}
		while(p.first>=rs.size()){
			long long int sa=p.first-rs.size();
			long long int num=(sa-1)/rs.size()+1;
			p.first-=rs.size()*num;
			p.second-=ls.size()*num;
		}

		long long int fst_num=p.first*ls.size()+l;
		if(X>=fst_num){

			long long int nans=(X-fst_num)/roop_size+1;
			ans+=nans;
		}

	}
	cout<<ans<<endl;
	return 0;

}