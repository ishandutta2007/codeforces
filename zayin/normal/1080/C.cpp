#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


LL x5,y5,x6,y6;

LL calc0(LL x1,LL y1,LL x2,LL y2)
{
	LL w=x2-x1+1,h=y2-y1+1,t=(w/2)*((h+1)/2)+((w+1)/2)*(h/2);
	
//	cout<<"calc0:"<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<w<<" "<<h<<" "<<t<<endl;
	if ((x1+y1)&1)
		return t;
	else
		return w*h-t;
}

LL calc1(LL x1,LL y1,LL x2,LL y2)
{
	LL w=x2-x1+1,h=y2-y1+1,t=(w/2)*((h+1)/2)+((w+1)/2)*(h/2);
	if ((x1+y1)&1)
		return w*h-t;
	else
		return t;
}

void intersect(LL x1,LL y1,LL x2,LL y2,LL x3,LL y3,LL x4,LL y4)
{
	if (x1>x3)
		swap(x1,x3),swap(x2,x4);
	if (y1>y3)
		swap(y1,y3),swap(y2,y4);
	
//	cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
	if (x1<=x3&&x4<=x2)
		x5=x3,x6=x4;
	else
		x5=x3,x6=x2;
	
//	cout<<y1<<" "<<y2<<" "<<y3<<" "<<y4<<endl;
	if (y1<=y3&&y4<=y2)
		y5=y3,y6=y4;
	else
		y5=y3,y6=y2;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		LL n,m;

		LL x1,y1,x2,y2;
		LL x3,y3,x4,y4;

		
		scanf("%lld%lld",&m,&n);
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		scanf("%lld%lld%lld%lld",&x3,&y3,&x4,&y4);
		intersect(x1,y1,x2,y2,x3,y3,x4,y4);
		
		LL ans=calc0(1,1,n,m)+calc1(x1,y1,x2,y2)-calc0(x3,y3,x4,y4);
		
//		cout<<ans<<" "<<calc0(1,1,n,m)<<" "<<calc1(x1,y1,x2,y2)<<" "<<calc0(x3,y3,x4,y4)\
		<<" "<<x5<<" "<<y5<<" "<<x6<<" "<<y6<<endl;
		if (x5<=x6&&y5<=y6)
			ans-=calc1(x5,y5,x6,y6);
		
		printf("%lld %lld\n",ans,n*m-ans);
	}
	return 0;
}