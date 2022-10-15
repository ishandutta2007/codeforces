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
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
	}
	multiset<long long> s1;
	for (int i: a) s1.insert(i);
	long long sm = 0;
	for (int i: a) sm += i;
	multiset<long long> s;
	s.insert(sm);
	int cnt = n-1;
	while (!s.empty()){
		if (s1.empty()) {
			cout << "NO" << endl;
			return;
		}
		long long a1 = *s.rbegin();
		long long a2 = *s1.rbegin();
		s.erase(s.find(a1));
		if (a1 == a2) {
			s1.erase(s1.find(a2));
			continue;
		}
		if (a1 < a2) {
			cout << "NO" << endl;
			return;
		}
		cnt--;
		s.insert(a1/2);
		s.insert(a1-a1/2);
	}
	if (cnt == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}