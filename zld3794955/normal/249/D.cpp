#include<bits/stdc++.h>
using namespace std;
const int N=100100;
typedef long long ll;
struct star
{
	ll x,y;
}s[N]={};
int n,a,b,c,d,len=0,tot=0;
ll f[N]={};
int main()
{
	scanf("%d\n%d/%d %d/%d",&n,&a,&b,&c,&d);
	for(int i=1,x,y;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		s[++tot]={(ll)y*b-(ll)a*x,(ll)c*x-(ll)y*d};
		tot-=(s[tot].x<=0 || s[tot].y<=0);
	}
	n=tot;
	sort(s+1,s+n+1,[](const star &s1,const star &s2)
					{return s1.x<s2.x || (s1.x==s2.x && s1.y>s2.y);});
	for(int i=1;i<=n;++i)
		if(s[i].y>f[len])
			f[++len]=s[i].y;
		else
			f[lower_bound(f+1,f+len+1,s[i].y)-f]=s[i].y;
	printf("%d\n",len);
	return 0;
}