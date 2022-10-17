#include<bits/stdc++.h>
#define N 100100
using namespace std;

int n,m,ans,cnt[N],num[N];
bool vis[N];

int main()
{
    int i,j,t;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
	scanf("%d",&num[i]);
	cnt[num[i]]++;
    }
    for(i=1;i<=m;i++)
    {
	cnt[num[i]]--;
	if(vis[num[i]]) continue;
	vis[num[i]]=1;
	if(num[i]>1 && !cnt[num[i]-1]) ans++;
	if(num[i]<n && !cnt[num[i]+1]) ans++;
    }
    for(i=1;i<=n;i++)
    {
	if(vis[i]) continue;
	ans++;
	if(i>1) ans++;
	if(i<n) ans++;
    }
    cout<<ans;
}