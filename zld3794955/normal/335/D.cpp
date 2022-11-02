#include<bits/stdc++.h>
using namespace std;
const int N=100010,V=3030;
struct rectangle
{
	int x1,y1,x2,y2;
}t[N]={};
struct point
{
	int x,y,l;
}p[N<<2]={};
bool point_sort_cmp(const point &p1,const point &p2)
{
	return p1.x-p1.y<p2.x-p2.y || (p1.x-p1.y==p2.x-p2.y && p1.x<p2.x);
}
bool point_unique_cmp(const point &p1,const point &p2)
{
	return p1.x==p2.x && p1.y==p2.y;
}
int n,m,f[V][V]={},s[V][V]={},now[N<<2]={},top=0,lx=0,ly=0,rx=0,ry=0;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d%d",&t[i].x1,&t[i].y1,&t[i].x2,&t[i].y2);
		++t[i].x1,++t[i].y1,++t[i].x2,++t[i].y2;
		p[++m]={t[i].x1,t[i].y1,V};
		p[++m]={t[i].x2,t[i].y2,V};
		p[++m]={t[i].x1,t[i].y2,V};
		p[++m]={t[i].x2,t[i].y1,V};
	}
}
void get_border()
{
	for(int i=0;i<V;++i)
		fill(f[i],f[i]+V,0);
	for(int i=1;i<=n;++i)
		f[t[i].x1][t[i].y1]=t[i].x2-t[i].x1;
	for(int i=V-1;i>=1;--i)
		for(int j=V-1;j>=1;--j)
			f[i][j]=f[i][j]+f[i+f[i][j]][j];
	for(int i=1;i<=m;++i)
		p[i].l=min(p[i].l,f[p[i].x][p[i].y]);
	
	for(int i=0;i<V;++i)
		fill(f[i],f[i]+V,0);
	for(int i=1;i<=n;++i)
		f[t[i].x1][t[i].y1]=t[i].y2-t[i].y1;
	for(int i=V-1;i>=1;--i)
		for(int j=V-1;j>=1;--j)
			f[i][j]=f[i][j]+f[i][j+f[i][j]];
	for(int i=1;i<=m;++i)
		p[i].l=min(p[i].l,f[p[i].x][p[i].y]);
}
void get_s()
{
	for(int i=1;i<=n;++i)
		s[t[i].x2][t[i].y2]+=(t[i].x2-t[i].x1)*(t[i].y2-t[i].y1);
	for(int i=1;i<V;++i)
		for(int j=1;j<V;++j)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
}
bool check(int x1,int y1,int x2,int y2)
{
	return x2-x1==y2-y1 && s[x2][y2]-s[x2][y1]-s[x1][y2]+s[x1][y1]==(x2-x1)*(y2-y1);
}
void work()
{
	sort(p+1,p+m+1,point_sort_cmp);
	m=unique(p+1,p+m+1,point_unique_cmp)-p-1;
	now[++top]=1;
	for(int i=2;i<=m;++i)
	{
		if(p[i].x-p[i].y != p[now[top]].x-p[now[top]].y)
			now[top=1]=i;
		else
		{
			for(int j=now[top]; top; j=now[--top])
				if(p[j].x+p[j].l>=p[i].x)
					break;
			if(top && check(p[now[top]].x,p[now[top]].y,p[i].x,p[i].y))
			{
				lx=p[now[top]].x, rx=p[i].x, ly=p[now[top]].y, ry=p[i].y;
				break;
			}
			now[++top]=i;
		}
	}
	if(lx && ly && rx && ry)
	{
		vector<int> ans;
		for(int i=1;i<=n;++i)
			if(lx<=t[i].x1 && t[i].x2<=rx && ly<=t[i].y1 && t[i].y2<=ry)
				ans.push_back(i);
		printf("YES %u\n",ans.size());
		for(auto p:ans)
			printf("%d ",p);
		printf("\n");
	}
	else
		puts("NO");
}
int main()
{
	init();
	get_border();
	get_s();
	work();
	return 0;
}