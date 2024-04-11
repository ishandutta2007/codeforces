#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m; 
	cin >> n >> m;
	string s;
	cin >> s;

	vector<int> p(n*m), pr(n*m+1);
	for (int i=0;i<s.size();++i) pr[i+1] = pr[i] + (s[i] == '1');
	for (int j=0;j<m;++j){
		for (int i=0;i<n;++i){
			if (s[i*m+j] == '1') {
				p[i*m+j]++;
				break;
			}
		}
	}

	for (int i=1;i<p.size();++i) p[i] += p[i-1];

	bool b = false;
	for (int j=0;j<m;++j){
		if (s[j] == '1') b = true;
		int c = b;
		p[j] += c;
		for (int i=1;i<n;++i){
			c += pr[i*m+j+1] > pr[(i-1)*m+j+1];
			p[i*m+j] += c;
		}
	}
	for (int i: p) printf("%d ", i);
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