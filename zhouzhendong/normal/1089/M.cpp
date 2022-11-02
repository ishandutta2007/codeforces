#include <bits/stdc++.h>
#define y1 __zzd001
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=0,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?x:-x;
}
const int N=12;
int n;
int g[N][N],g2[N][N],vis[N],id[N];
int v[30][40][200],c[30];
int check(int s){
	for (int i=1;i<=n;i++)
		if ((s>>i&1)&&vis[i])
			return 0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ((s>>i&1)&&(s>>j&1)&&!g[i][j])
				return 0;
	return 1;
}
int cnt;
void tuopu(){
	int q[100],head=0,tail=0;
	int in[100];
	memset(in,0,sizeof in);
	for (int i=1;i<=cnt;i++)
		for (int j=1;j<=cnt;j++)
			if (i!=j&&g2[i][j])
				in[j]++;
	for (int i=1;i<=cnt;i++)
		if (!in[i])
			q[++tail]=i;
	while (head<tail){
		int x=q[++head];
		for (int i=1;i<=cnt;i++)
			if (g2[x][i]&&in[i])
				if ((--in[i])==0)
					q[++tail]=i;
	}
	for (int i=1;i<=cnt;i++)
		id[q[i]]=cnt-i+1;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			g[i][j]=read();
	for (int i=1;i<=n;i++)
		g[i][i]=1;
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				g[i][j]|=g[i][k]&&g[k][j];
	memset(vis,0,sizeof vis);
	for (int i=(1<<n)-1;i>0;i--)
		if (check(i<<1)){
			cnt++;
			for (int j=0;j<n;j++)
				if (i>>j&1)
					vis[j+1]=cnt;
		}
	int a=cnt*2,b=3,C=max(n,cnt*cnt*2);
	memset(g2,0,sizeof g2);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			g2[vis[i]][vis[j]]|=g[i][j];
	tuopu();
//	for (int i=1;i<=n;i++)
//		cout << id[i] << endl;
	for (int i=1;i<=a;i+=2)
		for (int j=1;j<=2;j++)
			for (int k=1;k<=C;k++)
				v[i][j][k]=-1;
	for (int i=1;i<=a;i++)
		for (int k=1;k<=C;k++)
			v[i][2][k]=-1;
	for (int i=1;i<=a;i++)
		for (int k=1;k<=C;k+=2)
			v[i][3][k]=-1;
	memset(c,0,sizeof c);
	for (int i=1;i<=n;i++)
		v[id[vis[i]]*2][1][++c[vis[i]]]=i;
	for (int i=1;i<=cnt;i++)
		for (int j=1;j<=cnt;j++)
			if (i!=j&&g2[i][j]){
				v[id[i]*2][2][2*((i-1)*cnt+j)]=0;
				v[id[j]*2-1][3][2*((i-1)*cnt+j)]=-1;
				v[id[j]*2][2][2*((i-1)*cnt+j)]=0;
			}
	printf("%d %d %d\n",C,b,a);
	for (int i=a;i>=1;i--,puts(""))
		for (int j=1;j<=b;j++,puts(""))
			for (int k=1;k<=C;k++)
				if (v[i][j][k]==-1)
					putchar('#');
				else if (v[i][j][k]==0)
					putchar('.');
				else
					putchar('0'+v[i][j][k]);
	return 0;
}
/*
4
1 1 0 0
1 0 0 0
0 1 0 0
0 0 0 0
*/