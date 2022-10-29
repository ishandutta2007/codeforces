#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

typedef long long LL;
const int MAX_N = 52;

LL pow(LL a,LL n) {
	LL ret=1;
	for (int i=0;n>i;i++) {
		ret*=a;
	}
	return ret;
}

int main () {
	LL n,m;
	while (scanf("%lld %lld",&n,&m) != EOF) {
		vector<int> go_up;
		vector<int> go_down;
		m--;
		go_up.push_back(0);
		for (int i=1;n>=i;i++) {
			go_up.push_back(i);
		}
		int id=n-1;
		while (m>0) {
			int t=m%2;
			m/=2;
			if (t==1) {
				go_up.erase(go_up.begin()+id);
			}
			id--;
		}
//		for (auto i:go_up) {
//			cout<<i<<' ';
//		}
//		cout<<endl;
		set<int> st;
		bool flag=false;
		for (int i=1;go_up.size()>i;i++) {
			if (flag) printf(" ");
			printf("%d",go_up[i]);
			flag=1;
			st.insert(go_up[i]);
		}
		for (int i=n-1;i>=1;i--) {
			if (st.find(i) == st.end()) {
				printf(" %d",i);
			}
		}
		puts("");
	}
}