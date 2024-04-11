#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000005;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
void write(int v){
	int k=v/10;
	if (v>9)
		write(k);
	putchar('0'+(v-k*10));
}
int cnt,y[N],nxt[N],fst[N];
void add(int a,int b){
	y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
}
int n,m;
int vis[N],ans[N],anscnt=0;
int main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int a=read(),b=read();
		add(a,b);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			vis[i]=-2;
			for (int j=fst[i];j;j=nxt[j])
				if (!vis[y[j]])
					vis[y[j]]=-1;
		}
	for (int i=n;i>=1;i--)
		if (vis[i]==-2){
			ans[++anscnt]=i;
			for (int j=fst[i];j;j=nxt[j])
				vis[y[j]]=-1;
		}
	write(anscnt),puts("");
	for (int i=anscnt;i>=1;i--)
		write(ans[i]),putchar(' ');
	return 0;
}