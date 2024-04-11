#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 1<<15;
int v[MOD];

void solve(int test_ind){
	int a;
	cin >> a;
	cout << v[a] << " ";
}

int main(){
	for (int i=0;i<MOD;++i) v[i] = -1;
	v[0] = 0;
	vector<int> q = {0};
	for (int qind=0;qind<q.size();++qind){
		int a = q[qind];
		int ind1 = (a+MOD-1)%MOD;
		if (v[ind1] == -1) {
			q.push_back(ind1);
			v[ind1] = v[a] + 1;
		}
		if (a % 2 == 0) {
			ind1 = a / 2;
			if (v[ind1] == -1) {
				q.push_back(ind1);
				v[ind1] = v[a] + 1;
			}
			ind1 += MOD / 2;
			if (v[ind1] == -1) {
				q.push_back(ind1);
				v[ind1] = v[a] + 1;
			}
		}
	}

	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}