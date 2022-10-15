#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int ask(int x){
	x++;
	printf("? %d\n", x);
	fflush(stdout);
	int y;
	scanf("%d", &y);
	return y - 1;
}

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> a(n, -1);
	int c = -1;
	for (int i=0;i<n;++i){
		if (a[i] != -1) continue;
		vector<int> v;
		int q = 2;
		while (q){
			int y = ask(i);
			if (q == 2) c++;
			if (q == 1) v.push_back(y);
			if (y == i){
				q--;
			}
		}
		// for (int i: v) cout << i << " ";
		// cout << endl;
		int prv = i;
		for (int j=0;j<v.size();++j){
			int nind = (j + c) % v.size();
			a[prv] = v[nind];
			prv = a[prv];
		}
		// for (int i: a){
		// 	cout << i << " ";
		// }
		// cout << endl;
		c += v.size();
	}
	printf("!");
	for (int i: a){
		printf(" %d", i + 1);
	}
	printf("\n");
	fflush(stdout);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}