#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;

vector<ld>ten_nines(101);
int main() {
	ten_nines[0]=1;
	for (int i = 0; i < 100; ++i) {
		ten_nines[i+1]=ten_nines[i]*10/9;
	}

	int TestCase;scanf("%d",&TestCase);
	while (TestCase--) {
		int N;scanf("%d",&N);
		ld C,T;
		scanf("%Lf %Lf",&C,&T);
		vector<pair<int,int>>problems;
		for (int i = 0; i < N; ++i) {
			int dif,sco;scanf("%d %d",&dif,&sco);
			problems.emplace_back(dif,sco);
		}
		sort(problems.begin(),problems.end(),greater<pair<int,int>>());
		vector<vector<vector<ld>>>dp(2,vector<vector<ld>>(N+1,vector<ld>(10*N+1,1e18)));
		int now=0;
		int nex=1;
		dp[now][0][0]=0;
		for (int i=0;i<N;++i) {
			auto problem=problems[i];
			for (int solved_cnt = 0; solved_cnt <= i; ++solved_cnt) {
				for (int now_score = 0; now_score <= 10 * i; ++now_score) {
					dp[nex][solved_cnt][now_score]=
						min(dp[nex][solved_cnt][now_score],
							dp[now][solved_cnt][now_score]);
					dp[nex][solved_cnt+1][now_score+problem.second]=
						min(dp[nex][solved_cnt+1][now_score+problem.second],
							dp[now][solved_cnt][now_score]+ten_nines[solved_cnt]*problem.first);
				}
			}
			for (int i = 0; i < N+1; ++i) {
				for (int j = 0; j < 10*N+1; ++j) {
					dp[now][i][j]=1e18;
				}
			}
			swap(now,nex);
		}
		vector<vector<ld>>results(dp[now]);

		//nneeeddeddddddddd
		for (int i = 0; i <= N; ++i) {
			for (int j = 10*N; j >0; --j) {
				results[i][j-1]=min(results[i][j-1],results[i][j]);
			}
		}
		int amin=0;
		int amax=10*N+1;

		while (amin + 1 != amax) {
			int amid=(amin+amax)/2;
			bool ok=false;
			{
				for (int i = 0; i <= N; ++i) {
					ld normal_time=10.0/9*results[i][amid];
					ld X=(-1+sqrt(C*normal_time))/(C);
					ld total_time;
					if (X < 0) {
						total_time=normal_time+i*10;
					}
					else {
						total_time=X+normal_time/(1+X*C)+i*10;
					}
					if(total_time<T)ok=true;
				}
			}
			if(ok)amin=amid;
			else amax=amid;
		}
		cout<<amin<<endl;
	}
	

	return 0;
}