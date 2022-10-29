#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
using namespace std;

map<string,int> mp;

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		string a;
		for (int x=0;n>x;x++) {
			cin >> a;
			mp[a]=1;
		}
		int cnt=0;
		for (int x=0;m>x;x++) {
			cin >> a;
			if (mp[a]==1) cnt++;
		}
		n -= (cnt/2);
		m -= (cnt%2==1?cnt/2+1:cnt/2);
		if (n>m) puts("YES");
		else puts("NO");
	}
}