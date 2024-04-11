#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

P pos[SIZE];//counter clockwise
ll sum[SIZE],px[SIZE],py[SIZE];
ll imos[SIZE];

ll cross(P p,P q)
{
	return p.first*q.second-p.second*q.first;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		pos[n-i-1]=P(x,y);//counter clockwise
	}
	for(int i=n;i<2*n;i++) pos[i]=pos[i-n];
	ll all=0;
	for(int i=0;i<n;i++) all+=cross(pos[i],pos[i+1]);
	for(int i=0;i<n;i++)
	{
		sum[i]=0;
		if(i>0) sum[i]=sum[i-1]+cross(pos[i-1],pos[i]);
	}
	for(int i=0;i<2*n;i++)
	{
		px[i]=pos[i].first;
		py[i]=pos[i].second;
		if(px[i]<0) px[i]+=MOD;
		if(py[i]<0) py[i]+=MOD;
		if(i>0)
		{
			px[i]+=px[i-1];
			py[i]+=py[i-1];
			if(px[i]>=MOD) px[i]-=MOD;
			if(py[i]>=MOD) py[i]-=MOD;
		}
	}
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		int l=1,r=n-1;
		while(r-l>1)
		{
			int m=(l+r)/2;
			ll gt=cross(pos[i+m],pos[i])-sum[i];
			if(i+m<n) gt+=sum[i+m];
			else gt+=all+sum[i+m-n];
			if(gt<=(all+1)/2&&(gt*2<all||(gt*2==all&&i+m<n))) l=m;
			else r=m;
		}
		//i+2`i+l 
		//i+2`i+lKi <- aimos
		//i+1  l-1 , i+2`i+l  l-1,l-2,...,1 
		//i+2`i+l a +1 , i+1 a -(l-1)
		imos[i]-=l-1;
		imos[i+1]+=l-1;
		imos[i+2]+=1;
		imos[i+l+1]-=1;
		//pO
		//firstseconda
		ll f=px[i+l]-px[i+1],s=py[i+l]-py[i+1];
		if(f<0) f+=MOD;
		if(s<0) s+=MOD;
		ll t1=pos[i].second,t2=pos[i].first;
		if(t1<0) t1+=MOD;
		if(t2<0) t2+=MOD;
		ret+=(f*t1%MOD)-(s*t2%MOD);
		if(ret<0) ret+=MOD;
		else if(ret>=MOD) ret-=MOD;
	}
	for(int i=1;i<2*n;i++) imos[i]+=imos[i-1];
	for(int i=0;i<2*n;i++)
	{
		if(imos[i]<0) imos[i]=MOD-(llabs(imos[i])%MOD);
		imos[i]%=MOD;
	}
	for(int i=2*n-2;i>=0;i--)
	{
		imos[i]+=imos[i+1];
		if(imos[i]>=MOD) imos[i]-=MOD;
	}
	for(int i=1;i<2*n;i++)
	{
		ll vl=cross(pos[i-1],pos[i]);
		if(vl<0) vl=MOD-(llabs(vl)%MOD);
		vl%=MOD;
		ll vt=imos[i];
		if(vt<0) vt+=MOD;
		ret+=vl*vt%MOD;
		if(ret>=MOD) ret-=MOD;
	}
	//printf("%lld\n",ret);
	//ret : v
	ll nm=(ll) n*(ll) (n-3)/2;
	nm%=MOD;
	nm*=(all%MOD);
	nm%=MOD;
	nm-=2LL*ret%MOD;
	if(nm<0) nm+=MOD;
	printf("%lld\n",nm);
	return 0;
}