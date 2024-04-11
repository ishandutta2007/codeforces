#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

const int MAX_N = 1003;
int val[MAX_N][MAX_N];

int row[MAX_N];
int col[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		string s;
		int total=0;
		for (int x=0;n>x;x++) {
			cin >> s;
			for (int y=0;m>y;y++) {
				if (s[y]=='*') {
					row[x]++;
					col[y]++;
					total++;
					val[x][y]=1;
				}
			}
		}
		bool ans=false;
		for (int x=0;n>x;x++) {
			for (int y=0;m>y;y++) {
				if (val[x][y]==0 && row[x]+col[y]==total) {
					printf("YES\n%d %d\n",x+1,y+1);
					ans=true;
					break;
				}
				else if (val[x][y]==1 && (row[x]-1) + (col[y]-1) == total-1) {
					printf("YES\n%d %d\n",x+1,y+1);
					ans=true;
					break;
				}
			}
			if (ans) break;
		}
		if (!ans) puts("NO");
	}
}