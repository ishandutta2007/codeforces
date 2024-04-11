#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);

	// inside - outside >= k
	// inside + outside = n
	// inside >= (n + k) / 2
	vector<int> b(a.begin(), a.end());
	sort(b.begin(), b.end());

	int mn = 1000000000;
	int x, y;
	int insd = (n + k + 1) / 2;
	for (int i=0;i<=n-insd;++i){
		if (mn > b[i+insd-1] - b[i]){
			mn = b[i+insd-1] - b[i];
			x = b[i];
			y = b[i+insd-1];
		}
	}
	printf("%d %d\n", x, y);
	int lft = 0, cnt = 0;
	for (int i=0;i<n;++i){
		if (k == 1){
			break;
		}
		cnt += ((a[i] >= x) && (a[i] <= y));
		if (2 * cnt > (i - lft + 1)){
			k--;
			printf("%d %d\n", lft + 1, i + 1);
			lft = i + 1;
			cnt = 0;
		}
	}
	cout << lft + 1 << " " << n << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}