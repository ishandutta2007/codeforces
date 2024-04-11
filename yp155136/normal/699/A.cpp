#include <iostream>
#include <stdio.h>
using namespace std;

#define int long long

const int MAX_N = 2e5+6;
int a[MAX_N];

main () {
	int n;
	while (scanf("%I64d",&n) != EOF) {
		string s;
		cin >> s;
		for (int x=0;n>x;x++) {
			scanf("%I64d",&a[x]);
		}
		int ans=123456789000;
		for (int x=0;n-1>x;x++) {
			//x collide x+1
			if (s[x]=='R' && s[x+1]=='L') {
				ans = min(ans,(a[x+1]-a[x])/2);
			}
		}
		if (ans==123456789000) puts("-1");
		else printf("%I64d\n",ans);
	}
}