#include<bits/stdc++.h>
using namespace std;

string s[500];

int dp[401][401];

int ask(int x1,int y1,int x2,int y2){
	return dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>s[i], s[i].insert(0," ");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1] -dp[i-1][j-1] + (s[i][j] =='a');
	long long int ans = 0;
	for(int l=1;l<=n;l++)
		for(int r=l+1;r<=n;r++){
			vector<int> v[26];
			for(int i=1;i<=m;i++){
				if(s[l][i] == s[r][i])
					v[s[l][i]-'a'].emplace_back(i);
			}
			for(int i=0;i<26;i++){
				int cur = 0;
				for(int j=0;j<v[i].size();j++){
					if(cur < j)	cur = j;
					while(cur + 1 < v[i].size() && 
						ask(l,v[i][j],r,v[i][cur+1]) <= k
					)	cur++;
				
					ans += cur - j;
				}
			}
		}
	cout << ans << endl;
}