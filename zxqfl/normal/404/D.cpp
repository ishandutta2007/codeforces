#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <cassert>
#include <cmath>

#define mp make_pair
#define point pair<int, int> 
#define px first
#define py second
#define INF 1000000000
#define EPS 1e-8
#define loop(i, x) for(int i = 0; i < (x); i++)
#define rep(x) for (int COUNTER = 0; COUNTER < (x); COUNTER++)
#define ll long long

#define MOD 1000000007
#define BOMB 3
#define MAXLEN 1000000

using namespace std;

ll dp[4][4];
ll newdp[4][4];

void process(int type)
{
	if (type == 0)
	{
		loop(i, 3)
			loop(j, 4)
				newdp[0][i] += dp[j][0];
	}
	else if (type == 1)
	{
		loop(i, 3)
			newdp[1][BOMB] += dp[i][1];
		loop(i, 3)
			newdp[1][i] += dp[BOMB][1];
	}
	else if (type == 2)
	{
		newdp[2][BOMB] += dp[BOMB][2];
	}
	else
	{
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				newdp[BOMB][i] += dp[j][BOMB];
	}
}

int main()
{
	loop(i, 4)
		loop(j, 4)
			dp[i][j] = 0;
			
	loop(i, 4)
		dp[1][i] = 1;
	
	while (1)
	{
		loop(i, 4)
			loop(j, 4)
				newdp[i][j] = 0;
			
		int c = getchar();
		
		if (c == '0' || c == '1' || c == '2')
			process(c - '0');
		else if (c == '*')
			process(BOMB);
		else if (c == '?')
			loop(i, 4)
				process(i);
		else
			break;
		
		/*
		loop(i, 4)
		{
			loop(j, 4)
			{
				printf("dp[%d][%d] = %d\n", i, j, newdp[i][j]);
			}
		}
		printf("\n");
		*/
		
		loop(i, 4)
			loop(j, 4)
				dp[i][j] = newdp[i][j] % MOD;
	}
	
	ll total = 0;
	total += dp[BOMB][1];
	total += dp[1][0];
	total += dp[0][0];
	printf("%I64d\n", total % MOD);
}