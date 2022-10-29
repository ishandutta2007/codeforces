#include <iostream>
#include <stdio.h>
#include <Cstring>
using namespace std;

int cnt[144];

int main () {
	string s;
	while (cin >> s) {
		memset(cnt,0,sizeof(cnt));
		int sz=s.size();
		for (int x=0;sz>x;x++) {
			cnt[s[x]]++;
		}
		string t="Blbsr";
		int ans=1234567;
		for (int x=0;t.size()>x;x++) {
			ans = min(ans,cnt[t[x]]);
		}
		ans = min(ans,cnt['a']/2);
		ans = min(ans,cnt['u']/2);
		printf("%d\n",ans);
	}
}