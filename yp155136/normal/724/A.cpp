#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

const int MAX_N = 1e5 + 6;

int a[MAX_N];

int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int s[13];

int main () {
	string i,j;
	while (cin >> i >> j) {
		s[0]=0;
		for (int x=1;12>=x;x++) {
			s[x] = s[x-1] + d[x];
		}
		map<string,int> mp;
		mp["monday" ] = 1;
		mp["tuesday" ] = 2;
		mp["wednesday" ] = 3;
		mp["thursday" ] = 4;
		mp["friday" ] = 5;
		mp["saturday" ] = 6; 
		mp["sunday" ] = 7;
		int a=mp[i];
		int b=mp[j];
		bool ans=false;
		for (int x=1;12>=x;x++) {
			for (int y=x+1;x+1>=y && 12>=y;y++) {
				if ((b-a+7)%7 == (s[y]-s[x])%7) {
					ans=true;
				}
			}
		}
		if (ans) puts("YES");
		else puts("NO");
	}
}