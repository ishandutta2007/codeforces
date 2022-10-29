#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N =506;

char s[MAX_N];
int mp[MAX_N][MAX_N];
int _[MAX_N],__[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		getchar();
		memset(mp,0,sizeof(mp));
		memset(_,0,sizeof(_));
		memset(__,0,sizeof(__));
		for (int i=1;n>=i;i++) {
			scanf("%s",s);
			for (int j=1;m>=j;j++) {
				mp[i][j] = (s[j-1]=='.'?0:1);
			}
		}
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				_[i] += mp[i][j];
				__[j] += mp[i][j];
			}
		}
		string ans="NO";
		int _get=0;
		bool ala1=true;
		for (int i=1;n>=i;i++) {
			if (_[i] != 0 && _get==0) {
				_get = _[i];
			}
			else if (_[i] !=0 && _[i]==_get);
			else if (_[i] !=0) ala1=false;
			else if (_[i] == 0) {
				if (_get !=0) _get=-1;
			}
		}
		_get=0;
		bool ala2=true;
		for (int i=1;m>=i;i++) {
			if (__[i] != 0 && _get==0) {
				_get = __[i];
			}
			else if (__[i] !=0 && __[i]==_get);
			else if (__[i] !=0) ala2=false;
			else if (__[i] == 0) {
				if (_get !=0) _get=-1;
			}
		}
		if (ala1 && ala2) puts("YES");
		else puts("NO");
	}
}