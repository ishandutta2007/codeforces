#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

ll C[4002][4002];
ll FAC[4002];
void init(){
	C[0][0] = 1;
	for(int i = 1 ; i < 4002 ; i ++){
		C[i][0] = 1;
		for(int j = 1 ; j <= i-1 ; j ++){
			C[i][j] = C[i-1][j-1]+C[i-1][j];
			if(C[i][j] >= MOD)C[i][j] -= MOD;
		}
		C[i][i] = 1;
	}
	FAC[0] = 1;
	for(int i = 1 ; i < 4002 ; i ++){
		FAC[i] = FAC[i-1]*i;
		FAC[i] %= MOD;
	}
}

int main(){
	init();
	static int h[2],n;
	static bool used[2][3800];
	for(int i = 0 ;i < 3800 ; i ++){
		used[0][i] = used[1][i] = false;
	}
	scanf("%d%d%d",&h[0],&h[1],&n);
	for(int i = 0 ; i < 2*n ; i ++){
		int x,y;
		scanf("%d%d",&x,&y); x --; y --;
		used[0][x] = true;
		used[1][y] = true;
	}
	
	static ll dp[2][4000][2000];
	for(int t = 0 ; t < 2 ; t ++){
		for(int i = 0 ; i < 4000 ; i ++){
			for(int j = 0 ; j < 2000 ; j ++){
				dp[t][i][j] = 0;
			}
		}
		dp[t][0][0] = 1;
		dp[t][1][0] = 1;
		if(h[t] >= 2 && !used[t][0] && !used[t][1])dp[t][1][1] = 1;
		for(int i = 2 ; i < h[t] ; i ++){
			for(int j = 0 ; j <= 1800 ; j ++){
				dp[t][i][j] = dp[t][i-1][j];
				if(j >= 1 && !used[t][i] && !used[t][i-1]){
					dp[t][i][j] += dp[t][i-2][j-1];
					if(dp[t][i][j] >= MOD)dp[t][i][j] -= MOD;
				}
			}
		}
	}
	
	/*for(int j = 0 ; j <= 4 ; j ++){
		cout << dp[0][h[0]-1][j] << " ";
	}cout << endl;
	for(int j = 0 ; j <= 4 ; j ++){
		cout << dp[1][h[1]-1][j] << " ";
	}cout << endl;*/
	
	ll cnt[2] = {};
	for(int t = 0 ; t < 2 ; t ++){
		for(int i = 0 ; i < h[t] ; i ++){
			if(!used[t][i])cnt[t] ++;
		}
	}
	
	/*for(int t = 0 ; t < 2 ; t ++){
		cout << cnt[t] << endl;
	}
	cout << C[3][1] << endl;*/
	
	ll ret = 0;
	for(int a = 0 ; a <= 1800 ; a ++){
		for(int b = 0 ; b <= 1800 ; b ++){
			if(cnt[0]-2*a < b)continue;
			if(cnt[1]-2*b < a)continue;
			ll r = dp[0][h[0]-1][a]*dp[1][h[1]-1][b]; r %= MOD;
			r *= C[cnt[0]-2*a][b];
			r %= MOD;
			r *= C[cnt[1]-2*b][a];
			r %= MOD;
			r *= FAC[a];
			r %= MOD;
			r *= FAC[b];
			r %= MOD;
			ret += r;
			if(ret >= MOD)ret -= MOD;
			//cout << a << " " << b << " " << r << endl;
		}
	}
	cout << ret << endl;
}