#include <cstdio>
#include <cassert>
#include <list>
const int N=8e5+10;
const int dir[4][2]={{1,1},{1,-1},{-1,-1},{-1,1}};
const int pdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int T,n,m,f[N];char *s[N];
int id(int x,int y){return x*m+y;}
struct pt{
	int x,y;pt():x(0),y(0){};
	pt(int x,int y):x(x),y(y){};
	int uid(){return id(x,y);}
}ls[N];std::list<pt> q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i){
			s[i]=new char[m+10];
			scanf("%s",s[i]+1);
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)f[id(i,j)]=-1;
		q.clear();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				for(int k=0;k<4;++k){
					int nx=i+pdir[k][0],ny=j+pdir[k][1];
					if(nx<1||nx>n||ny<1||ny>m)continue;
					if(s[nx][ny]=='#')f[id(i,j)]=-2;
				}
			}
		}
		for(int i=1;i<=n;++i){
			ls[id(i,1)]=pt(0,0);if(~f[id(i,1)])continue;
			if(s[i][1]=='#')f[id(i,1)]=0,q.push_front(pt(i,1));
			else f[id(i,1)]=1,q.push_back(pt(i,1));
		}
		int tim=0;
		while(q.size()){
			assert((int)q.size()<=n*m);
			pt u=q.front();q.pop_front();
			int x=u.x,y=u.y,v=id(x,y);
			for(int i=0;i<4;++i){
				int nx=x+dir[i][0],ny=y+dir[i][1];
				if(nx<1||ny<1||nx>n||ny>m||~f[id(nx,ny)])continue;
				if(s[nx][ny]=='#')f[id(nx,ny)]=f[v],ls[id(nx,ny)]=u,q.push_front(pt(nx,ny));
				else f[id(nx,ny)]=f[v]+1,ls[id(nx,ny)]=u,q.push_back(pt(nx,ny));
			}
			assert(++tim<=n*m);
		}
		int p=1;
		for(int i=2;i<=n;++i)if(f[id(i,m)]>=0&&(f[id(p,m)]<0||f[id(i,m)]<f[id(p,m)]))p=i;
		if(f[id(p,m)]<0){puts("NO");continue;}else puts("YES");
		tim=0;
		for(pt np=pt(p,m);np.x;np=ls[np.uid()]){
			s[np.x][np.y]='#';
			assert(++tim<=n*m);
		}
		for(int i=1;i<=n;++i)puts(s[i]+1);
	}
	return 0;
}