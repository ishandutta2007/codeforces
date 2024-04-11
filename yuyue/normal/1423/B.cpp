#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}

const int M=2e4+10,E=3e5+10;
int n,m,s,t,cnt,maxflow;
int cur[M],head[M],nxt[E],to[E],w[E];
int l,r,q[M],dep[M];
void add(int x,int y,int v){
	to[++cnt]=y; nxt[cnt]=head[x]; w[cnt]=v; head[x]=cnt;
}
void addedge(int x,int y,int v){
	add(x,y,v);
	add(y,x,0);
}
int now;
bool bfs(){
	l=r=1; q[1]=s;
	memset(dep,0,sizeof dep); dep[s]=1;
	while (l<=r){
		int x=q[l++];
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (!dep[y] && w[i]>0 && i<=now) dep[y]=dep[x]+1,q[++r]=y;
		}
	}
	return dep[t];
}
int dfs(int x,int flow){
//	cout<<dep[x]<<" "<<x<<"\n";
	if (!flow || x==t) return flow;
	int res=0;
	for (int &i=cur[x];i;i=nxt[i]){
		int y=to[i];
		if (dep[y]==dep[x]+1 && w[i]>0 && i<=now){
			int ff=dfs(y,min(flow,w[i]));
			if (ff>0){
				w[i]-=ff;
				w[i^1]+=ff;
				flow-=ff;
				res+=ff;
			}
			if (res==flow) return flow;
		}
	}
	return res;
}
struct node{
	int x,y,z;
}a[E];
bool cmp(node A,node B){
	return A.z<B.z;
}
int MF(int bp){
	now=bp;
	F(i,2,cnt){
		w[i]+=w[i^1];
		w[i^1]=0;
		i++;
	}
	int maxflow=0; 
	while (bfs()) {	
//		cout<<maxflow<<"   hh\n";
		memcpy(cur,head,sizeof head);
		maxflow+=dfs(s,INT_MAX);
	}
	return maxflow;
}
int lim[E];
int main(){
	n=read(); m=read(); s=0; t=2*n+1;
	cnt=1;
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		a[i]=(node){x,y,z}; 
	}
	F(i,1,n) addedge(s,i,1),addedge(i+n,t,1);
	sort(a+1,a+m+1,cmp);
	F(i,1,m){
		addedge(a[i].x,a[i].y+n,1);
		lim[i]=cnt;
	}
//	return 0; 
	int l=1,r=m,ans=m+1;
	while (l<=r){
		int mid=(l+r>>1);
		if (MF(lim[mid])==n) r=mid-1,ans=mid; 
		else l=mid+1; 
	}
	cout<<(ans==m+1 ? -1 : a[ans].z)<<"\n";
	return 0;
}