#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool check(vector<int> &a, int bad){
	int ri=a.size() - 1;
	for (int li=0; li<a.size(); li++){
		if (a[li] == bad)
			continue;
		while (ri > 0 && a[ri] == bad)
			ri--;
		if (a[li] != a[ri])
			return false;
		ri--;
	}
	return true;
}

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
	}
	int bad1 = -1, bad2 = -1;

	for (int li=0, ri=n-1;li<n;li++,ri--){
		if (a[li] != a[ri]){
			bad1=a[li];
			bad2=a[ri];
		}
	}

	if (!check(a, bad1) && !check(a, bad2)){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}