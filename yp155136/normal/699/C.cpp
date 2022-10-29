#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 103;

int dp[3][MAX_N]; //means that the last day is 0-->rest, 1-->contest, 2-->gym
int a[MAX_N];
const int INF = 1e9+7;

/*
ai equals 0, the gym is closed and the contest is not carried out;
ai equals 1, the gym is closed, but the contest is carried out;
ai equals 2, the gym is open and the contest is not carried out;
ai equals 3, the gym is open and the contest is carried out.
*/

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=0;3>x;x++) {
			for (int y=0;n>=y;y++) {
				dp[x][y]=INF;
			}
		}
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			if (x==1) {
				dp[0][x]=1;
				if (a[x]==1||a[x]==3) dp[1][x]=0;
				if (a[x]==2||a[x]==3) dp[2][x]=0;
			}
			else {
				dp[0][x]=min(min(dp[0][x-1],dp[1][x-1]),dp[2][x-1]) + 1;
				if (a[x]==1||a[x]==3) dp[1][x] = min(dp[0][x-1],dp[2][x-1]);
				if (a[x]==2||a[x]==3) dp[2][x] = min(dp[0][x-1],dp[1][x-1]);
			}
//			for (int y=0;3>y;y++) {
//				cout<<dp[y][x]<<' ';
//			}
//			cout<<endl;
		}
		printf("%d\n",min(min(dp[0][n],dp[1][n]),dp[2][n]));
	}
}