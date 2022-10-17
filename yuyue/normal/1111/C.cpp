#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll n,k,A,B;
int a[100000+1000];
 
ll dfs(int l,int r)
{ 
	int m=l+(r-l+1)/2;
	ll ans;
	int num=upper_bound(a+1,a+1+k,r)-lower_bound(a+1,a+1+k,l);
	if(num==0)return ans=A;
	else ans=B*num*(r-l+1);
	if(r-l>=1)ans=min(ans,dfs(l,m-1)+dfs(m,r));
	return ans;
}
 
int main()
{
//	freopen("input.in","r",stdin);
	cin>>n>>k>>A>>B;
	for(int i=1;i<=k;i++)cin>>a[i];
	sort(a+1,a+1+k);
	cout<<dfs(1,1<<n)<<endl;
	return 0;	
}