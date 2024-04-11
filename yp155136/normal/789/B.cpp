#include <iostream>
#include <stdio.h>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;

int main () {
	LL a,b,c,d;
	map<LL,bool> mp;
	while (cin >> a>> b >> c >> d) {
		mp.clear();
		while (d--) {
			LL x;
			cin >> x;
			mp[x]=1;
		}
		int cnt=100;
		LL ans=0;
		LL now=a;
		while (cnt--) {
			if (abs(now) > c) break;
			else if (mp[now] == 0) ans++;
//			else ans++;
			now *= b;
		}
		if (ans > 40) puts("inf");
		else printf("%I64d\n",ans);
	}
}