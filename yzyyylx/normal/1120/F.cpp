#include<bits/stdc++.h>
#define ll long long
#define N 100100
using namespace std;

ll n,c,d,ans,now,t[N],cz[N],to[N];
char str[2];

int main()
{
    ll i,j;
    cin>>n>>c>>d;
    for(i=1;i<=n;i++)
    {
	scanf("%lld%s",&t[i],str);
	cz[i]=(str[0]=='P'?1:2);
    }
    cin>>t[n+1];
//    for(i=1;i<=n;i++) cout<<t[i]<<" ";puts("");
    for(i=n;i>=1;i--)
    {
	if(cz[i]!=cz[i+1]) to[i]=t[i+1]-t[i];
	else to[i]=to[i+1]+t[i+1]-t[i];
    }
//    for(i=1;i<=n;i++) cout<<to[i]<<" ";return 0;
    ans=n*d;
    for(i=n;i>=1;i--)
    {
	now+=(t[i+1]-t[i])*c;
	if(cz[i]==cz[i+1]) now+=min(d,to[i+1]*c);
	ans=min(ans,now+(i-1)*d);
    }
    cout<<ans;
}