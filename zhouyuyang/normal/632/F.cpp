#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
using namespace std;
const int L=1000000;
char LZH[L];
char *SSS,*TTT;
inline char gc(){
	if (SSS==TTT) TTT=(SSS=LZH)+fread(LZH,1,L,stdin);
	return *SSS++;
}
inline int read(){
	int x=0;
	char c=gc();
	for (;c<'0'||c>'9';c=gc());
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x;
}
const int N=2505;
int n,a[N][N],fl[N];
int f[N],pre[N];
int dis[N],q[N];
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int main(){
	n=read();
	For(i,1,n) For(j,1,n) a[i][j]=read();
	For(i,1,n) if (a[i][i]) return puts("NOT MAGIC"),0;
	For(i,1,n) For(j,i+1,n)
		if (a[i][j]!=a[j][i])
			return puts("NOT MAGIC"),0;
	For(i,0,n) f[i]=1e9+1e8; f[1]=0;
	For(i,1,n){
		int j=0;
		For(k,1,n) if (!fl[k]&&f[k]<f[j]) j=k;
		fl[j]=1;
		if (pre[j])
			add(pre[j],j),add(j,pre[j]);
		For(k,1,n) if (a[j][k]<f[k])
			pre[k]=j,f[k]=a[j][k];
	}
	For(i,1,n){
		For(j,1,n) dis[j]=-1;
		int h=0,t=1; q[1]=i; dis[i]=0;
		while (h!=t){
			int x=q[++h];
			for (int i=head[x];i;i=e[i].next)
				if (dis[e[i].to]==-1){
					dis[e[i].to]=max(dis[x],a[x][e[i].to]);
					q[++t]=e[i].to;
				}
		}
		For(j,1,n)
			if (dis[j]!=a[i][j])
				return puts("NOT MAGIC"),0;
	}
	puts("MAGIC");
}