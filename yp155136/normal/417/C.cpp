#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e3 +6;

int mp[MAX_N][MAX_N];

//1-->i win j
//0-->nothing
//-1 --> i lose j

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		memset(mp,0,sizeof(mp));
		bool can=true;
		for (int i=1;n>=i;i++) {
			int cnt=0;
			for (int j=1;n>=j;j++) {
				if (i==j) continue;
				if (mp[j][i] == 1) continue;
				mp[i][j] = 1;
				cnt++;
				if (cnt == k) break;
			}
			if (cnt != k) can=false;
		}
		if (can) {
			int m=0;
			for (int i=1;n>=i;i++) {
				for (int j=1;n>=j;j++) {
					m += (mp[i][j]==1);
				}
			}
			printf("%d\n",m);
			for (int i=1;n>=i;i++) {
				for (int j=1;n>=j;j++) {
					if (mp[i][j]==1) {
						printf("%d %d\n",i,j);
					}
				}
			}
		}
		else puts("-1");
	}
}