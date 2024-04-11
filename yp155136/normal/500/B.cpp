#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cassert>
using namespace std;

const int MAX_N = 306;

int dp[MAX_N][MAX_N];
int a[MAX_N];
int pos[MAX_N];
int used[MAX_N];
char c[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(dp,0,sizeof(dp));
		memset(used,0,sizeof(used));
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			pos[a[x]]=x;
		}
		for (int i=1;n>=i;i++) {
			getchar();
			scanf("%s",c);
			for (int j=1;n>=j;j++) {
				if (c[j-1]=='1') dp[i][j]=1;
				else dp[i][j]=0;
			}
		}
		for (int k=1;n>=k;k++) {
			for (int i=1;n>=i;i++) {
				for (int j=1;n>=j;j++) {
					dp[i][j] = max(dp[i][j],dp[i][k] & dp[k][j]);
					if (dp[i][j]) dp[i][j]=1;
				}
			}
		}
//		for (int i=1;n>=i;i++) {
//			for (int j=1;n>=j;j++) {
//				assert(dp[i][j] == dp[j][i]);
//				cout<<dp[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		for (int i=1;n>=i;i++) {
			for (int j=1;a[i]>j;j++) {
				//number j and position i
				if (dp[pos[j]][i] && !used[j]) {
//					cout<<"can change , i = "<<i<<" , j = "<<j<<endl;
					int v1=a[i],v2=j;
					int p1=i,p2=pos[j];
					a[p1]=v2,a[p2]=v1;
					pos[v2]=p1,pos[v1]=p2;
					used[j]=1;
					break;
				}
			}
			used[a[i]]=1;
		}
		for (int x=1;n>=x;x++) {
			if (x!=1) printf(" ");
			printf("%d",a[x]);
		}
		puts("");
	}
}