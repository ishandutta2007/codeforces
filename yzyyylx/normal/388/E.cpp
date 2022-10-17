#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define db long double
#define eps 1e-8
#define N 1010
using namespace std;

int n,ans,an,cnt;
db ti[N];
struct Xn
{
	db x,y,vx,vy;
} xn[N],tmp;
struct Dn
{
	db x,y;
} jd[N];

inline db cj(Dn u,Dn v)
{
	return u.x*v.y-u.y*v.x;
}

inline bool cmp(const Dn &u,const Dn &v)
{
	if(fabs(cj(u,v))<eps)
	{
		if(fabs(u.x-v.x)>eps) return u.x<v.x;
		return u.y<v.y;
	}
	return cj(u,v)<0;
}

int main()
{
	int i,j;
	db a,b,c,d,e,f,t;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		scanf("%Lf%Lf%Lf%Lf%Lf%Lf",&c,&a,&b,&f,&d,&e);
		t=f-c;
		xn[i].vx=(d-a)/t;
		xn[i].vy=(e-b)/t;
		xn[i].x=a-xn[i].vx*c;
		xn[i].y=b-xn[i].vy*c;
	}
	for(i=1; i<=n; i++)
	{
		cnt=0;
		for(j=1; j<=n; j++)
		{
			if(i==j) continue;
			tmp.x=xn[i].x-xn[j].x;
			tmp.y=xn[i].y-xn[j].y;
			tmp.vx=xn[i].vx-xn[j].vx;
			tmp.vy=xn[i].vy-xn[j].vy;
			t=fabs(tmp.vx)>eps?tmp.x/tmp.vx:fabs(tmp.vy)>eps?tmp.y/tmp.vy:0;
			if(fabs(tmp.vx*t-tmp.x)<eps&&fabs(tmp.vy*t-tmp.y)<eps)
			{
				ti[++cnt]=t;
				jd[cnt].x=tmp.vx;
				jd[cnt].y=tmp.vy;
//				cout<<i<<" "<<j<<endl;
			}
		}
		if(!cnt) continue;
//		cout<<" "<<i<<" "<<cnt<<endl;
		sort(ti+1,ti+cnt+1);
		an=1;
		for(j=2; j<=cnt; j++)
		{
			if(fabs(ti[j]-ti[j-1])<eps) an++;
			else
			{
				ans=max(ans,an);
				an=1;
			}
		}
		ans=max(an,ans);

		sort(jd+1,jd+cnt+1,cmp);
		an=1;
		for(j=2; j<=cnt; j++)
		{
			if(fabs(cj(jd[j],jd[j-1]))<eps)
			{
				if(fabs(jd[j].x-jd[j-1].x)>eps || fabs(jd[j].y-jd[j-1].y)>eps) an++;
			}
			else
			{
				ans=max(ans,an);
				an=1;
			}
		}
		ans=max(ans,an);
	}
	cout<<ans+1;
}