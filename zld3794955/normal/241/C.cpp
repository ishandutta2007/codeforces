#include<bits/stdc++.h>
using namespace std;
const int N=105,H=100;
struct seg
{
	int y,xl,xr,score,num;
}t[N*H/2]={};
int n,m,hl,hr,s[N]={},h[N]={},a[N]={},b[N]={},ans=0;
void init()
{
	cin>>hl>>hr>>n;
	char ch;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i]>>ch>>a[i]>>b[i];
		h[i]=ch=='T' ? H : 0;
	}
}
int sgn(long long x)
{
	return x>0 ? 1 : x<0 ? -1 : 0;
}
int calc(long long sx,long long sy,long long ex,long long ey)
{
	//cout<<"sx="<<sx<<" sy="<<sy<<" ex="<<ex<<" ey="<<ey<<endl;
	long long A=sy-ey,B=ex-sx,C=sx*ey-sy*ex;
	int sum=0;
	bool v[N]={};
	for(int h=(sy/H+1)*H; h<ey; h+=H)
	{
		bool flag=false;
		//cout<<"h="<<h<<endl;
		for(int i=1;i<=m;++i)
			if(t[i].y==h && sgn(A*t[i].xl+B*t[i].y+C)*sgn(A*t[i].xr+B*t[i].y+C)<=0)
			{
				if(v[t[i].num])
					return 0;
				v[t[i].num]=true;
				sum+=t[i].score;
				flag=true;
			}
		//cout<<"sum="<<sum<<endl;
		if(!flag)
			return 0;
	}
	return sum;
}
void work()
{
	m=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=n/2;++j)
			t[++m]={h[i]+j*2*H,a[i],b[i],s[i],i};
	int nl=hr;
	for(int j=0;j<=n;++j)
	{
		ans=max(ans,calc(0,hl,100000,nl));
		nl+=(j%2==0 ? (H-hr)*2 : hr*2);
	}
}
void reverse()
{
	for(int i=1;i<=n;++i)
		h[i]=h[i]==H ? 0 : H;
	hl=H-hl,hr=H-hr;
}
int main()
{
	init();
	work();
	reverse();
	work();
	printf("%d\n",ans);
	return 0;
}