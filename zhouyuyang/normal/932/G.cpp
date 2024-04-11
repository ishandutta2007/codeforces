#include<bits/stdc++.h>
#define mo 1000000007
#define N 1000005
using namespace std;
int fa[N],ch[N][26],l[N];
int dif[N],anc[N],la;
int a[N],f[N],g[N];
int n,p;
char s[N];
void init(){
	p=2; l[0]=fa[1]=0;
	l[1]=-1; fa[0]=1;
	f[0]=la=1;
}
void extend(int c,int id){
	int x=la;
	for (;a[id]!=a[id-l[x]-1];x=fa[x]);
	if (!ch[x][c]){
		l[p]=l[x]+2;
		int k=fa[x];
		for (;a[id]!=a[id-l[k]-1];k=fa[k]);
		fa[p]=ch[k][c];
		ch[x][c]=p;
		dif[p]=l[p]-l[fa[p]];
		if (dif[p]==dif[fa[p]])
			anc[p]=anc[fa[p]];
		else anc[p]=fa[p];
		p++;
	}
	la=ch[x][c];
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	if (n&1) return puts("0"),0;
	for (int i=1;i<=n/2;i++)
		a[i*2-1]=s[i]-'a',a[i*2]=s[n-i+1]-'a';
	a[0]=-1; init();
	for (int i=1;i<=n;i++){
		extend(a[i],i);
		for (int x=la;x;x=anc[x]){
			g[x]=f[i-(l[anc[x]]+dif[x])];
			if (anc[x]!=fa[x])
				g[x]=(g[x]+g[fa[x]])%mo;
			if (i%2==0) f[i]=(f[i]+g[x])%mo;
		}
	}
	printf("%d\n",f[n]);
}