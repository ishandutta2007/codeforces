#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



int mod = 998244352;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		
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

template<typename T>
vector<vector<T>> keisann(const vector<vector<T>>l, const vector<vector<T>>r) {
	vector<vector<T>>ans(l.size(), vector<T>(r[0].size()));
	assert(l[0].size() == r.size());
	for (unsigned int h = 0; h < l.size(); ++h) {
		for (unsigned int i = 0; i < r.size(); ++i) {
			for (unsigned int w = 0; w < r[0].size(); ++w) {

				ans[h][w] += l[h][i] * r[i][w];
			}
		}
	}
	return ans;
}

template<typename T>
vector<vector<T>>powgyou(vector<vector<T>>a, const long long int n) {
	assert(a.size() == a[0].size());
	if (!n) {
		vector<vector<T>>e(a.size(), vector<T>(a[0].size()));
		for (unsigned int i = 0; i < a.size(); ++i) {
			e[i][i] = 1;
		}
		return e;
	}
	if (n == 1)return a;
	else {
		vector<vector<T>>ans(a.size(), vector<T>(a[0].size(), 0));
		ans = powgyou(a, n / 2);
		ans = keisann(ans, ans);
		if (n % 2) {
			ans = keisann(ans, a);
		}
		return ans;
	}
}

int solve(int a, int b) {

	//a?b

	int T=10000;
	vector<pair<long long int,int>>pow_memos(T);
	pow_memos[0]=make_pair(1,0);
	for (int i = 0; i < T-1; ++i) {
		pow_memos[i+1]=make_pair(pow_memos[i].first*a%mod,i+1);
	}
	sort(pow_memos.begin(), pow_memos.end());

	for (int i = 0; i < mod; i += T) {
		Mod now=mod_pow(a,i);
		Mod need=Mod(b)/now;

		auto it=lower_bound(pow_memos.begin(),pow_memos.end(),
			make_pair(static_cast<long long int>(need.num),0));
		if (it != pow_memos.end() && it->first == need.num) {
			return i+it->second;
		}
	}
	return -1;

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

//a/b mod(amod) =x
//b*x= amod*y + a
//b*x-amod*y=a
int waru(int a, int b,long long int amod) {
	int ag=gcd(b,amod);
	if(a%gcd(b,amod)!=0)return -1;
	auto p=exeu.solve(b,amod);
	while(p.first<0)p.first+=amod;
	return (p.first*(a/gcd(b,amod)))%amod;
}

int main()
{
	int N;cin>>N;
	vector<int>v(N);for(int i=0;i<N;++i)cin>>v[i];

	vector<vector<Mod>>mat(N,vector<Mod>(N));
	for (int i = 0; i < N; ++i) {
		if(i!=N-1)mat[i][i+1]=Mod(1);
	}
	for (int i = 0; i < N; ++i) {
		mat[i][0] = v[i];
	}

	int A,M;cin>>A>>M;

	Mod num;
	{
		vector<vector<Mod>>fst(1,vector<Mod>(N));
		fst[0][0]=1;
		fst=keisann(fst,powgyou(mat,A-N));
		num=fst[0][0];
		if (num == 0) {
			if (M == 1) {
				cout<<1<<endl;
			}
			else {
				cout << -1 << endl;

			}
			return 0;
		}
		mod++;
		int B=solve(3,M);
		assert(mod_pow(3,B).num==M);
		mod--;
		int X=waru(B,num.num,mod);
		if (X == -1) {
			cout<<-1<<endl;
			return 0;
		}
		mod++;
		//3^(x*num) == 3^B == M

		Mod answer=mod_pow(3,X);
		Mod tt=mod_pow(6,23);
		Mod yy=mod_pow(3,static_cast<long long int>(X)*num.num);
		Mod xx=mod_pow(answer,num.num);
		assert(xx.num==M);
		cout<<answer.num<<endl;
	}
	return 0;

}