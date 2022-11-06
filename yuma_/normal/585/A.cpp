#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;

struct child {
	int id;
	long long int conf;
	long long int v;
	long long int d;
	long long int p;
};

int main() {
	int N; cin >> N;
	vector<child>childs;
	for (int i = 0; i < N; ++i) {
		int v, d, p; cin >> v >> d >> p;
		childs.push_back(child{ i+1,p,v,d,p });

	}
	vector<int>clears;
	int target = 0;
	while (childs.size() > target) {
		clears.push_back(childs[target].id);
		vector<int>rans(childs.size());
		vector<int>ranids;
		for (int i = 1; i <= childs[target].v; ++i) {
			const int ntarget = target + i;
			if (ntarget >= childs.size())break;
			childs[ntarget].conf -= childs[target].v - i + 1;
			if (childs[ntarget].conf < 0&&!rans[ntarget]) {
				rans[ntarget] = 1;
				ranids.push_back(ntarget);
			}
		}
		while (!ranids.empty()) {
			const int cry(ranids.back());
			ranids.pop_back();
			for (int i = cry +1; i < childs.size(); ++i) {
				childs[i].conf -= childs[cry].d;
				if (childs[i].conf < 0 && !rans[i]) {
					rans[i] = 1;
					ranids.push_back(i);
				}
			}
		}
		vector<child>newchilds;
		for (int i = 0; i < childs.size(); ++i) {
			if (!rans[i])newchilds.push_back(childs[i]);
		}
		childs = newchilds;
		target++;
	}
	cout << clears.size() << endl;
	for (int i = 0; i < clears.size(); ++i) {
		cout << clears[i];
		if (i != clears.size() - 1)cout << " ";
	}
	cout << endl;
	return 0;
}