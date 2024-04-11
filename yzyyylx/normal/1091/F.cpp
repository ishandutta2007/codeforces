#include<bits/stdc++.h>
#define ll long long
#define N 100100
using namespace std;

ll n,ans,last=1,num[N],qz[N],to[N],st[N],need[N],fly[N];
char str[N];

int main()
{
    ll i,j,p,q,t,tmp;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%lld",&num[i]),num[i]*=2,qz[i]=qz[i-1]+num[i],st[i]=qz[i]-num[i];
    st[n+1]=qz[n];
    scanf("%s",str+1);
    for(i=q=1,p=0;i<=n;i++)
    {
	if(str[i]=='L')
	{
	    if(num[i]>p)
	    {
		last=i+1;
		t=num[i]-p;
		p=0;
		if(str[q]=='G') ans+=t*5;
		if(str[q]=='W') ans+=t*3;
	    }
	    else p-=num[i];
	    ans+=num[i];
	}
	else if(str[i]=='W')
	{
	    if(q==1) q=i;
	    p+=num[i];
	    ans+=num[i]*3;
	}
	else
	{
	    p+=num[i];
	    ans+=num[i]*5;
	}
    }
//    cout<<ans/2<<" "<<p/2;return 0;
    for(i=n;i>=last;i--)
    {
	if(str[i]=='L') need[i-1]=max(num[i],need[i]+num[i]);
	else need[i-1]=max(0ll,need[i]-num[i]);
    }
    for(i=last,t=0;i<=n;i++)
    {
	if(str[i]=='L') t-=num[i];
	else if(str[i]=='W') t+=num[i];
	else
	{
	    t+=num[i];
	    tmp=min(num[i]*2,t-need[i]);
	    if(tmp<=p)
	    {
		p-=tmp;
		fly[i]=tmp/2;
		ans-=tmp*2;
		t-=tmp;
	    }
	    else
	    {
		ans-=p*2;
		cout<<ans/2;
		return 0;
	    }
	}
    }
    ans-=p;
    cout<<ans/2;
}