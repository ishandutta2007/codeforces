#include<bits/stdc++.h>
using namespace std;

long long int solve(long long int x){
	long long int res = 0;
	for(long long int base=1, dig=1;x > 0;base*=10, ++dig){
		long long int cur = min(x, base * 9);
		res += cur * dig;
		x -= cur;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int k;
	cin >> k;
	long long int l = 1, r = 1e12;
	while(l < r){
		long long int mid = (l + r) >> 1;
		if(solve(mid) >= k)
			r = mid;
		else
			l = mid + 1;
	}
	k -= solve(l - 1);
	vector<long long int> digs;
	while(l){
		digs.emplace_back(l % 10);
		l /= 10;
	}
	reverse(digs.begin(), digs.end());
	cout <<  digs[k - 1] << endl;
}