#include<bits/stdc++.h>
#define ll long long
#define se second
#define N 1010
#define M 1000000007
using namespace std;

ll m,n,ans=1,si[N][N],sum[N];
char str[N][N];
map<ll,ll>cnt;
map<ll,ll>::iterator it;

int main()
{
    ll i,j,t;
    cin>>m>>n;
    for(i=1;i<=n;i++) scanf("%s",str[i]+1);
    si[0][0]=1;
    for(i=1;i<=m;i++)
    {
	for(j=1;j<=i;j++)
	{
	    si[i][j]=(si[i-1][j-1]+si[i-1][j]*j)%M;
	    sum[i]=(sum[i]+si[i][j])%M;
	}
    }
    for(i=1;i<=m;i++)
    {
	t=0;
	for(j=1;j<=n;j++)
	{
	    t=t*2+str[j][i]-'0';
	}
	cnt[t]++;
    }
    for(it=cnt.begin();it!=cnt.end();it++)
    {
	t=(*it).se;
	ans=ans*sum[t]%M;
    }
    cout<<ans;
}