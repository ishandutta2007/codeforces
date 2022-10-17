#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int lan(int n){
	int c = 0;
	while (n > 1){
		c++;
		n /= 2;
	}
	return c;
}
vector<int> pows(18, 1), spows(19, 0);
void solve(int test_ind){
	int n, x=-1;
	cin >> n;
	vector<long long> a(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
		if (a[i] == -1){
			x = i;
			a[i]=0;
		}
		if (x == -1)
			a[i] = 0;
	}
	int l = lan(n);
	for(int i=1;i<=l;++i)
		pows[i] = pows[i-1] * 2;
	for(int i=l-1;i>=0;--i){
		spows[i] = pows[i] + spows[i+1];
	}
	vector<vector<long long> > ans(n+1, vector<long long>(l+1, -1));
	ans[n][0] = 0;
	for(int i=n;i>0;--i){
		for(int j = 0; j < l; ++j){
			if (ans[i][j]==-1)
				continue;
			if (ans[i-1][j+1] == -1){
				ans[i-1][j+1] = a[i-1] + ans[i][j];
				continue;
			}
			ans[i-1][j+1] = min(ans[i-1][j+1], ans[i][j]+a[i-1]);
		}
		for(int j=1;j<=l;++j){
			if (ans[i][j]==-1)
				continue;
			if (spows[l - j] + i > n){
				if (ans[i-1][j] == -1)
					ans[i-1][j] = ans[i][j];
				else
					ans[i-1][j] = min(ans[i-1][j], ans[i][j]);
			}
		}
	}
	cout << ans[1][l] << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}