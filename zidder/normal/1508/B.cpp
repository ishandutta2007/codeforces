#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	long long k;
	cin >> n >> k;
	if (n <= 60){
		if ((1ll<<(n-1)) < k){
			cout << -1 << endl;
			return;
		}
	}
	for (int i=1;i<n-60;++i){
		printf("%d ", i);
	}
	for (int i=max(n-60, 1);i<=n;++i){
		long long cnt = 0;
		for (int j=i;j<=n;++j){
			long long prevcnt = cnt;
			if (j == n) cnt++;
			else cnt += (1ll<<(n-j-1));
			if (cnt >= k) {
				k -= prevcnt;
				for (int p=j;p>=i;--p){
					printf("%d ", p);
				}
				i = j;
				break;
			}
		}
	}
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}