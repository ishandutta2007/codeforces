#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
const int N=1000005;
int id[N],to[N],n,Q;
char s[N],ns[N];
int nxt[N],q[N],len[N];
int type[N],beg[N];
int vis[N];
int read(){
	int x=0;
	#define gc getchar
	char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc());
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return x;
}
void solve(){
	int k=read(),d=read(),top=0; *q=0;
	For(i,0,d-1) for (int j=i;j<k;j+=d) id[top++]=j;
	For(i,0,k-1){
		nxt[(i==0?k:i-1)]=id[i];
		to[id[i]]=(i==0?k:i-1);
	}
	nxt[k-1]=-1; int T=0;
	For(i,0,k) vis[i]=0;
	Rep(i,k,0) if (!vis[i]){
		++T; type[T]=(i!=k); beg[T]=*q+1;
		for (int x=i;x!=-1&&!vis[x];x=nxt[x])
			q[++*q]=x,id[x]=*q,vis[x]=T;
		len[T]=*q-beg[T]+1;
	}
	For(i,0,n-1){
		int mxT=min(n-i,n-k+1),beg=min(k-1,i);
		if (!type[vis[beg]]){
			if (id[beg]-2<=mxT) mxT-=id[beg]-2,beg=nxt[k];
			else beg=q[id[beg]-mxT],mxT=0;
		}
		else{
			int fr=id[beg]-::beg[vis[beg]];
			int las=(fr+len[vis[beg]]-mxT%len[vis[beg]])%len[vis[beg]];
			beg=q[las+::beg[vis[beg]]]; mxT=0;
		}
		if (mxT&&to[beg]==k) ns[n-mxT-k+1]=s[i];
		else ns[n-k+beg+1]=s[i];
	}
	For(i,0,n-1) putchar(s[i]=ns[i]);
	puts("");
}
int main(){
	scanf("%s",s);
	Q=read(); n=strlen(s);
	while (Q--) solve();
}