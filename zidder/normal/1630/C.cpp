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
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	// 1 2 1
	vector<int> inds(n+1);
	for (int i=0;i<n;++i) inds[a[i]] = i;
	int cnt = 0;
	for (int i=0;i<n;++i){
		int rind = inds[a[i]];
		while (i < rind){
			i++;
			int r1 = rind;
			while(i < rind){
				cnt++;
				r1 = max(r1, inds[a[i]]);
				i++;
			}
			rind = r1;
		}
	}
	cout << cnt << endl;	
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}