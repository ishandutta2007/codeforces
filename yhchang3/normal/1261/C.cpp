#include<bits/stdc++.h>
using namespace std;

string g[1000000];

int n,m;
vector<vector<int> > dp,vis;


bool check(int mid){
	queue<pair<int,int> > q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(g[i][j]=='X'&&dp[i][j]>=mid){
				vis[i][j]=0;
				q.push(make_pair(i,j));
			}
			else vis[i][j]=-1;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;q.pop();
		if(vis[x][y]>=mid)	break;
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++){
				int nx=x+i,ny=y+j;
				if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]!=-1)	continue;
				vis[nx][ny]=vis[x][y]+1;
				q.push(make_pair(nx,ny));
			}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if((g[i][j]=='X'&&vis[i][j]==-1)||(g[i][j]=='.'&&vis[i][j]!=-1))
				return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>g[i];
dp.resize(n);
	vis.resize(n);
	for(int i=0;i<n;i++){
		dp[i].resize(m,-1);
		vis[i].resize(m,0);
	}
	queue<pair<int,int> > q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(g[i][j]=='X'){
				bool ok=false;
				if(i==0||j==0||i==n-1||j==m-1)
					ok=true;
				else{
					for(int ii=-1;ii<=1;ii++)
						for(int jj=-1;jj<=1;jj++)
							if(g[i+ii][j+jj]=='.')
								ok=true;
				}
				if(ok){
					dp[i][j]=0;
					q.push(make_pair(i,j));
				}
			}
	while(!q.empty()){
		auto now=q.front();q.pop();
		for(int ii=-1;ii<=1;ii++)
			for(int jj=-1;jj<=1;jj++)
				if(now.first+ii>=0&&now.first+ii<n&&now.second+jj<m&&now.second+jj>=0&&dp[now.first+ii][now.second+jj]==-1){
					dp[now.first+ii][now.second+jj]=dp[now.first][now.second]+1;
					q.push(make_pair(now.first+ii,now.second+jj));
				}
	}
	int l=0,r=1e6;
	while(l<r){
		int mid = (l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<'\n';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			if(g[i][j]=='X'&&dp[i][j]>=l)
				cout<<'X';
			else
				cout<<'.';
		cout<<'\n';
	}
}
;