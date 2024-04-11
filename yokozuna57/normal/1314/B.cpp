#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second
#define rep(i,x) for(int i = 0 ; i < x ; i ++)

const int INF = 1000000000;

int main(){
	static int n,k;
	static bool fav[(1<<17)+10];
	for(int i = 0 ; i < (1<<17)+10 ; i ++){
		fav[i] = false;
	}
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i < k ; i ++){
		int a;
		scanf("%d",&a);
		fav[a] = true;
	}
	
	static int dp[(1<<17)+10][2][2];
	for(int i = 1 ; i <= (1<<n) ; i ++){
		if((i&-i) != 1)continue;
		int cnt = 0;
		if(fav[i])cnt ++;
		if(fav[i+1])cnt ++;
		if(cnt == 0){
			dp[i][0][0] = 0;
			dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -INF;
		}
		else if(cnt == 1){
			dp[i][0][1] = dp[i][1][0] = 1;
			dp[i][0][0] = dp[i][1][1] = -INF;
		}
		else {
			dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = -INF;
			dp[i][1][1] = 1;
		}
	}
	for(int t = 1 ; t <= n-1 ; t ++){
		for(int i = 1 ; i <= (1<<n) ; i ++){
			if((i&-i) != (1<<t))continue;
			int x = 1<<(t-1);
			dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -INF;
			rep(a,2)rep(b,2)rep(c,2)rep(d,2){
				int cnt[2] = { a+c , b+d };
				if(cnt[1] >= 1){
					if(cnt[0] == 0){
						dp[i][0][1] = max( dp[i][0][1] , dp[i-x][a][b]+dp[i+x][c][d]+2 );
					}
					else {
						dp[i][1][1] = max( dp[i][1][1] , dp[i-x][a][b]+dp[i+x][c][d]+3 );
					}
				}
				else {
					if(cnt[0] == 0){
						dp[i][0][0] = max( dp[i][0][0] , dp[i-x][a][b]+dp[i+x][c][d] );
					}
					else if(cnt[0] == 1){
						dp[i][1][0] = max( dp[i][1][0] , dp[i-x][a][b]+dp[i+x][c][d]+1 );
						dp[i][0][1] = max( dp[i][0][1] , dp[i-x][a][b]+dp[i+x][c][d]+2 );
					}
					else {
						dp[i][1][1] = max( dp[i][1][1] , dp[i-x][a][b]+dp[i+x][c][d]+2 );
					}
				}
			}
		}
	}
	
	int ret = 0;
	ret = max( ret , dp[1<<(n-1)][0][0] );
	ret = max( ret , dp[1<<(n-1)][0][1]+1 );
	ret = max( ret , dp[1<<(n-1)][1][0]+1 );
	ret = max( ret , dp[1<<(n-1)][1][1]+1 );
	cout << ret << endl;
}