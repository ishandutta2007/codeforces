#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2005;
int pa[N];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
inline void unin(int x,int y){
	x=find(x),y=find(y),pa[x]=y;
}
int n,m,E;
struct Edge{
	int x,y,dat;
	bool operator <(const Edge &q) const {return dat>q.dat;}
}e[N*N];
bitset<N>a[N];
char ch[N];
vector<pii>ans;
inline void work(){
	n=read(),m=read();ans.clear();E=0;
	for(int i=1;i<=n;i++)a[i].reset(),pa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=n;j++)
			if(ch[j]=='1')a[j].set(i);
	}
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			e[++E]=(Edge){i,j,(int)(a[i]&a[j]).count()};
	sort(e+1,e+E+1);
	for(int i=1;i<=E;i++){
		int x=e[i].x,y=e[i].y;
		if(find(x)^find(y))
			unin(x,y),ans.push_back(pii(x,y));
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			pa[j]=a[j][i]?j:0;
		for(auto x:ans)
			if(pa[x.fi] && pa[x.se])unin(x.fi,x.se);
		int tot=0;
		for(int j=1;j<=n;j++)tot+=(find(j)==j);
		if(tot>1){puts("NO");return;}
	}
	puts("YES");
	for(auto x:ans)printf("%d %d\n",x.fi,x.se);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}