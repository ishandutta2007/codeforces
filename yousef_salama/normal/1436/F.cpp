#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 100005;

long long modpow(long long x, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;
	
	long long r = modpow(x, p / 2);
	return r * r % MOD;
}
long long modinv(long long x){
	return modpow(x, MOD - 2);
}

struct element{
	long long val, num, sum, sum2, size;
	element(){}
	element(long long val, long long num, long long sum, long long sum2, long long size): val(val), num(num), sum(sum), sum2(sum2), size(size){}
};

element combine(element& a, element& b){
	return element(-1, a.num * b.num % MOD, (a.sum * b.num + a.num * b.sum) % MOD,
					(a.sum2 * b.num % MOD + b.sum2 * a.num % MOD + 2LL * a.sum * b.sum % MOD) % MOD, -1);
}

element calc(long long num, long long val){
	if(num == 0){
		return element(val, 1, 0, 0, num);
	}
	
	long long cnt = modpow(2, num);
	
	long long sum = num * val % MOD * modpow(2, num - 1) % MOD;
			
	long long sum2;
	
	if(num == 1)sum2 = 1LL * val * val % MOD;
	else sum2 = (num * val % MOD * val % MOD * modpow(2, num - 1) + num * (num - 1) % MOD * val % MOD * val % MOD * modpow(2, num - 2)) % MOD;
	
	return element(val, cnt, sum, sum2, num);
}

int main(){
	int m;
	scanf("%d", &m);
	
	vector <long long> c(MAX, 0), f(MAX, 0);
	
	for(int i = 0; i < m; i++){
		int a, freq;
		scanf("%d %d", &a, &freq);
		
		c[a] += freq;
	}
	
	vector <element> pre(MAX), pre2(MAX);
	
	for(int i = 1; i < MAX; i++)if(c[i] != 0){
		pre[i] = calc(c[i], i);
		pre2[i] = calc(c[i] - 1, i);
	}
	
	for(int i = 1; i < MAX; i++){
		vector <int> v;
		for(int j = i; j < MAX; j += i)if(c[j] != 0){
			v.push_back(j);
		}
		if(v.empty())continue;
		
		vector <element> pref(v.size()), suf(v.size());
		for(int j = 0; j < (int)v.size(); j++){
			if(j == 0)pref[j] = pre[v[j]];
			else pref[j] = combine(pref[j - 1], pre[v[j]]);
		}
		for(int j = ((int)v.size()) - 1; j >= 0; j--){
			if(j == (int)v.size() - 1)suf[j] = pre[v[j]];
			else suf[j] = combine(suf[j + 1], pre[v[j]]);
		}
		
		f[i] = 0;
		for(int j = 0; j < (int)v.size(); j++){
			element e1 = pre2[v[j]];
			if(j > 0)e1 = combine(e1, pref[j - 1]);
			if(j + 1 < (int)v.size())e1 = combine(e1, suf[j + 1]);
			
			f[i] = (f[i] + c[v[j]] * (e1.sum2 + e1.sum * v[j] % MOD) % MOD) % MOD;
			
		}
	}
	
	for(int i = MAX - 1; i >= 1; i--){
		for(int j = i + i; j < MAX; j += i)
			f[i] = (f[i] - f[j] + MOD) % MOD;
	}
	printf("%lld\n", f[1]);
	
	return 0;
}