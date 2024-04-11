#include <iostream>
#include <stdio.h>
#include <cstring>
#include <set>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 +6;

LL a[MAX_N];
LL pre[MAX_N];
LL suf[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%lld",&a[i]);
		}
		if (n==1) {
			puts("NO");
			continue;
		}
		for (int i=1;n>=i;i++) {
			pre[i] = pre[i-1] + a[i];
		}
//		cout<<"pre["<<n<<"] = "<<pre[n]<<endl;
		if (pre[n] % 2 != 0) {
			puts("NO");
			continue;
		}
		suf[n+1]=0;
		for (int i=n;i>=1;i--) {
			suf[i] = suf[i+1] + a[i];
		}
		bool check=false;
		for (int i=1;n>=i;i++) {
			if (pre[i] == suf[i+1]) {
				if (!check)puts("YES");
				check=true;
			}
		}
		if (check) continue;
		multiset<LL> st;
		for (int i=1;n>=i;i++) {
			st.insert(a[i]);
			if (st.find(pre[i]-(pre[n]/2)) != st.end()) {
				check=true;
			}
		}
		st.clear();
		for (int i=n;i>=1;i--) {
			st.insert(a[i]);
			if (st.find(suf[i]-(suf[1]/2)) != st.end()) {
				check=true;
			}
		}
		if (check) puts("YES");
		else puts("NO");
	}
}