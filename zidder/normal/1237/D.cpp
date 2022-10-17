#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, endind=1;
	cin >> n;
	vector<int> v(n), ans(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	map<int, int> ms;
	ms[v[0]] = 1;
	bool finish=false;
	for(int start=0,end=1;start<n;end=endind%n){
		if (finish){
			ans[start++] = -1;
			continue;
		}
		if (endind == start + 2 * n){
			finish=true;
			continue;
		}
		ms[v[end]]++;
		int max_val = ms.rbegin()->first;
		while (max_val > v[end] * 2){
			ans[start] = endind - start;
			ms[v[start]]--;
			if (ms[v[start]] == 0)
				ms.erase(v[start]);
			start++;
			if (start==n){
				break;
			}
			max_val	= ms.rbegin() -> first;
		}
		endind++;
	}
	for(int i=0;i<n;++i)
		cout << ans[i] << " ";
	cout<<endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}