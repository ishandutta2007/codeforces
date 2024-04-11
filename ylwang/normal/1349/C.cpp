#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace yspm{
	inline int read()
	{
		int res=0,f=1; char k;
		while(!isdigit(k=getchar())) if(k=='-') f=-1;
		while(isdigit(k)) res=res*10+k-'0',k=getchar();
		return res*f;
	}
	const int N=1010;
	const int inf=1e15+10;
	bool fl[N][N],g[N][N];
	int n,m,f[N][N],T;
	char s;
	inline bool in(int x,int y)
	{
		return x>=1&&x<=n&&y>=1&&y<=m;
	}
	int dx[4]={1,0,-1,0};
	int dy[4]={0,1,0,-1};
	queue<pair<int,int> > q; 
	inline void work()
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				for(int k=0;k<4;++k)
				{
					int tx=dx[k]+i,ty=dy[k]+j;
					if(in(tx,ty)) 
					{
						if(g[i][j]==g[tx][ty]) 
						{
							fl[i][j]=1;
							f[i][j]=0;
							q.push(make_pair(i,j));
							break;
						}
					}
				}	
			}
		}
		while(!q.empty())
		{
			pair<int,int> fr=q.front(); q.pop();
			int x=fr.first,y=fr.second;
			for(int i=0;i<4;++i)
			{
				int tx=x+dx[i],ty=y+dy[i];
				if(fl[tx][ty]||!in(tx,ty)) continue;
				f[tx][ty]=f[x][y]+1; fl[tx][ty]=1;
				q.push(make_pair(tx,ty));
			}
		} return ;
	}
	signed main()
	{
		n=read(); m=read(); T=read();
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				while(!isdigit(s=getchar())); 
				g[i][j]=s-'0';
			}
		} 
		work();
		while(T--)
		{
			int i=read(),j=read(),r=read();
			int c=max(r-f[i][j],0ll);
			if(!fl[i][j]){printf("%d\n",g[i][j]); continue;} 
			if(c&1) printf("%d\n",!g[i][j]);
			else printf("%d\n",g[i][j]);
		}
		return 0;
	}
}
signed main(){return yspm::main();}