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
int sz[M],c[M][2],val[M],tgv[M],tga[M],ans[M],pri[M]; 
void pu(int x){
	sz[x]=sz[c[x][0]]+sz[c[x][1]]+1;
}
int rd(){
	return rand()^(rand()<<10);
}
void sub(int x,int y){
	if (!x) return ;
	val[x]-=y; tgv[x]+=y;
}
void ja(int x,int y){
	if (!x) return ;
	ans[x]+=y; tga[x]+=y;
}
void pd(int x){
	if (tgv[x]){
		sub(c[x][0],tgv[x]);
		sub(c[x][1],tgv[x]); 
		tgv[x]=0;
	}
	if (tga[x]){
		ja(c[x][0],tga[x]);
		ja(c[x][1],tga[x]);
		tga[x]=0;
	}
	return ;
}
int merge(int x,int y){
	if (!x || !y) return x|y;
	pd(x); pd(y);
	if (pri[x]>pri[y]){
		c[x][1]=merge(c[x][1],y);
		pu(x);
		return x;
	}
	else{
		c[y][0]=merge(x,c[y][0]);
		pu(y);
		return y;
	}
}
void split(int now,int k,int &x,int &y){
	if (!now) return x=y=0,void();
	pd(now);
	if (val[now]<=k){
		x=now;
		split(c[now][1],k,c[x][1],y);
	}
	else{
		y=now;
		split(c[now][0],k,x,c[y][0]);
	}
	pu(now);
}
void ins(int &rt,int x){
	sz[x]=1; c[x][0]=c[x][1]=0;
	int tx,ty;
	split(rt,val[x],tx,ty);
	rt=merge(tx,merge(x,ty));
}
void dec(int x,int y){
	sub(x,y);
	ja(x,1);
}
int q[M],cc[M],n,m,p[M];
bool cmp(int x,int y){
	return q[x]==q[y] ? cc[x]<cc[y] : q[x]>q[y];
}
void dfs(int x,int &y){
	if (!x) return ;
	pd(x); 
	dfs(c[x][0],y); dfs(c[x][1],y);
	if (y!=-1) ins(y,x);
}
int b[M];
int main(){
//	freopen("2.in","r",stdin);
	srand(time(0));
	n=read(); 
	F(i,1,n) cc[i]=read(),q[i]=read(),p[i]=i;
	sort(p+1,p+n+1,cmp);
	m=read();
	int tx,ty,tz,rt=0;
	F(i,1,m){
		int x=read();
		sz[i]=1; val[i]=x; pri[i]=rd();
//		int res=x,tt=0;
//		F(j,1,n){
//			if (res>=cc[p[j]]) res-=cc[p[j]],tt++;
//		}
//		b[i]=tt;
		ins(rt,i);
	}
	F(i,1,n){
		int x=p[i],co=cc[x];
		split(rt,co-1,tx,ty);
		split(ty,2*co-1,ty,tz);
		dec(ty,co); dec(tz,co);
		dfs(ty,tx);
		rt=merge(tx,tz);
	}
	int tmp=-1;
	dfs(rt,tmp);
//	F(i,1,m) assert(ans[i]==b[i]);
	
	F(i,1,m){
		cout<<ans[i]<<" ";
//		assert(ans[i]==b[i]);
	}
//	cerr<<"  OK\n";
	cout<<"\n";
	return 0;
}
/*
*/