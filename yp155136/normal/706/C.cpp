#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;

int c[MAX_N];
LL dp[2][MAX_N];
const LL INF = 1e17 + 10;
string v[2][MAX_N];
string val[MAX_N];

string f(string s) {
	string ret="";
	int len=s.size();
	for (int x=0;len>x;x++) ret+=" ";
	for (int x=0;len>x;x++) ret[x] = s[len-x-1];
	return ret;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n){
		for (int x=1;n>=x;x++) cin>>c[x];
		for(int x=1;n>=x;x++) {
			cin >> val[x];
		}
		for (int x=0;n>=x;x++) {
			dp[0][x] = dp[1][x] =INF;
			v[0][x] = v[1][x] = "";
		}
		dp[0][0] = dp[1][0] = 0;
		for (int x=1;n>=x;x++) {
			//0 --> no change
			//1 --> change
			if (val[x] >= v[0][x-1]) {
				dp[0][x] = min(dp[0][x],dp[0][x-1]);
			}
			if (val[x] >= v[1][x-1]) {
				dp[0][x] = min(dp[0][x],dp[1][x-1]);
			}
			v[0][x] = val[x];
			string tmp=f(val[x]);
			if (tmp >= v[0][x-1]) {
				dp[1][x] = min(dp[1][x],dp[0][x-1] + c[x]);
			}
			if (tmp >= v[1][x-1]) {
				dp[1][x] = min(dp[1][x],dp[1][x-1] + c[x]);
			}
			v[1][x] = tmp;
		}
		if (dp[0][n] == INF && dp[1][n] == INF) cout<<"-1"<<endl;
		else cout<<min(dp[0][n],dp[1][n]) << endl;
	}
}