#include<bits/stdc++.h>
#define N 200005
#define M 505 
using namespace std;
int a[N],L[M],R[M];
int num[M],fa[M][N+233];
int v[M][105],val[N+233];
int n,sz,cnt,rt[M][105];
int q,l,r,x,y;
void pushdown(int id){
	for (int i=num[id];i;i--)
		fa[id][i]=fa[id][fa[id][i]];
	for (int i=1;i<=100;i++)
		val[v[id][i]]=i;
	for (int i=L[id];i<=R[id];i++)
		a[i]=val[fa[id][a[i]]];
}
void pushup(int id){
	num[id]=100;
	for (int i=1;i<=100;i++)
		fa[id][i]=i,rt[id][i]=i,v[id][i]=i;
}
#define gc() getchar()
int read(){
	int x=0; char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc());
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return x;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	sz=400; cnt=(n-1)/sz+1;
	for (int i=1;i<=cnt;i++){
		L[i]=(i-1)*sz+1,R[i]=min(n,i*sz);
		pushup(i);
	}
	q=read();
	while (q--){
		l=read(); r=read();
		x=read(); y=read();
		if (x==y) continue;
		int le=(l-1)/sz+1,ri=(r-1)/sz+1;
		if (le==ri){
			pushdown(le);
			for (int i=l;i<=r;i++)
				if (a[i]==x) a[i]=y;
			pushup(le);
			continue;
		}
		pushdown(le);
		pushdown(ri);
		for (int i=l;i<=R[le];i++)
			if (a[i]==x) a[i]=y;
		for (int i=L[ri];i<=r;i++)
			if (a[i]==x) a[i]=y;
		for (int i=le+1;i<ri;i++){
			if (!rt[i][x])
				continue;
			if (!rt[i][y]){
				rt[i][y]=rt[i][x];
				rt[i][x]=0;
				v[i][y]=v[i][x];
				v[i][x]=0;
				continue;
			} 
			num[i]++;
			fa[i][rt[i][x]]=num[i];
			fa[i][rt[i][y]]=num[i];
			fa[i][num[i]]=num[i];
			rt[i][y]=num[i];
			rt[i][x]=0;
			v[i][y]=num[i];
			v[i][x]=0;
		}
		pushup(le);
		pushup(ri);
	}
	for (int i=1;i<=cnt;i++)
		pushdown(i);
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
}