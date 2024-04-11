#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
	int n,v;
	while (cin >> n >> v) {
		vector<int> ans;
		int i=0;
		while (n--) {
			i++;
			int a;
			cin >> a;
			vector<int> tmp;
			while (a--) {
				int t;
				cin >> t;
				tmp.push_back(t);
			}
			sort(tmp.begin(),tmp.end());
			if (v>tmp[0]) ans.push_back(i);
		}
		cout<<ans.size()<<endl;
		for (auto i:ans) cout<<i<<' ';
		cout<<endl;
	}
}