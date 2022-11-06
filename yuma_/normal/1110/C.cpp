#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
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

vector<long long int> divisor(long long int n) {
	vector<long long int> res;
	for (long long int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	sort(begin(res), end(res));
	return res;
}
int solve(int a) {
	if(a==1)return 1;
	auto divs=divisor(a);
	int x=divs[1];
	return a/x;
	
}
int MAX_N=28;
int main() {

	vector<int>memo(MAX_N);
	for (int i = 1; i < MAX_N; ++i) {
		int num=(1<<i)-1;
		memo[i]=solve(num);
	}

	int Q;cin>>Q;
	while (Q--) {
		int num;cin>>num;
		int answer=-1;
		for (int i = 1; i < MAX_N; ++i) {
			if (num < (1 << i)) {
				if (num + 1 == (1 << i)) {
					answer=memo[i];
				}
				else {
					answer=(1<<i)-1;
				}
				break;
			}
			else {
				continue;
			}
		}
		cout<<answer<<endl;
	}

	return 0;
}