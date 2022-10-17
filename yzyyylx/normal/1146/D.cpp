#include<bits/stdc++.h>
#define ll long long
#define N 200100
using namespace std;

ll n,a,b,f,g,ans,num[N],qz[N],top;

inline ll qh(ll u,ll v){return (u+v)*(v-u+1)/2;}
inline ll gcd(ll u,ll v)
{
    for(;v;)
    {
	u%=v;
	swap(u,v);
    }
    return u;
}

int main()
{
    ll i,j,p,q,t;
    cin>>n>>a>>b;
    g=gcd(a,b);
    num[top=1]=0;
    for(i=0;;)
    {
	i+=a;
	num[++top]=i;
	for(;i>=b;)
	{
	    i-=b;
	    if(!i) break;
	    num[++top]=i;
	}
	if(!i) break;
    }
//    for(i=1;i<=top;i++) cout<<num[i]<<" ";puts("");
    t=0;
    for(i=1;i<=top;i++)
    {
	t=max(t,num[i]);
	qz[t]++;
    }
    t=0;
    for(i=0;i<=min(a+b-1,n);i++)
    {
	t+=qz[i];
	ans+=t;
    }
    if(n<a+b)
    {
	cout<<ans;
	return 0;
    }
//    cout<<" "<<ans<<endl;
    if((a+b)/g==n/g)
    {
	for(i=n;i<=a+b;i++)
	    ans+=i/g+1;
	cout<<ans;
	return 0;
    }
    p=((a+b)/g+1)*g;ans+=(p-(a+b))*((a+b)/g+1);
    q=n/g*g-1;ans+=(n-q)*(n/g+1);
//    cout<<p<<" "<<q<<" "<<ans<<endl;
    ans+=qh(p/g+1,q/g+1)*g;
    cout<<ans;
}