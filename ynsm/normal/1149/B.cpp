#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, q, dp[260][260][260], nxt[26][N], l[3], a[3][260];
char s[N];
void calc(int i, int j, int q){
	dp[i][j][q] = n + 1;
	if(i > 0)
		dp[i][j][q] = min(dp[i][j][q], nxt[a[0][i]][dp[i - 1][j][q]]);
    if(j > 0)
    	dp[i][j][q] = min(dp[i][j][q], nxt[a[1][j]][dp[i][j - 1][q]]);
    if(q > 0)
		dp[i][j][q] = min(dp[i][j][q], nxt[a[2][q]][dp[i][j][q - 1]]);
}

int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", &s);
	for(int i = 0; i < 26; i++)
		nxt[i][n] = nxt[i][n + 1] = n + 1;

	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++)
			nxt[j][i] = nxt[j][i + 1];
		nxt[s[i] - 'a'][i] = i + 1;	
	}

	while(q--){
		int p;
		char t, c;
		t = getchar();
		while(t != '+' && t != '-')
			t = getchar();		
		scanf("%d", &p);
		p--;
		if(t == '+'){
			c = getchar();
			while(c < 'a' || c > 'z')
				c = getchar();		
			c -= 'a';
			if(p == 0){
				l[0]++;
				a[0][l[0]] = c;
				for(int i = 0; i <= l[1]; i++)
					for(int j = 0; j <= l[2]; j++)
						calc(l[0], i, j);
			}
			if(p == 1){
				l[1]++;
				a[1][l[1]] = c;
				for(int i = 0; i <= l[0]; i++)
					for(int j = 0; j <= l[2]; j++)
						calc(i, l[1], j);
			}
            if(p == 2){
				l[2]++;
				a[2][l[2]] = c;
				for(int i = 0; i <= l[0]; i++)
					for(int j = 0; j <= l[1]; j++)
						calc(i, j, l[2]);
			}
		}else{
			l[p]--;
		}
		/*
		for(int i = 0; i <= l[0]; i++)
			for(int j = 0; j <= l[1]; j++)
				for(int q = 0; q <= l[2]; q++)
					cerr << i << " " << j << " " << q << " " << dp[i][j][q] << endl;
		cerr << endl;
		*/
		if(dp[l[0]][l[1]][l[2]] > n)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}