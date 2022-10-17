#include<bits/stdc++.h>
#define N 200100
using namespace std;

int n,ans,num[N],cnt[N];

int main()
{
    int i,j,p;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    for(i=1;i<=n;i++)
    {
	for(j=i+1;j<=n;j++)
	{
	    cnt[num[i]+num[j]]++;
	}
    }
    for(i=1;i<=200000;i++)
    {
	ans=max(ans,cnt[i]);
    }
    cout<<ans;
}