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
	set<int> s;
	for (int i=1;i<=n;++i) s.insert(i);
	for (int i=1;i<=n;++i){
		s.erase(i);
		printf("%d ", i);
		for (auto it=s.rbegin();it!=s.rend();++it){
			printf("%d ", *it);
		}
		printf("\n");
		s.insert(i);
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}