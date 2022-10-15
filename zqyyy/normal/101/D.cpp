#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
struct Edge{
	int to,nxt,dat;
}e[N<<1];
int cnt,head[N];
inline void add_e(int from,int to,int dat){
	e[++cnt].to=to,e[cnt].dat=dat;
	e[cnt].nxt=head[from],head[from]=cnt;
}
struct node{
	ll sum,tim,sz;
	bool operator <(const node &q) const {
		return sum*q.sz<q.sum*sz;
	}
}b[N];
int n;
vector<node>a[N];
void dfs(int x,int fa){
	b[x].sz=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to,dat=e[i].dat;
		if(y==fa)continue;
		dfs(y,x);b[x].sz+=b[y].sz;
		a[x].push_back((node){b[y].sum+2*dat,b[y].tim+b[y].sz*dat,b[y].sz});
	}
	sort(a[x].begin(),a[x].end());
	int siz=b[x].sz-1;
	for(auto i:a[x]){
		siz-=i.sz;
		b[x].tim+=i.tim+i.sum*siz;
		b[x].sum+=i.sum;
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read(),dat=read();
		add_e(x,y,dat),add_e(y,x,dat);
	}
	dfs(1,0);
	double ans=b[1].tim*1.0/(n-1);
	printf("%.6lf\n",ans);
	return 0;
}