#include<bits/stdc++.h>
using namespace std;
const int N=100100,P=363000;
struct event
{
	int type,x,y;
}q[P*4+N]={};
int n,m,a[10]={},vx[N]={},vy[N]={},t[N]={},ans[P*4]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",vx+i,vy+i);
		q[++m]={0,vx[i],vy[i]};
	}
	sort(vx+1,vx+n+1);
	sort(vy+1,vy+n+1);
	for(int i=1;i<=m;++i)
	{
		q[i].x=lower_bound(vx+1,vx+n+1,q[i].x)-vx;
		q[i].y=lower_bound(vy+1,vy+n+1,q[i].y)-vy;
	}
	//cout<<endl;
	//for(int i=1;i<=m;++i)
	//	cout<<q[i].x<<' '<<q[i].y<<endl;
	for(int i=1;i<=9;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+10); 
	do
	{
		int x1=a[1]+a[4]+a[7],x2=n-a[3]-a[6]-a[9];
		int y1=a[7]+a[8]+a[9],y2=n-a[1]-a[2]-a[3];
		if(vx[x1]==vx[x1+1] || vx[x2]==vx[x2+1] || vy[y1]==vy[y1+1] || vy[y2]==vy[y2+1])
			continue;
		++m,q[m]={m-n,x1,y1}; ++m,q[m]={m-n,x1,y2};
		++m,q[m]={m-n,x2,y1}; ++m,q[m]={m-n,x2,y2};
	}while(next_permutation(a+1,a+10));
}
void work()
{
	sort(q+1,q+m+1,[](const event &e1,const event &e2)
					{return e1.x<e2.x || (e1.x==e2.x && e1.type<e2.type);});
	for(int i=1;i<=m;++i)
		if(q[i].type)
			for(int j=q[i].y; j; j-=j&(-j))
				ans[q[i].type]+=t[j];
		else
			for(int j=q[i].y;j<=n;j+=j&(-j))
				++t[j];
	//for(int i=1;i<=m;++i)
	//	cout<<q[i].type<<' '<<q[i].x<<' '<<q[i].y<<' '<<ans[q[i].type]<<endl;
	int pos=1;
	do
	{
		int x1=a[1]+a[4]+a[7],x2=n-a[3]-a[6]-a[9];
		int y1=a[7]+a[8]+a[9],y2=n-a[1]-a[2]-a[3];
		if(vx[x1]==vx[x1+1] || vx[x2]==vx[x2+1] || vy[y1]==vy[y1+1] || vy[y2]==vy[y2+1])
			continue;
		if(ans[pos]==a[7] && ans[pos+3]==a[4]+a[5]+a[7]+a[8]
		&& ans[pos+1]==a[4]+a[7] && ans[pos+2]==a[7]+a[8])
		{
			printf("%.10f %.10f\n%.10f %.10f\n",vx[x1]+0.5,vx[x2]+0.5,vy[y1]+0.5,vy[y2]+0.5);
			return;
		}
		pos+=4;
	}while(next_permutation(a+1,a+10));
	puts("-1");
}
int main()
{
	init();
	work();
	return 0;
}