#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
vector<int>primes;
void hurui(const int amax) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>(amax + 1, true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes.push_back(i);
		}
	}
	flag = true;
}
long long int gcd(long long int l, long long int r) {
	if (l > r)return gcd(r, l);
	else {
		if (r%l) {
			return gcd(l, r%l);

		}
		else {
			return l;
		}
	}
}
map<long long int, int>soinnsuu(long long int a) {
	hurui(1e5+10);
	map<long long int, int>ans;
	for (auto i : primes) {
		if (i> a)break;
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}
long long int calc(const map<long long int,int>&mp) {
	long long int ans=1;
	for (auto m : mp) {
		ans*=1+m.second;
	}
	return ans;
}
int main() {
	vector<int>v;
	int N;cin>>N;
	v.push_back(0);
	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		v.push_back(a);
	}
	vector<int>used(N+1);
	int ans=0;
	for (int i = N; i >= 0; --i) {
		if (!used[i]) {
			ans++;
			int now=i;
			while (now) {
				if(used[now])break;
				used[now]=true;
				now=v[now];
			}
			used[now]=true;
		}
	}
	cout<<ans<<endl;
	return 0;
}