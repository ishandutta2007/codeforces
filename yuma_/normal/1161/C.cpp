#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAX_N=10001;


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

int main() {
	int N;cin>>N;
	map<int,int>mp;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		mp[a]++;
	}
	int x=mp.begin()->second;
	bool ok=x>=N/2+1;
	if(ok)cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
	return 0;
}