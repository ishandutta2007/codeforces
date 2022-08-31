#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
typedef long long ll;



int main() {
	int m,n;scanf("%d%d",&m,&n);

	vector<vector<int>> ts(m,vector<int>(n));
	for(int y=0;y<m;y++)for(int x=0;x<n;x++){
		scanf("%d",&ts[y][x]);
	}

	vector<vector<int>> dp(m+1,vector<int>(n+1));


	for(int y=1;y<=m;y++)for(int x=1;x<=n;x++){
		dp[y][x]=max(dp[y-1][x],dp[y][x-1])+ts[y-1][x-1];
	}

	for(int y=1;y<=m;y++){
		if(y!=1)printf(" ");
		printf("%d",dp[y][n]);
	}
	printf("\n");
}