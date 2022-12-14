#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,dx,dy;
	int side()const{
		if(dy==0)	return dx>0?0:1;
		return dy>0?0:1;
	}
	bool operator<(const edge& rhs)const{
		if(side()!=rhs.side())	return side()<rhs.side();
		return (long long int) dx*rhs.dy>(long long int) dy*rhs.dx;
	}
};
vector<edge> e;
long long int dp[5][300][300];
int x[300],y[300];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
				e.push_back({i,j,x[j]-x[i],y[j]-y[i]});
	sort(e.begin(),e.end());
	for(int i=0;i<e.size();i++){
		int f=e[i].from,t=e[i].to;
		dp[0][f][t]=1;
		for(int j=0;j<4;j++)
			for(int k=0;k<n;k++)
				dp[j+1][k][t]+=dp[j][k][f];
	}
	long long int ans=0;
	for(int i=0;i<n;i++)
		ans+=dp[4][i][i];
	cout<<ans<<endl;
}