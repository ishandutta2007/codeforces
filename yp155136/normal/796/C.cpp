#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

const int MAX_N = 3e5 + 6;

vector<int> edg[MAX_N];
int a[MAX_N];

int main () {
	int n;
	scanf("%d",&n);
	multiset<int> st;
	for (int i=1;n>=i;i++) {
		scanf("%d",&a[i]);
		st.insert(a[i]+2);
	}
	for (int i=1;n>i;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		edg[a].push_back(b);
		edg[b].push_back(a);
	}
	int ans=(*(--st.end()));
	for (int i=1;n>=i;i++) {
		int mx=a[i];
		st.erase(st.find(a[i]+2));
		for (int j:edg[i]) {
			st.erase(st.find(a[j]+2));
			mx = max(mx,a[j]+1);
		}
		if (st.size()) mx = max(mx,(*(--st.end())));
		for(int j:edg[i]) {
			st.insert(a[j]+2);
		}
		st.insert(a[i]+2);
		ans = min(ans,mx);
	}
	printf("%d\n",ans);
}