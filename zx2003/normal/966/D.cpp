#include<bits/stdc++.h>
using namespace std;
const int N=300005;
char ibuf[1<<25],*ih=ibuf;
inline void read(int&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
vector<int>e[N];
int n,m,x,y,i,d[N],pre[N];
bool vi[N],vii[N];
int q[N];
int t,w;
void bfs(int x){
	t=0,w=1;
	int i,u;
	q[1]=x;d[x]=0;vi[x]=1;pre[x]=0;
	for(;t<w;){
		u=q[++t];
		for(i=0;i<e[u].size();++i)if(!vi[e[u][i]]){
			d[e[u][i]]=d[u]+1;q[++w]=e[u][i];
			vi[e[u][i]]=1;pre[e[u][i]]=u;
		}
	}
}
bool ask(int x,int y){
	vector<int>::iterator p=lower_bound(e[x].begin(),e[x].end(),y);
	return p!=e[x].end() && y==*p;
}
void outi(int i){
	int a[10],xb=0;
	for(;i;i=pre[i])a[++xb]=i;
	for(;xb;)cout<<a[xb--]<<' ';
}
inline void work(int x){
	int deg=-1,v,i,j;
	bfs(x);
	for(i=1;i<=w;++i){
		int d=e[q[i]].size();
		if(d>deg)deg=d,v=q[i];
		vi[q[i]]=0;vii[q[i]]=1;
	}
	bfs(v);
	for(i=1;i<=w;++i)if(d[q[i]]==2){
		cout<<"5\n1 ";
		outi(q[i]);
		cout<<v<<' '<<n<<'\n';
		exit(0);
	}
	for(i=0;i<e[v].size();++i)
		for(j=i+1;j<e[v].size();++j)
			if(!ask(e[v][i],e[v][j])){
				cout<<"5\n1 "<<e[v][i]<<' '<<v<<' '<<e[v][j]<<' '<<e[v][i]<<' '<<n;
				exit(0);
			}
}
int main(){
//	freopen("1","r",stdin);
//	ios::sync_with_stdio(0);cin.tie(0);
	fread(ibuf,1,1<<25,stdin);
	read(n),read(m);
	for(i=1;i<=m;++i){
		read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(i=1;i<=n;++i)sort(e[i].begin(),e[i].end());
	bfs(1);
	if(vi[n] && d[n]<=4){
		int a[10],xb=0;
		cout<<d[n]<<'\n';
		for(i=n;i;i=pre[i])a[++xb]=i;
		for(;xb;)cout<<a[xb--]<<' ';
		return 0;
	}else{
		for(i=1;i<=n;++i)if(d[i]==2)break;
		if(d[i]==2){
			cout<<"4\n";
			outi(i);
			cout<<"1 "<<n;
			exit(0);
		}
		memset(vi,0,sizeof vi);vi[1]=1;
		for(i=0;i<e[1].size();++i)if(!vii[e[1][i]])work(e[1][i]);
		cout<<"-1\n";
	}
	return 0;
}