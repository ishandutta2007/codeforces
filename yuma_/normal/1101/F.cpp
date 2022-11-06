#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int main()
{
	int N,M;cin>>N>>M;
	vector<int>as(N);
	for(int i=0;i<N;++i)scanf("%d",&as[i]);
	vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(N)));
	for (int l = 0; l < N; ++l) {
		for (int r = l; r < N; ++r) {
			dp[l][r][0]=as[r]-as[l];
		}
		for (int k = 1; k < N; ++k) {
			
			dp[l][l][k]=0;
			int m=l;

			for (int r = l + 1; r < N; ++r) {
				while (m!=N-1) {

					int ans_1 = max(dp[l][m][k - 1],as[r]-as[m]);
					int ans_2=max(dp[l][m+1][k-1],as[r]-as[m+1]);

					if (ans_1 > ans_2) {
						m++;
					}
					else {
						break;
					}
				}
				dp[l][r][k]=max(dp[l][m][k-1],as[r]-as[m]);
			}
		}
	}

	long long int answer=0;
	for (int i = 0; i < M; ++i) {
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a--;b--;
		if(d>=N)d=N-1;
		long long int nanswer=dp[a][b][d];
		answer=max(answer,nanswer*c);
	}
	cout<<answer<<endl;
	return 0;
}