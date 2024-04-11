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
const int M=155;
struct edge{
	int x,y,t;
}e[M];
int n,m;
struct Mt{
	bitset<M> a[M];
	Mt(){
		F(i,1,n) a[i].reset();
	}
}ret,base;
Mt operator *(const Mt &A,const Mt &B){
	Mt C;
	F(i,1,n) F(k,1,n) if (A.a[i][k]) C.a[i]|=B.a[k];
	return C;
}
bool cmp(edge A,edge B){
	return A.t<B.t;
}
void fast(int p,Mt o){
	for (;p;p>>=1,o=o*o) if (p&1) ret=ret*o;
}
int q[M],dis[M];
void bfs(){
	int l=1,r=0;
	F(i,1,n){
		if (ret.a[1][i]) q[++r]=i,dis[i]=0;
		else dis[i]=1e9;
	}
	while (l<=r){
		int x=q[l++];
		for (int j=1;j<=n;j++){
			if (dis[j]==1e9 && base.a[x][j]){
				
				q[++r]=j;
				dis[j]=dis[x]+1;
			}
		}
	}
}
int main(){
	n=read(); m=read();
	F(i,1,m){
		e[i].x=read(); e[i].y=read(); e[i].t=read();
	}
	ret.a[1][1]=1;
	sort(e+1,e+m+1,cmp);
	int now=0;
	F(i,1,m){
		fast(e[i].t-now,base);
		base.a[e[i].x][e[i].y]=1;
		bfs();
		now=e[i].t;	
		if (dis[n]!=1e9) {
			cout<<now+dis[n]<<"\n";
			return 0;
		}
	
	}
	cout<<"Impossible\n";
	return 0;
}