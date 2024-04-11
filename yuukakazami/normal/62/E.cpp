/*
 * E. World Evil.cpp
 *
 *  Created on: 2011-2-26
 *      Author: user
 *
 * turn the maxFlow problem to a min-cut problem
 * and as n'is 5 we can use set-dp
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long int64;

const int MAX_N=5;
const int MAX_M=100000+10;
int64 xCap[MAX_N][MAX_M];//(r,c)->(r,c+1)
int64 yCap[MAX_N][MAX_M];//(r,c)->((r+1)%n,c)
int n,m;
int cutSet[1<<MAX_N];
int64 dp[MAX_M][1<<MAX_N];

int main(){
	scanf("%d%d",&n,&m);
	for (int c = 0; c < m-1; ++c) {
		for (int r = 0; r < n; ++r) {
			scanf("%I64d",&xCap[r][c]);
		}
	}

	for (int c = 0; c < m; ++c) {
		for (int r = 0; r < n; ++r) {
			scanf("%I64d",&yCap[r][c]);
		}
	}

	for (int set = 0; set < (1<<n); ++set) {
		cutSet[set]=0;
		for (int cur = 0; cur < n; ++cur) {
			bool withSource1=set>>cur&1;
			bool withSource2=set>>((cur+1)%n)&1;
			if(withSource1^withSource2)
				cutSet[set]|=1<<cur;
		}
	}

	fill(dp[0],dp[0]+(1<<n),LONG_LONG_MAX/4);
	dp[0][(1<<n)-1]=0;

	int64 xSum[1<<MAX_N],ySum[1<<MAX_N];
	for (int c = 1; c < m; ++c) {
		fill(dp[c],dp[c]+(1<<n),LONG_LONG_MAX/4);
		fill(xSum,xSum+(1<<n),0);
		fill(ySum,ySum+(1<<n),0);
		for (int set = 0; set < (1<<n); ++set) {
			for (int r = 0; r < n; ++r) {
				if(set>>r&1)
					xSum[set]+=xCap[r][c-1];
				if(cutSet[set]>>r&1)
					ySum[set]+=yCap[r][c];
			}
		}
		for (int prevSet = 0; prevSet < (1<<n); ++prevSet) {
			for (int curSet = 0; curSet < (1<<n); ++curSet) {
				int64 tmp=dp[c-1][prevSet]+xSum[prevSet^curSet]+ySum[curSet];
				if(tmp<dp[c][curSet])
					dp[c][curSet]=tmp;
			}
		}
	}

	printf("%I64d\n",dp[m-1][0]);
}