#include<bits/stdc++.h>
using namespace std;
const int x_[8]={0,1,1,1,0,-1,-1,-1};
const int y_[8]={1,1,0,-1,-1,-1,0,1};
const int N=32,M=32,K=1000010,D=N+M,C=N*M;
int n,m,s[N][M]={},to[N][M]={},x[K]={},y[K]={},tot=-1;
bool reverse_xy=false,ok[N][M]={};
inline int abs(int x)
{
	return x>=0 ? x : -x;
}
inline void add_start(int x_,int y_)
{
	++tot,x[tot]=x_,y[tot]=y_;
}
auto add_noswap=add_start;
inline void add_next(int x_,int y_) //Suppose that tot>=0 before.
{
	swap(s[x_][y_],s[x[tot]][y[tot]]);
	++tot,x[tot]=x_,y[tot]=y_;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&s[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&to[i][j]);
}
bool same()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]!=to[i][j])
				return false;
	return true;
}
bool impossible()
{
	int t[C]={};
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			++t[s[i][j]],--t[to[i][j]];
	for(int i=0;i<C;++i)
		if(t[i])
			return true;
	return false;
}
inline int dis(int x1,int y1,int x2,int y2)
{
	return max(abs(x2-x1),abs(y2-y1));
}
void solve(int x1,int y1) // make (x1,y1) correct and not be moved any more
{
	// find target position (x2,y2) for destination (x1,y1)
	int x2=0,y2=0,x3=x[tot],y3=y[tot];
	for(int i=1;i<=n && !x2;++i)
		for(int j=1;j<=m && !y2;++j)
			if(!ok[i][j] && s[i][j]==to[x1][y1] && (i!=x3 || j!=y3))
				x2=i,y2=j;

	// from current position (x3,y3) to neighboorhood of target position
	int mind=dis(x2,y2,x3,y3);
	while(mind>1)
	{
		int dir=rand()%8,nx3=x3+x_[dir],ny3=y3+y_[dir];
		int nowd=dis(x2,y2,nx3,ny3);
		if(ok[nx3][ny3] || nowd>=mind || (nx3==x2 && ny3==y2))
			continue;
		mind=nowd;
		x3=nx3,y3=ny3;
		add_next(x3,y3);
	}
	// move target position to (x1,y1)
	mind=dis(x1,y1,x2,y2)*D+dis(x1,y1,x3,y3);
	while(x2!=x1 || y2!=y1)
	{
		int dir=rand()%8,nx3=x3+x_[dir],ny3=y3+y_[dir],nx2=x2,ny2=y2;
		if(nx3==x2 && ny3==y2)
			nx2=x3,ny2=y3;
		if(ok[nx3][ny3] || abs(nx3-nx2)>1 || abs(ny3-ny2)>1)
			continue;
		int nowd=dis(x1,y1,nx2,ny2)*D+dis(x1,y1,nx3,ny3);
		if(nowd<=mind)
		{
			add_next(nx3,ny3);
			x2=nx2,y2=ny2,x3=nx3,y3=ny3;
			mind=nowd;
		}
	}
	ok[x1][y1]=true;
}
void work()
{
	if(impossible())
		return;
	if(n>m)
	{
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j)
				swap(s[i][j],s[j][i]),swap(to[i][j],to[j][i]);
		reverse_xy=true;
		swap(n,m);
	}
	if(same())
		return add_start(1,1);
	for(int i=0;i<=m+1;++i)
		ok[0][i]=ok[n+1][i]=true;
	for(int i=0;i<=n+1;++i)
		ok[i][0]=ok[i][m+1]=true;
	if(n==1)
	{
		int l=1,r=m;
		while(l<=m && s[1][l]==to[1][l])
			++l;
		while(r>=0 && s[1][r]==to[1][r])
			--r; // has guaranteed that s[] and to[] are different.
		bool flag=s[1][r]==to[1][l];
		for(int i=l;i<r && flag;++i)
			flag&=(s[1][i]==to[1][i+1]);
		if(flag)
			for(int i=r;i>=l;--i)
				add_noswap(1,i);
		flag=!flag && s[1][l]==to[1][r];
		for(int i=l;i<r && flag;++i)
			flag&=to[1][i]==s[1][i+1];
		if(flag)
			for(int i=l;i<=r;++i)
				add_noswap(1,i);
	}
	else
	{
		for(int i=1;i<=n && tot==-1;++i)
			for(int j=1;j<=m && tot==-1;++j)
				if(s[i][j]==to[n][m])
					add_start(i,j);
		for(int i=1;i<=n-2;++i)
			for(int j=1;j<=m;++j)
				solve(i,j);
		for(int j=1;j<m;++j)
			solve(n-1,j),solve(n,j);
        solve(n-1,m);
	}
}
void print()
{
	printf("%d\n",tot);
	for(int i=0;i<=tot;++i)
		if(reverse_xy)
			printf("%d %d\n",y[i],x[i]);
		else
			printf("%d %d\n",x[i],y[i]);
}
int main()
{	
	srand(time(0));
	init();
	work();
	print();
	return 0;
}