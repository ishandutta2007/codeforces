#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
using namespace std;

const int MAX_N = 106;

int mp[MAX_N][MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(mp,0,sizeof(mp));
		for (int i=1;n>=i;i++) {
			string s;
			cin >>s;
			for (int j=1;n>=j;j++) {
				mp[i][j] = (s[j-1]=='#');
			}
		}
		bool ans=true;
		for (int i=1;n>=i;i++) {
			for (int j=1;n>=j;j++) {
				if (mp[i][j]) {
					if (mp[i+1][j-1] && mp[i+1][j] && mp[i+1][j+1] && mp[i+2][j]) {
						mp[i][j] = mp[i+1][j-1] = mp[i+1][j] = mp[i+1][j+1] = mp[i+2][j] = 0;
					} 
					else {
						ans=false;
					}
				}
				;
			}
		}
		if (ans) puts("YES");
		else puts("NO");
	}
}