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
const int M=5e5+10;
int n,m;
int to[M],nxt[M],head[M],cnt,w[M];
void add(int x,int y,int z){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}
int f[M][2],q[M];
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read(),z=read();
		add(y,x,z);
	}
	int l=1,r=1;
	F(i,1,n) f[i][0]=f[i][1]=1e9; 
	q[1]=n; f[n][0]=f[n][1]=0;
	while (l<=r){
		int x=q[l++];
		int o=max(f[x][0],f[x][1]);
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			int old=max(f[y][1],f[y][0]);
			if (1+o<f[y][w[i]]){
				f[y][w[i]]=o+1;
				int nw=max(f[y][1],f[y][0]);
				if (nw^old){
					q[++r]=y; 
				}
			}
		}
	}
	int dis=max(f[1][0],f[1][1]);
	if (dis>=1e9){
		puts("-1");
//		return 0;
	}
	else cout<<dis<<"\n";
	F(i,1,n){
		cout<<(f[i][0]<f[i][1] ? 1 : 0);
	}
	cout<<"\n";
	return 0;
}