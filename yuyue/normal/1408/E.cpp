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
const int M=4e5+10;
int n,m,ct;
struct node{
	int x,y,v;
}e[M];
bool cmp(node A,node B){
	return A.v>B.v;
}
int f[M];
int Fd(int x){
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
}
int a[M],b[M];
int main(){
	n=read(); m=read();
	F(i,1,n) a[i]=read();
	F(i,1,m) b[i]=read();
	LL ans=0;
	F(i,1,n){
		int num=read();
		F(j,1,num){
			int x=read();
			e[++ct]=(node){m+i,x,a[i]+b[x]};
			ans+=a[i]+b[x];
		}
	}
	sort(e+1,e+ct+1,cmp); 
	F(i,1,n+m) f[i]=i;
	F(i,1,ct){
		int u=e[i].x,v=e[i].y;
		u=Fd(u); v=Fd(v);
		if (u^v){
			f[u]=v;
			ans-=e[i].v;
		}
	}
	cout<<ans<<'\n';
	return 0;
}