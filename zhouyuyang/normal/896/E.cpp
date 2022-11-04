#include<bits/stdc++.h>
#define sz 254
#define l(x) (((x)-1)*sz+1)
#define r(x) min(n,((x)*sz))
#define N 108000
#define M 405
#define Merge(p,a,b) if (V[p][a].rt) merge(p,a,b)
using namespace std;
int n,m,be[N],a[N];
int pre[N],pos[N],L[N],R[N];
struct P{unsigned char num,rt;}V[M][N];
void merge(int p,int a,int b){
	P x=V[p][a],y=V[p][b];
	if (y.rt) pre[x.rt+l(p)-1]=y.rt+l(p)-1;
	else y.rt=x.rt,pos[y.rt+l(p)-1]=b;
	y.num+=x.num; x.rt=x.num=0;
	V[p][a]=x; V[p][b]=y;
}
int find(int x){
	for (;x!=pre[x];x=pre[x]=pre[pre[x]]);
	return x;
}
void pushdown(int v){
	for (int i=l(v);i<=r(v);i++){
		a[i]=pos[find(i)];
		V[v][a[i]].rt=0;
		V[v][a[i]].num=0;
		a[i]-=L[v];
	}
	for (int i=l(v);i<=r(v);i++)
		pre[i]=0;
	L[v]=0;
}
void update(int v){
	R[v]=0;
	for (int i=l(v);i<=r(v);i++){
		if (a[i]>R[v]) R[v]=a[i];
		if (!V[v][a[i]].rt){
			pre[i]=i; pos[i]=a[i];
			V[v][a[i]].rt=i-l(v)+1;
		}
		else
			pre[i]=V[v][a[i]].rt+l(v)-1;
		V[v][a[i]].num++;
	}
}
void modify(int x,int v){
	int &p=L[x],&q=R[x];
	if (v*2<=q-p){
		for (int i=p+1;i<=p+v;i++)
			Merge(x,i,i+v);
		p+=v;
	}
	else{
		for (int i=q;i>p+v;i--)
			Merge(x,i,i-v);
		q=min(q,p+v);
	}
}
void modify(int x,int y,int v){
	int p=be[x],q=be[y];
	if (p==q){
		pushdown(p);
		for (int i=x;i<=y;i++)
			if (a[i]>v) a[i]-=v;
		update(p);
		return;
	}
	pushdown(p);
	pushdown(q);
	for (int i=x;i<=r(p);i++)
		if (a[i]>v) a[i]-=v;
	for (int i=l(q);i<=y;i++)
		if (a[i]>v) a[i]-=v;
	for (int i=p+1;i<q;i++)
		modify(i,v);
	update(p);
	update(q);
}
int find(int x,int y,int v){
	int ans=0,p=be[x],q=be[y];
	if (p==q){
		for (int i=x;i<=y;i++)
			if (pos[find(i)]-L[p]==v)
				ans++;
		return ans;
	}
	for (int i=x;i<=r(p);i++)
		if (pos[find(i)]-L[p]==v)
			ans++;
	for (int i=l(q);i<=y;i++)
		if (pos[find(i)]-L[q]==v)
			ans++;
	for (int i=p+1;i<q;i++)
		if (v+L[i]<=100000)
			ans+=V[i][v+L[i]].num;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),be[i]=(i-1)/sz+1;
	for (int i=1;i<=be[n];i++)
		update(i);
	for (;m--;){
		int fl,l,r,v;
		scanf("%d%d%d%d",&fl,&l,&r,&v);
		if (fl==1) modify(l,r,v);
		else printf("%d\n",find(l,r,v));
	}
}