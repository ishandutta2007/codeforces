#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000") 
using namespace std;
const int N=500005,M=N*4;
struct Gragh{
	//2M*2*4B+0.5M*4B=18MB
	int cnt,y[M],nxt[M],fst[N];
	void clear(){
		cnt=1;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g,g2;
int n,m;
int dfn[N],low[N],inst[N],st[N],vis[N],id[N],Time,top,tot;
int used[M];
int Fa[N];
vector <int> cir[N],son[N];
void Tarjan_Prepare(){
	Time=top=tot=0;
	memset(id,0,sizeof id);
	memset(st,0,sizeof st);
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	memset(vis,0,sizeof vis);
	memset(inst,0,sizeof inst);
	memset(used,0,sizeof used);
}
void Tarjan(int x){
	dfn[x]=low[x]=++Time;
	vis[x]=inst[x]=1;
	st[++top]=x;
	for (int i=g.fst[x];i;i=g.nxt[i]){
		if (used[i/2])
			continue;
		used[i/2]=1;
		if (!vis[g.y[i]]){
			Tarjan(g.y[i]);
			low[x]=min(low[x],low[g.y[i]]);
		}
		else if (inst[g.y[i]])
			low[x]=min(low[x],low[g.y[i]]);
	}
	if (dfn[x]==low[x]){
		tot++;
		id[st[top]]=tot;
		inst[st[top]]=0;
		while (st[top--]!=x){
			id[st[top]]=tot;
			inst[st[top]]=0;
		}
	}
}
void Get_cir(int x){
	if (vis[x])
		return;
	vis[x]=1;
	cir[id[x]].push_back(x);
	for (int i=g.fst[x];i;i=g.nxt[i]){
		int y=g.y[i];
		if (id[y]==id[x])
			Get_cir(y);
	}
}
void build(int x,int pre){
	int ID=id[x];
	Fa[ID]=pre;
	cir[ID].clear();
	Get_cir(x);
	for (int i=0;i<cir[ID].size();i++){
		int u=cir[ID][i];
		son[u].clear();
		for (int j=g.fst[u];j;j=g.nxt[j]){
			int v=g.y[j];
			if (id[v]==ID||id[v]==pre)
				continue;
			son[u].push_back(v);
			build(v,ID);
		}
	}
}
int Deep[N];
// The Minimum value of the distance between 
// x and the deepest posterity of x 
//     x   
//   Deep  + 1 
int spDeep[N],usDeep[N];
// spDeep[x] x  
// usDeep[x] x  
int Lmax[N],Rmax[N];
void Get_Deep(int x){
	int ID=id[x];
	for (int i=0;i<cir[ID].size();i++){
		int u=cir[ID][i],v;
		Deep[u]=0;
		for (int j=0;j<son[u].size();j++){
			v=son[u][j];
			Get_Deep(v);
			Deep[u]=max(Deep[u],Deep[v]+1);
		}
	}
	int n=cir[ID].size()-1;
	Lmax[0]=Rmax[n+1]=0;
	for (int i=1;i<=n;i++)
		Lmax[i]=max(Lmax[i-1],Deep[cir[ID][i]]+i);
	for (int i=n;i>=1;i--)
		Rmax[i]=max(Rmax[i+1],Deep[cir[ID][i]]+(n-i+1));
	int v=1e9;
	for (int i=1;i<=n+1;i++)
		v=min(v,max(Lmax[i-1],Rmax[i]));
	Deep[x]=max(usDeep[x]=Deep[x],spDeep[x]=v);
}
int Far[N];
// The Minimum value of the distance between 
// x and the farthest vetrex which isn't a posterity of x 
//      
//    
int val[N*3];
int Lv[N*3],Rv[N*3];
struct Monotone_Queue{
	int head,tail,q[N*3],d[N*3];
	void clear(){
		head=1,tail=0;
	}
	int front(){
		return head<=tail?q[head]:-1e9;
	}
	void push(int v,int _d){
		while (head<=tail&&q[tail]<=v)
			tail--;
		q[++tail]=v,d[tail]=_d;
	}
	void pop(int _d){
		while (head<=tail&&d[head]<_d)
			head++;
	}
	int Next_front(int _d){
		if (head>tail)
			return -1e9;
		if (d[head]!=_d)
			return q[head];
		return head==tail?-1e9:q[head+1];
	}
}QL,QR;
vector <int> LRmax[N];
void Solve(int x,int far){
	int ID=id[x];
	Far[x]=far;
	int n=cir[ID].size();
	for (int i=1;i<n;i++)
		val[i]=Deep[cir[ID][i]];
	val[0]=max(usDeep[x],Far[x]);
	for (int i=n;i<n*3;i++)
		val[i]=val[i%n];
	for (int i=0;i<n*3;i++){
		Lv[i]=val[i]+n*3-i;
		Rv[i]=val[i]+i+1;
	}
	QL.clear(),QR.clear();
	int Lp=2,Rp=n+1;
	for (int i=Lp;i<=n;i++)
		QL.push(Lv[i],i);
	for (int i=n+1;i<n*2;i++){
		int result=1e9;
		int v1=n*3-i,v2=i+1;
		while (Rp<i){
			Lp++,QL.pop(Lp);
			Rp++;
			if (Rp!=i)
				QR.push(Rv[Rp],Rp);
		}
		while (QL.Next_front(Lp)-v1>max(QR.front(),Rv[Rp+1])-v2){
			result=min(result,QL.front()-v1);
			Lp++,QL.pop(Lp);
			Rp++,QR.push(Rv[Rp],Rp);
		}
		result=min(result,QL.front()-v1);
		result=min(result,max(QR.front(),Rv[Rp+1])-v2);
		QL.push(Lv[i],i);
		QR.pop(i+2);
		Far[cir[ID][i%n]]=result;
	}
	for (int i=0;i<n;i++){
		int u=cir[ID][i];
		int m=son[u].size();
		Lmax[0]=Rmax[m+1]=0;
		for (int j=1;j<=m;j++)
			Lmax[j]=max(Lmax[j-1],Deep[son[u][j-1]]+1);
		for (int j=m;j>=1;j--)
			Rmax[j]=max(Rmax[j+1],Deep[son[u][j-1]]+1);
		LRmax[u].clear();
		for (int j=0;j<m;j++)
			LRmax[u].push_back(max(Lmax[j],Rmax[j+2]));
		for (int j=0;j<m;j++)
			Solve(son[u][j],max(spDeep[u],max(Far[u],LRmax[u][j]))+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	g.clear();
	for (int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		g.add(a,b);
		g.add(b,a);
	}
	Tarjan_Prepare();
	for (int i=1;i<=n;i++)
		if (!vis[i])
			Tarjan(i);
	memset(vis,0,sizeof vis);
	build(1,0);
	Get_Deep(1);
	Solve(1,0);
	for (int i=1;i<=n;i++)
		printf("%d ",max(Far[i],Deep[i]));
	return 0;
}