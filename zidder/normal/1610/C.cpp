#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;
vector<int> a, b;

bool check(int val){
	int cnt = 0;
	for (int i=0;i<n;++i){
		if (cnt <= b[i] && a[i] + cnt + 1 >= val){
			cnt++;
		}
	}
	return cnt >= val;
}

void solve(int test_ind){
	cin >> n;
	a = vector<int> (n);
	b = vector<int> (n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &a[i], &b[i]);
	}

	int mi=1, ma = n + 1;
	for (int i=0;i<20;++i){
		int mid = (mi + ma) / 2;
		if (check(mid))
			mi = mid;
		else
			ma = mid;
	}
	cout << mi << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}