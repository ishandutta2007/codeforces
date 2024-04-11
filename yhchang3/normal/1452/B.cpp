#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int &x:v)
			cin >> x;
		long long int res = *max_element(v.begin(), v.end()) * (n - 1LL) - accumulate(v.begin(), v.end(), 0LL);
		if(res < 0) {
			res = res % (n - 1);
			if(res < 0)
				res += n - 1;
		}
		cout << res << '\n';
	}
}