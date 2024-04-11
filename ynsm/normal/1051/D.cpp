//BOOOOOOOOOOOOM 
#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = 998244353, inf = (int)1e9;

int n, k, dp[2010][2010][4];
void add(int &a,int b){
	a+=b;
	if(a >= mod)
		a-=mod;
}
int get(int a,int b){ 
	if(a == 0 && b == 0)//00
		return 0;       //00
	
	if(a == 0 && b == 1)//00
		return 1;       //01
	
	if(a == 0 && b == 2)//00
		return 1;       //10
	
	if(a == 0 && b == 3)//00
		return 1;       //11
	
	if(a == 1 && b == 0)//01
		return 0;       //00
	                        
	if(a == 1 && b == 1)//01
		return 0;       //01

	if(a == 1 && b == 2)//01
		return 2;       //10

	if(a == 1 && b == 3)//01
		return 0;       //11

	if(a == 2 && b == 0)//10
		return 0;       //00
	
	if(a == 2 && b == 1)//10
		return 2;       //01
	
	if(a == 2 && b == 2)//10
		return 0;       //10
	
	if(a == 2 && b == 3)//10
		return 0;       //11
	
	if(a == 3 && b == 0)//11
		return 1;       //00
	                        
	if(a == 3 && b == 1)//11
		return 1;       //01

	if(a == 3 && b == 2)//11
		return 1;       //10

	if(a == 3 && b == 3)//11
		return 0;       //11
	
	
}
int main(){    
	cin >> n >> k;      
	dp[1][1][0] = 1;	
	dp[1][2][1] = 1;	
	dp[1][2][2] = 1;	
	dp[1][1][3] = 1;	
	for(int i = 2; i <= n; i++)
		for(int j = 0; j <= i + i; j++)
			for(int a = 0; a < 4; a++)
				for(int b = 0; b < 4; b++)
					add(dp[i][j + get(a,b)][b], dp[i - 1][j][a]);
	
	cout << (0ll + dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) %mod;
	
	return 0;
}