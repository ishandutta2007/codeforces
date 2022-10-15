// https://codeforces.com/problemset/problem/1619/F

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long n, m, k;
    cin >> n >> m >> k;
    long long mi = n / m, ma = (n + m - 1) / m; // min and max number of people at a table
    long long cma = n % m, cmi = m - cma; // number of people at each table
	long long bmi = (mi * cmi * k) / n; // min b
	int cbma = (mi * cmi * k) % n;

	set<pair<int, int> > bind;

	for (int i=0;i<n;++i){
		if (i < cbma){
			bind.emplace(bmi + 1, i + 1);
		} else {
			bind.emplace(bmi, i + 1);
		}
	}

	for (int j=0;j<k;++j){
		vector<int> small;
		vector<pair<int, int> > tmp;
		for (int i=0;i<cmi * mi;++i){
			auto it = bind.rbegin();
			tmp.emplace_back(it->first-1, it->second);
			small.emplace_back(it->second);
			bind.erase(*it);
		}
		auto it = small.begin();
		for (int i=0;i<cmi;++i){
			printf("%d", mi);
			for (int ii=0;ii<mi;ii++){
				printf(" %d", *it);
				it++;
			}
			printf("\n");
		}
		auto it2 = bind.begin();
		for (int i=0;i<cma;++i){
			printf("%d", ma);
			for (int ii=0;ii<ma;ii++){
				printf(" %d", it2->second);
				it2++;
			}
			printf("\n");
		}
		for (auto it: tmp){
			bind.emplace(it);
		}
	}
	printf("\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}