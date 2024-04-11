#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 2006;

int mp[MAX_N][MAX_N];

int dx[4] = {1,0,-1,0},dy[4]={0,1,0,-1};

char s[MAX_N];

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		getchar();
		memset(mp,-1,sizeof(mp));
		for (int i=1;n>=i;i++) {
			scanf("%s",s);
			for (int j=1;m>=j;j++) {
				if (s[j-1]=='R') mp[i][j]=3;
				else if (s[j-1]=='L') mp[i][j] = 1;
				else if (s[j-1]=='U') mp[i][j] = 0;
				else if (s[j-1]=='D') mp[i][j] = 2;
			}
		}
		for (int j=1;m>=j;j++) {
			int t=0;
			int cnt=0;
			for (int i=1;n>=i;i++) {
				for (int k=0;4>k;k++) {
					int tx=i+t*dx[k];
					int ty=j+t*dy[k];
//					cout<<"i = "<<i<<" , j = "<<j<<" , tx = "<<tx<<" , ty = "<<ty<<" , k = "<<k<<" mp = "<<mp[tx][ty]<<endl;
					if (0<=tx && tx<MAX_N && 0<=ty && ty<MAX_N && mp[tx][ty]==k) cnt++;
				}
				t++;
			}
			if (j!=1) printf(" ");
			printf("%d",cnt);
		}
		puts("");
	}
}