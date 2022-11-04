#include<bits/stdc++.h>
using namespace std;
const int N=1210000;
int ch[N][27],ri[N][11];
int l[N],fa[N],sz=1,la=1;
int T,L[15],R[15];
vector<int> p[N];
long long ans;
char s[N];
void extend(int c,int tp){
	int p=la,np=++sz; la=np; l[np]=l[p]+1;
	if (tp!=-1) ri[np][tp]++;
	for (;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if (!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if (l[q]==l[p]+1) fa[np]=q;
		else{
			int nq=++sz; l[nq]=l[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for (;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
}
void dfs(int x){
	for (int i=0;i<p[x].size();i++){
		dfs(p[x][i]);
		for (int j=0;j<=T;j++)
			ri[x][j]+=ri[p[x][i]][j];
	}
	bool ok=1;
	for (int j=1;j<=T;j++)
		if (ri[x][j]<L[j]||ri[x][j]>R[j]) ok=0;
	if (!ri[x][0]) ok=0;
	if (ok) ans+=l[x]-l[fa[x]];
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++)
		extend(s[i]-'a',0);
	scanf("%d",&T);
	for (int i=1;i<=T;i++){
		scanf("%s%d%d",s+1,&L[i],&R[i]);
		int n=strlen(s+1); extend(26,-1);
		for (int j=1;j<=n;j++) extend(s[j]-'a',i);
	}
	extend(26,-1);
	for (int i=2;i<=sz;i++)
		p[fa[i]].push_back(i);
	dfs(1);
	printf("%lld\n",ans);
}