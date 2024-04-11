#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

const int MAX_N = 2e5 + 6;

char c[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		scanf("%s",c);
		int ans=1;
		int dx=0,dy=0;
		map<char,int> mp;
		mp['L']=-1;
		mp['R']=1;
		mp['D']=-1;
		mp['U']=1;
		for (int x=0;n>x;x++) {
			if (c[x]=='L') {
				if (dx==0 || dx==-1) dx=-1;
				else {
					dx=-1;
					dy=0;
					ans++;
				}
			}
			else if (c[x]=='R') {
				if (dx==0 || dx==1) dx=1;
				else {
					dx=1;
					dy=0;
					ans++;
				}
			}
			else if(c[x]=='U') {
				if (dy==1 || dy==0) dy=1;
				else {
					dx=0;
					dy=1;
					ans++;
				}
			}
			else if(c[x]=='D') {
				if (dy==-1 || dy==0) dy=-1;
				else {
					dx=0;
					dy=-1;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}