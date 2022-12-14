#include<bits/stdc++.h>
using namespace std;

int dp[210][210][210],pre[210][210][210];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size(),x,y;
	s.insert(0," ");t.insert(0," ");
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=200;k++)
				dp[i][j][k]=-1;
	queue<int> q;
	q.emplace(0);
	q.emplace(0);
	q.emplace(0);
	dp[0][0][0]=0;
	while(!q.empty()){
		int i=q.front();q.pop();
		int j=q.front();q.pop();
		int k=q.front();q.pop();
		if(k!=0){
			x=i+(s[i+1]==')');
			y=j+(t[j+1]==')');
			if(dp[x][y][k-1]==-1){
				dp[x][y][k-1]=dp[i][j][k]+1;
				pre[x][y][k-1]=i*300*300+j*300+k;
				q.emplace(x);
				q.emplace(y);
				q.emplace(k-1);
			}
		}
		if(k!=200){
			x=i+(s[i+1]=='(');
			y=j+(t[j+1]=='(');
			if(dp[x][y][k+1]==-1){
				dp[x][y][k+1]=dp[i][j][k]+1;
				pre[x][y][k+1]=i*300*300+j*300+k;	
				q.emplace(x);
				q.emplace(y);
				q.emplace(k+1);
			}
		}
	}
	string ans;
	int nn=n,mm=m,kk=0;
	for(int i=0;i<dp[n][m][0];i++){
		int z=pre[nn][mm][kk];
		if(z%300==kk+1)
			ans+=')';
		else
			ans+='(';
		kk=z%300;z/=300;
		mm=z%300;nn=z/300;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
}