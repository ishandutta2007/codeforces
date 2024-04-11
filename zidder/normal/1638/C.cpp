#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);

	vector<int> b(n+1);
	for (int i=0;i<n;++i) b[a[i]] = i;

	int lind = 0;
	int ans = 0;

	for (int i=1;i<=n;++i){
		if (b[i] == lind){
			ans++;
			lind++;
			continue;
		}
		int rind = b[i++];
		int cnt = rind - lind;
		while (cnt){
			// cout << cnt << " " << rind << " " << lind << " " << i << endl;
			if (b[i] > rind){
				cnt += b[i] - rind - 1;
				rind = b[i];
				i++;
				continue;
			}
			i++;
			cnt--;
		}
		i--;
		ans++;
		lind = rind + 1;
	}

	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}