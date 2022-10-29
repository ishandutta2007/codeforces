#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#define f(i,j) (used[i+200][j+200])
#define trans(i) (i+200)
using namespace std;
struct data{
	int x,y,d;
	data(){}
	data(int x,int y,int d):x(x),y(y),d(d){}
	int operator<(const data& z)const{
		if(x!=z.x)return x<z.x;
		if(y!=z.y)return y<z.y;
		return d<z.d;
	}
};
bool used[510][510];
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
int t[50],n;
set<data>st[2];
int main(){
	int ptr=0,nptr=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&t[i]);
	st[ptr].insert(data(200,200,0));
	used[200][200]=1;
	t[1]--;
	for(int i=1;i<=n;++i){
		swap(ptr,nptr);
		st[ptr].clear();
		for(set<data>::iterator it=st[nptr].begin();it!=st[nptr].end();++it){
			data p=*it;
			for(int j=1;j<=t[i];++j)p.x+=dx[p.d],p.y+=dy[p.d],used[p.x][p.y]=1;
		//	printf("[%d,%d,%d]\n",i,p.x-200,p.y-200);
			st[ptr].insert(data(p.x,p.y,(p.d-1)&7));
			st[ptr].insert(data(p.x,p.y,(p.d+1)&7));
		}
	}
	int ans=0;
	for(int i=0;i<=500;++i)
		for(int j=0;j<=500;++j)if(used[i][j])ans++;
	printf("%d",ans);
}