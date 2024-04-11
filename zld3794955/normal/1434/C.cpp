#include<bits/stdc++.h>
using namespace std;
const int D=6,N=100010;
int t,a,b,c,d;
long long bans;
void brute_force()
{
	long long ans=a,hp=a,t=1;
	for(int i=1;i<=c*10;++i)
	{
		hp-=t*b;
		if(i%d==0)
		{
			hp+=a;
			++t;
		}
		ans=max(ans,hp);
	}
	bans=ans;
	//cout<<ans<<endl;
}
void get_input()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	/*
	a=rand()%10+1;
	b=rand()%10+1;
	c=rand()%10+1;
	d=rand()%10+1;
	*/
	//cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
}
int main()
{
	srand(time(0));
	scanf("%d",&t);
	while(t--)
	{
		get_input();
		if(a>b*1ll*c)
		{
			puts("-1");
			continue;
		}
		if(a<=b)
		{
			printf("%d\n",a);
			continue;
		}
		//brute_force();
		long long e=a/b/d;
		long long t0=e*d,ans=(e+1ll)*a-(t0*1ll*(e+1)/2)*b;
		bans=ans;
		if(ans!=bans)
		{
			cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			cout<<e<<' '<<t0<<' '<<ans<<' '<<bans<<endl;
		}
		else
			printf("%I64d\n",ans);
	}
}