#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3)
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=100005;
int n,m,base;
int v[N],nxt[N],pre[N],nxb[N],tax[500][N];
int bL[N],bR[N];
int Find(int x){
	int now=0;
	while (x>=base)
		x-=base,now=nxb[now];
	while (x)
		x--,now=nxt[now];
	return now;
}
int Getorder(int x){
	return (x-1)/base;
}
int main(){
	n=read();
	base=(int)(1.2*sqrt(n));
	nxt[0]=1,nxb[0]=min(base,n+1),pre[0]=0;
	for (register int i=1;i<=n;i++){
		v[i]=read();
		nxt[i]=i+1,pre[i]=i-1;
		nxb[i]=min(i+base,n+1);
	}
	nxt[n+1]=nxb[n+1]=n+1,pre[n+1]=n;
	for (register int i=1;i<=n;i+=base){
		int j=min(i+base-1,n);
		int ord=Getorder(i);
		bL[ord]=i,bR[ord]=j;
		for (int k=i;k<=j;k++)
			tax[ord][v[k]]++;
	}
	m=read();
	int lastans=0;
	while (m--){
		int opt=read(),L=read(),R=read();
		L=(L+lastans-1)%n+1;
		R=(R+lastans-1)%n+1;
		if (L>R)
		    swap(L,R);
		if (opt==1){
			if (L==R)
				continue;
			int l=Getorder(L);
			int r=Getorder(R);
			int lp=Find(L),rp=Find(R);
			if (l!=r){
				tax[l][v[rp]]++;
				tax[r][v[rp]]--;
				int now=Find(bR[l]);
				for (register int i=l;i<r;i++,now=nxb[now]){
					tax[i][v[now]]--;
					tax[i+1][v[now]]++;
				}
			}
			int s=pre[rp],E=max(R-base,0);
			for (register int i=R-1;i>=E;i--,s=pre[s])
				nxb[s]=nxt[nxb[s]];
			nxt[pre[rp]]=nxt[rp];
			pre[nxt[rp]]=pre[rp];
			
			pre[rp]=pre[lp];
			nxt[rp]=lp;
			
			nxt[pre[lp]]=rp;
			pre[lp]=rp;
			
			nxb[rp]=pre[nxb[nxt[rp]]];
			s=pre[rp],E=max(L-base,0);
			for (register int i=L-1;i>=E;i--,s=pre[s])
				nxb[s]=pre[nxb[s]];
		}
		else {
			int k=read(),ans=0;		k=(k+lastans-1)%n+1;

			if (k>=N){
				puts("0");
				lastans=0;
				continue;
			}
			int l=Getorder(L);
			int r=Getorder(R);
			if (l==r){
				int s=Find(L);
				for (;L<=R;L++,s=nxt[s])
					if (v[s]==k)
						ans++;
			}
			else {
				for (register int i=l+1;i<=r-1;i++)
					ans+=tax[i][k];
				int s=Find(L);
				for (register int E=bR[l];L<=E;L++,s=nxt[s])
					if (v[s]==k)
						ans++;
				s=Find(bL[r]);
				for (register int E=bL[r];E<=R;E++,s=nxt[s])
					if (v[s]==k)
						ans++;
			}
			printf("%d\n",lastans=ans);
		}
	}
	return 0;
}