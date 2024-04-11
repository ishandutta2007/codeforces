#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],cnt[N];ll sum[N];
int get(int x)
{
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]==x)continue;
		else if(a[i]-a[i-1]==x+1)a[i]--,ans++;
		else if(a[i]-a[i-1]==x-1)a[i]++,ans++;
		else return 1e9;
	}
	return ans;
}
int check(int x)
{
	int ans=1e9,tmp;bool flag=0;
	for(int i=1;i<=n;i++)a[i]=b[i];
	a[1]--;ans=min(ans,get(x)+1);
	for(int i=1;i<=n;i++)a[i]=b[i];
		ans=min(ans,get(x));
	for(int i=1;i<=n;i++)a[i]=b[i];
	a[1]++;ans=min(ans,get(x)+1);
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	int ans=b[2]-b[1],res=1e9;
	for(int i=ans-2;i<=ans+2;i++)
		res=min(res,check(i));
	res==1e9?printf("-1"):printf("%d\n",res);		
}