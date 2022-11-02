#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int M=440,S=600,V=300,L=1000000,x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
const int DX=270,DY=270;
const char dir[4]={'U','R','D','L'};
int m,sx,sy,ex,ey,tot=0;
pair<int,int> p[M];
char ans[L]={};
bool v[S][S]={},tree[S][S]={};
bool dfs1(int x,int y)
{
	if(x>DX || y>DY || x<-DX || y<-DY || v[x+V][y+V])
		return false; 
	if(x==DX && y==DY)
		return true;
	v[x+V][y+V]=true;
	for(int k=0;k<4;++k)
	{
		ans[++tot]=dir[k];
		if(dfs1(x+x_[k],y+y_[k]))
			return true;
		--tot;
	}
	return false;
}
void init()
{
	cin>>sx>>sy>>ex>>ey>>m;
	for(int i=1,x,y;i<=m;++i)
	{
		cin>>x>>y;
		tree[x+V][y+V]=true;
		p[i]={x,y};
	}
}
int move_out()
{
	int last=tot;
	for(int i=0;i<S;++i)
		copy(tree[i],tree[i]+S,v[i]);
	if(dfs1(sx,sy))
	{
		sx=DX,sy=DY;
		for(int i=last+1;i<=tot;++i)
		{
			int k=ans[i]=='U' ? 0 : ans[i]=='R' ? 1 : ans[i]=='D' ? 2 : 3;
			if(!tree[ex+x_[k]+V][ey+y_[k]+V])
				ex+=x_[k],ey+=y_[k];
		}
		last=tot;
		for(int i=0;i<S;++i)
			copy(tree[i],tree[i]+S,v[i]);
		if(dfs1(ex,ey))
		{
			for(int i=last+1;i<=tot;++i)
			{
				int k=ans[i]=='U' ? 0 : ans[i]=='R' ? 1 : ans[i]=='D' ? 2 : 3;
				sx+=x_[k],sy+=y_[k],ex+=x_[k],ey+=y_[k];
			}
			return 2;
		}
		else
			if(ex>DX || ey>DY)
			{
				for(int i=1;i<=DX;++i)
					ans[++tot]='U',ans[++tot]='R',++sx,++sy,++ex,++ey;
				return 2;
			}
			else
				return 1;
	}
	else
	{
		for(int i=0;i<S;++i)
			copy(tree[i],tree[i]+S,v[i]);
		return dfs1(ex,ey);
	}
}
void make_samex()
{
	if(ex<=sx)
	{
		int pos=1;
		for(int i=2;i<=m;++i)
			if(p[i].first>p[pos].first)
				pos=i;
		for(int i=p[pos].second;i<ey;++i)
			ans[++tot]='D';
		sy-=ey-p[pos].second;
		ey-=ey-p[pos].second;
		//cout<<"sx="<<sx<<" sy="<<sy<<" ex="<<ex<<" ey="<<ey<<endl;
		for(int i=p[pos].first+1;i<sx;++i)
			ans[++tot]='L';
		sx=ex=p[pos].first+1;
	}
	else
	{
		int pos=1;
		for(int i=2;i<=m;++i)
			if(p[i].first<p[pos].first)
				pos=i;
		for(int i=p[pos].first-1;i<ex;++i)
			ans[++tot]='L';
		sx-=ex-p[pos].first+1;
		ex-=ex-p[pos].first+1;
		for(int i=p[pos].second;i<ey;++i)
			ans[++tot]='D';
		sy-=ey-p[pos].second;
		ey-=ey-p[pos].second;
		for(int i=sx;i<p[pos].first-1;++i)
			ans[++tot]='R';
		sx=ex=p[pos].first-1;
	}
	for(int i=1;i<=DY+DY;++i)
		ans[++tot]='U',++sy,++ey;
	for(int i=1;i<=DX+DX;++i)
		ans[++tot]='R',++sx,++ex; 
}
void make_samey()
{
	if(ey<=sy)
	{
		int pos=1;
		for(int i=2;i<=m;++i)
			if(p[i].second>p[pos].second)
				pos=i;
		for(int i=p[pos].first; i<ex; ++i)
			ans[++tot]='L';
		sx-=ex-p[pos].first;
		ex-=ex-p[pos].first;
		for(int i=p[pos].second+1; i<sy; ++i)
			ans[++tot]='D';
		sy=ey=p[pos].second+1;
	}
	else
	{
		int pos=1;
		for(int i=2;i<=m;++i)
			if(p[i].second<p[pos].second)
				pos=i;
		for(int i=p[pos].second-1;i<ey;++i)
			ans[++tot]='D';
		sy-=ey-p[pos].second+1;
		ey-=ey-p[pos].second+1;
		for(int i=p[pos].first;i<ex;++i)
			ans[++tot]='L';
		sx-=ex-p[pos].first;
		ex-=ex-p[pos].first;
		for(int i=sy;i<p[pos].second-1;++i)
			ans[++tot]='U';
		sy=ey=p[pos].second-1;
	}
	puts(ans+1);
}
bool dfs(int x,int y)
{
	if(x==ex && y==ey)
		return true;
	if(v[x+V][y+V])
		return false;
	v[x+V][y+V]=true;
	for(int k=0;k<4;++k)
	{
		ans[++tot]=dir[k];
		if(dfs(x+x_[k],y+y_[k]))
			return true;
		--tot;
	}
	return false;
}
void follow()
{
	tot=0;
	for(int i=0;i<S;++i)
		copy(tree[i],tree[i]+S,v[i]);
	if(!dfs(sx,sy))
	{
		puts("-1");
		return;
	}
	for(int i=1;i<=tot;++i)
	{
		putchar(ans[i]);
		int k=ans[i]=='U' ? 0 : ans[i]=='R' ? 1 : ans[i]=='D' ? 2 : 3;
		sx+=x_[k],sy+=y_[k];
		if(!tree[ex+x_[k]+V][ey+y_[k]+V])
			ex+=x_[k],ey+=y_[k],ans[++tot]=ans[i];
		if(sx==ex && sy==ey)
			break;
	}
	putchar('\n');
}
int main()
{
	init();
	if(m==0)
	{
		puts("-1");
		return 0;
	}
	int tmp=move_out();
	if(tmp==2)
		make_samex(),make_samey();
	else
		if(tmp==1)
			puts("-1");
		else
			follow();
	return 0;
}