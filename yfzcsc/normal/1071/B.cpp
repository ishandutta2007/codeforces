#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii>L[2];
int n,k,dp[2010][2010],tp,vis[2010][2010];
char s[2010][2010],anses[20100];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=(s[i][j]=='a')+max(dp[i-1][j],dp[i][j-1]);
	int mx=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if((i+j-1)-dp[i][j]<=k)mx=max(mx,i+j-1);
	int p=0,np=1;
	if(!mx){
		L[np].push_back(pii(1,1));
		anses[tp++]=s[1][1];
	} else {
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if((i+j-1)-dp[i][j]<=k&&(i+j-1)==mx)
					L[np].push_back(pii(i,j)),vis[i][j]=1;
		for(int i=0;i<mx;++i)anses[tp++]='a';
	}
	while(L[np].size()){
		int mn=1000;
		for(auto c:L[np]){
			int x=c.first,y=c.second;
			if(x<n)mn=min(mn,(int)s[x+1][y]);
			if(y<n)mn=min(mn,(int)s[x][y+1]);
		}
		L[p].clear();
		if(mn==1000)break;
		anses[tp++]=mn;
		for(auto c:L[np]){
			int x=c.first,y=c.second;
			if(x<n&&s[x+1][y]==mn&&!vis[x+1][y])L[p].push_back(pii(x+1,y)),vis[x+1][y]=1;
			if(y<n&&s[x][y+1]==mn&&!vis[x][y+1])L[p].push_back(pii(x,y+1)),vis[x][y+1]=1;
		}
		swap(p,np);
	}
	for(int i=0;i<tp;++i)putchar(anses[i]);
}