#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		vector<int> v;
		for (int x=0;n>x;x++) {
			int i;
			scanf("%d",&i);
			v.push_back(i);
		}
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end()) - v.begin());
		int ans=false;
		int len=v.size();
		for (int x=1;len-1>x;x++) {
			if (v[x]-v[x-1]==1&&v[x+1]-v[x]==1) ans=true;
		}
		if (ans)puts("YES");
		else puts("NO");
	}
}