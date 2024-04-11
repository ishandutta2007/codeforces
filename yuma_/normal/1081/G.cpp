#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



int mod = 1000000007;
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

Mod solve(int a, int b) {
	Mod now_answer = 0;

	if(a>b)swap(a,b);
	for (int i = 0; i < a + b-1; ++i) {
		int num;
		if(i<a)num=i+1;
		else if(i<b)num=a;
		else num=a+b-i-1;


		Mod is_max_prob = Mod(2) / Mod(i + 2);
		now_answer += (Mod(1) - is_max_prob)*num;
	}
	now_answer/=Mod(2);
	return now_answer;
}

int main()
{
	int N,K;cin>>N>>K>>mod;K--;
	map<int,long long int>nums;
	if (K >= 20) {
		nums[1]=N;
	}
	else {
		nums[(N>>K)]=(1<<K)-(N-(N>>K)*(1ll<<K));
		nums[(N>>K)+1]=N-(N>>K)*(1ll<<K);
	}

	Mod answer=0;
	{
		Mod answer1=0;
		for (auto n : nums) {
			answer1+=Mod(n.first)*Mod(n.first-1)/Mod(4)*n.second;
		}
		answer+=answer1;
	}
	{
		Mod answer2=0;
		auto min_it=nums.begin();
		auto max_it=next(nums.begin());
		long long int min_num=min_it->second;
		long long int max_num=max_it->second;

		long long int min_min_merge_cnt=min_num*(min_num-1)/2;
		long long int max_max_merge_cnt=max_num*(max_num-1)/2;
		long long int min_max_merge_cnt=min_num*max_num;

		{
				
			answer2+=solve(min_it->first,min_it->first)*min_min_merge_cnt;
			answer2 += solve(min_it->first, max_it->first)*min_max_merge_cnt;
			answer2 += solve(max_it->first, max_it->first)*max_max_merge_cnt;

		}
		answer+=answer2;
		
	}
	cout<<answer.num<<endl;
	return 0;
}