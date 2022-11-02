#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=100010;
struct point
{
	int x,y;
};
struct cmpx
{
	bool operator() (const point &p1,const point &p2)
	{
		return p1.x<p2.x || (p1.x==p2.x && p1.y<p2.y);
	}
};
struct cmpy
{
	bool operator() (const point &p1,const point &p2)
	{
		return p1.y<p2.y || (p1.y==p2.y && p1.x<p2.x);
	}
};
typedef set<point,cmpx> xlist;
typedef set<point,cmpy> ylist;
int n,ans=0;
xlist allx;
ylist ally;
void init()
{
	scanf("%d",&n);
	for(int i=1,x=0,y=0;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		allx.insert((point){x,y});
		ally.insert((point){x,y});
	}
}
int tot=0;
void work(xlist &xl,ylist &yl)
{
	xlist newx;
	ylist newy;
	xlist::iterator sx=xl.begin(),ex=--xl.end();
	ylist::iterator sy=yl.begin(),ey=--yl.end();
	/*
	for(xlist::iterator it=xl.begin();it!=xl.end();++it)
		cout<<it->x<<' '<<it->y<<endl;
	cout<<"--------------------------------"<<endl;
	for(ylist::iterator it=yl.begin();it!=yl.end();++it)
		cout<<it->x<<' '<<it->y<<endl;
	cout<<"--------------------------------"<<endl;
	*/
	int flag=0;
	while(sx!=ex || sy!=ey)
	{
		if(flag==3)
		{
			flag=0;
			if(sx==ex)
				continue;
			xlist::iterator last=sx++;
			if(last->x < sx->x-1)
			{
				for(xlist::iterator it=xl.begin();it!=sx;++it)
				{
					point tmp=*it;
					newx.insert(tmp);
					newy.insert(tmp);
					yl.erase(tmp);
				}
				xl.erase(xl.begin(),sx);
				work(newx,newy);
				work(xl,yl);
				return;
			}
		}
		else if(flag==0)
		{
			flag=1;
			if(sx==ex)
				continue;
			xlist::iterator next=ex--;
			if(next->x > ex->x+1)
			{
				for(xlist::iterator it=next;it!=xl.end();++it)
				{
					point tmp=*it;
					newx.insert(tmp);
					newy.insert(tmp);
					yl.erase(tmp);
				}
				xl.erase(next,xl.end());
				work(newx,newy);
				work(xl,yl);
				return;
			}
		}
		else if(flag==1)
		{
			flag=2;
			if(sy==ey)
				continue;
			ylist::iterator last=sy++;
			if(last->y < sy->y-1)
			{
				for(ylist::iterator it=yl.begin();it!=sy;++it)
				{
					point tmp=*it;
					newx.insert(tmp);
					newy.insert(tmp);
					xl.erase(tmp);
				}
				yl.erase(yl.begin(),sy);
				work(newx,newy);
				work(xl,yl);
				return;
			}
		}
		else if(flag==2)
		{
			flag=3;
			if(sy==ey)
				continue;
			ylist::iterator next=ey--;
			if(next->y > ey->y+1)
			{
				for(ylist::iterator it=next;it!=yl.end();++it)
				{
					point tmp=*it;
					newx.insert(tmp);
					newy.insert(tmp);
					xl.erase(tmp);
				}
				yl.erase(next,yl.end());
				work(newx,newy);
				work(xl,yl);
				return;
			}
		}
	}
	++ans;
}
int main()
{	/*
	freopen("tmp.txt","w",stdout);
	cout<<100000<<endl;
	for(int i=2;i<=200000;i+=2)
		cout<<0<<' '<<i<<endl;
	*/
	//freopen("tmp.txt","r",stdin);
	init();
	work(allx,ally);
	printf("%d\n",ans);//*/
	return 0;
}