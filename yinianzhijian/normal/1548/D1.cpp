#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc()
{
	static char buf[1<<16],*s,*t;
	if(s==t)
	{
		t=(s=buf)+fread(buf,1,1<<16,stdin);
		if(s==t)return EOF;
	}
	return *s++;
}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=6000+5;
int n,t[4];//00 01 10 11
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
struct node
{
	int a,b;
}e[xx];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		e[i].a=read(),e[i].b=read();
		e[i].a/=2,e[i].b/=2;
		t[(e[i].a&1)*2+(e[i].b&1)]++;
	}
//	cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<" "<<t[3]<<"\n";
	ll ans=0,res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			t[(e[i].a&1)*2+(e[i].b&1)]--;
			t[(e[j].a&1)*2+(e[j].b&1)]--;
			int l1=gcd(abs(e[i].a-e[j].a),abs(e[i].b-e[j].b));
//			for(int k=1;k<=n;k++)
//			{
//				if(i==k||j==k)continue;
//				int l2=gcd(abs(e[i].a-e[k].a),abs(e[i].b-e[k].b));
//				int l3=gcd(abs(e[j].a-e[k].a),abs(e[j].b-e[k].b));
//				if((l1+l2+l3)&1)continue;
//				res++;
//			}
			for(int k=0;k<4;k++)
			{
				int a=k/2,b=k&1;
				int t1=(a+(e[i].a&1))&1,t2=(b+(e[i].b&1))&1;
				int t3=(a+(e[j].a&1))&1,t4=(b+(e[j].b&1))&1;
				int X=t1|t2,Y=t3|t4;
//				cout<<j<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<(e[j].a&1)<<" "<<(e[j].b&1)<<"\n";
				if((X+Y+(l1&1))%2==0)ans+=t[k];
			}
//			cout<<res<<" "<<ans<<" "<<i<<" sss "<<j<<" "<<l1<<'\n';
//			if(res)
//			return 0;
			t[(e[i].a&1)*2+(e[i].b&1)]++;
			t[(e[j].a&1)*2+(e[j].b&1)]++;
		}
	}
	cout<<ans/6<<"\n";
	return 0;
}