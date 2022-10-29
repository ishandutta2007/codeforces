#include<bits/stdc++.h>
#define maxn 10010
using namespace std;
typedef pair<int,int> par;
int n,l,r,sum,dp[maxn];
par p[maxn];
int isin(int l,int r,int x){
	return x>=l&&x<=r;
}
int main(){
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n;++i)scanf("%d",&p[i].first);
	for(int i=1;i<=n;++i)scanf("%d",&p[i].second);
	for(int i=1;i<=n;++i)sum+=p[i].first;
	l=sum-l,r=sum-r,swap(l,r);
	for(int i=1;i<=sum;++i)dp[i]=-1000000007;
	sort(p+1,p+n+1,[](par p,par q){return p.second==q.second?p.first>q.first:p.second<q.second;});
	for(int i=1;i<=n;++i)
		for(int j=sum-p[i].first;j>=0;--j)
			dp[j+p[i].first]=max(dp[j+p[i].first],dp[j]+p[i].second*isin(l,r,j+p[i].first));
	printf("%d",*max_element(dp,dp+sum+1));
}