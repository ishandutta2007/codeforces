#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 2e5 + 6;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		vector<int> v1;
		vector<int> v2;
		for (int i=1;n>=i;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			v1.push_back(x);
			v2.push_back(y);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		int ans=0;
		int m;
		scanf("%d",&m);
		for (int i=1;m>=i;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			ans = max(ans,x-v2[0]);
			ans = max(ans,v1[n-1]-y);
		}
		printf("%d\n",ans);
	}
}