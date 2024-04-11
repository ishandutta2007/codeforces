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
const int M=2e5+10; 
int to[M],nxt[M],head[M],w[M],cnt; 
void add(int x,int y,int v){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=v; 
}
int lg[M],p[M],ct,de[M]; 
int n,q; 
struct Tree{
	int rt,mxl,len[M],dis[M],son[M],tp[M],ans[M];
	int f[M][20],id[M],sbc[M]; 
	void dfs(int x,int fa,int dd){
		if (dd>mxl) rt=x,mxl=dd; 
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (y==fa) continue;
			dfs(y,x,dd+w[i]);
		}
	}
	void calc(int x,int fa,int dep,int id){
		F(i,1,lg[dep]) f[x][i]=f[f[x][i-1]][i-1];
//		g[x][i]=g[x][i-1]+g[f[x][i-1]][i-1];
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (y==fa) continue; 
			dis[y]=dis[x]+w[i];
			f[y][0]=x; //g[y][0]=w[i]; 
			calc(y,x,dep+1,i); 
			if (len[x]<len[y]+w[i]) son[x]=y,len[x]=len[y]+w[i]; 
		}
		sbc[x]=len[x]+w[id]; 
//		cout<<x<<" "<<len[x]<<" "<<son[x]<<"   gghhh\n"; 
	}
	void clp(int x,int fa,int th){
		tp[x]=th; 
		if (son[x]){
			clp(son[x],x,th);
		}
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (y==fa || y==son[x]) continue; 	
			clp(y,x,y); 
		}
	}
	void pre(){
//		tp[rt]=0; 
//		len[0]=len[rt]; 
		sort(p+1,p+ct+1,[&](int x, int y) { return (x==rt ? 0 : (y==rt ? 1 :sbc[tp[x]] > sbc[tp[y]])); });
//		cout<<rt<<"  fuck\n";
		for (int i=1;i<ct;i++){
			for (int x=p[i];tp[x]==tp[p[i]];x=f[x][0]) id[x]=i;
//			cout<<p[i]<<" "<<tp[p[i]]<<" "<<sbc[tp[p[i]]]<<" "<<ans[i-1]<<"   jj\n";
			ans[i]=ans[i-1]+sbc[tp[p[i]]];
//			cout<<ans[i]<<" "<<i<<"   gg\n";  
		}
	}
	int qry1(int x,int y){
		int tx=x;
		DF(i,lg[n],0){
			if (id[f[x][i]]>y){
				x=f[x][i];
			}
		}
		return ans[y]-len[f[x][0]]+len[tx]+(dis[tx]-dis[f[x][0]]); 
	}
	int qry2(int x,int y){
		int tx=x;
		DF(i,lg[n],0){
			if (id[f[x][i]]>y){
				x=f[x][i];
			}
		}
		return ans[y]+len[tx]+(dis[tx]-dis[f[x][0]]); 
	}
	int qry(int x,int y){
		y=min(y,ct-1);
//		cout<<id[x]<<"    lglglg\n";
		return (id[x]<=y  ? ans[y] : max(qry1(x,y),qry2(x,y-1)));
	}
}t1,t2;
int main(){
	n=read(); q=read();
	F(i,1,n-1){
		int x=read(),y=read(),z=read();
		add(x,y,z); add(y,x,z); de[x]++; de[y]++;
	}
	F(i,1,n) if (de[i]==1) p[++ct]=i;
	F(i,2,n) lg[i]=lg[i>>1]+1;
	t1.dfs(1,0,0); t2.dfs(t1.rt,0,0);
	t1.calc(t1.rt,0,0,0); t2.calc(t2.rt,0,0,0);
	t1.clp(t1.rt,0,t1.rt); t2.clp(t2.rt,0,t2.rt);
	t1.pre(); t2.pre(); 
	int lst=0;
	while (q--){
		int x=read(),y=read(); 
		x=(x+lst-1)%n+1; 
		y=(y+lst-1)%n+1; 
//		cout<<x<<" "<<y<<"  uncode\n";
		y=2*y-1;
		cout<<(lst=max(t1.qry(x,y),t2.qry(x,y)))<<"\n"; 
	}
	return 0;
}