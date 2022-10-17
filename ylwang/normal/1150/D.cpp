#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
/*
ns1,s2,s3


s1,s2,s3
*/
string s;
vector < int > S[4];
int dp[255][255][255];
int nxt[100005][35];
int to(char a) {return a - 'a' + 1;}
signed main()
{
	memset(dp, 0, sizeof(dp));
    int n = read(), Qnum = read();
    cin >> s; s = ' ' + s;
    int n1 = 0, n2 = 0, n3 = 0;
    For(j, 1, 26)
    	nxt[n][j] = nxt[n+1][j] = n+1;	
    for(int i = n-1; i >= 0; i--) {
    	for(int j = 1; j <= 26; j++)
    		nxt[i][j] = nxt[i+1][j];
    	nxt[i][to(s[i+1])] = i + 1;
	}
//	For(i, 1, n) {
//		For(j, 1, 26){
//			cout << nxt[i][j] << ' ';
//		} 
//		cout << endl;
//	} 
	For(i, 0, 250) For(j, 0, 250) For(k, 0, 250) 
		dp[i][j][k] = n + 1; 
	dp[0][0][0] = 0;
	while(Qnum--) {
		char opt1; int opt2; 
		cin >> opt1 >> opt2;
		if(opt1 == '+') {
			char c; cin >> c;
            S[opt2].push_back(c-'a'+1);
			if(opt2 == 1) {
				++n1;
				int i = n1; For(j, 0, n2) For(k, 0, n3) {
					if(i > 0) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i-1][j][k]][S[1][i-1]]);
					if(j > 0) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][S[2][j-1]]);
					if(k > 0) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][S[3][k-1]]);
				}
			} else if(opt2 == 2) {
				++n2;
				For(i, 0, n1) {int j = n2; For(k, 0, n3) {
					if(i > 0) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i-1][j][k]][S[1][i-1]]);
					if(j > 0) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][S[2][j-1]]);
					if(k > 0) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][S[3][k-1]]);
				}}
			} else {
				++n3;
				For(i, 0, n1) For(j, 0, n2) { int k = n3;
					if(i > 0) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i-1][j][k]][S[1][i-1]]);
					if(j > 0) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][S[2][j-1]]);
					if(k > 0) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][S[3][k-1]]);
				}
			}
		} else {
			if(opt2 == 1) {
				int i = n1; For(j, 0, n2) For(k, 0, n3) dp[i][j][k] = n + 1;
				--n1; S[1].pop_back();
			} else if(opt2 == 2) {
				int j = n2; For(i, 0, n1) For(k, 0, n3) dp[i][j][k] = n + 1;
				--n2; S[2].pop_back();
			} else {
				int k = n3; For(i, 0, n1) For(j, 0, n2) dp[i][j][k] = n + 1;
				--n3; S[3].pop_back();
			}
		}
		// cout << s1 << ' ' << s2 << ' ' << s3 << endl;
//		For(i, 1, n1) {
//			For(j, 1, n2) {
//				For(k, 1, n3) {
//					cout << dp[i][j][k] << ' ';
//				}
//				cout << endl;
//			} 
//			cout << endl;
//		}
		if(dp[n1][n2][n3] > n) printf("NO\n");
		else printf("YES\n");
	}
    return 0;
}