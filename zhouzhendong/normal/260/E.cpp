#include <bits/stdc++.h>
#define y1 _fn82
using namespace std;
const int N=100005,S=N*30;
struct HashTable{
	int v[N],tot;
	void clear(){tot=0;}
	void push(int x){v[++tot]=x;}
	void Hash(){
		sort(v+1,v+tot+1);
		int hs=1;
		for (int i=2;i<=tot;i++)
			if (v[i]!=v[i-1])
				v[++hs]=v[i];
		tot=hs;
	}
	int find(int x){
		int L=1,R=tot,mid;
		while (L<=R){
			mid=(L+R)>>1;
			if (v[mid]==x)
				return mid;
			if (x<v[mid])
				R=mid-1;
			else
				L=mid+1;
		}
	}
}hx,hy;
int n,x[N],y[N],a[N],xt,yt,id[N];
int psumx[N],psumy[N];
vector <int> points[N];
int root[N],sum[S],ls[S],rs[S],tot=0;
void build(int &rt,int L,int R){
	sum[rt=++tot]=0;
	if (L==R)
		return;
	int mid=(L+R)>>1;
	build(ls[rt],L,mid);
	build(rs[rt],mid+1,R);
}
void update(int prt,int &rt,int L,int R,int x){
	if (!rt||rt==prt)
		sum[rt=++tot]=sum[prt];
	sum[rt]++;
	if (L==R)
		return;
	if (!ls[rt])
		ls[rt]=ls[prt];
	if (!rs[rt])
		rs[rt]=rs[prt];
	int mid=(L+R)>>1;
	if (x<=mid)
		update(ls[prt],ls[rt],L,mid,x);
	else
		update(rs[prt],rs[rt],mid+1,R,x);
}
int query(int rt,int L,int R,int xL,int xR){
	if (!rt||R<xL||L>xR)
		return 0;
	if (xL<=L&&R<=xR)
		return sum[rt];
	int mid=(L+R)>>1;
	return query(ls[rt],L,mid,xL,xR)+query(rs[rt],mid+1,R,xL,xR);
}
int Query(int x1,int x2,int y1,int y2){
	return query(root[x2],1,yt,y1,y2)-query(root[x1-1],1,yt,y1,y2);
}
bool check(int x1,int x2,int y1,int y2){
	int x[4]={0,x1,x2,xt},y[4]={0,y1,y2,yt};
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			if (Query(x[i-1]+1,x[i],y[j-1]+1,y[j])!=a[id[(j-1)*3+i]])
				return 0;
	return 1;
}
void Try(){
	int x1=0,x2=0,y1=0,y2=0;
	int s=a[id[1]]+a[id[4]]+a[id[7]];
	for (int i=20;i>=0;i--)
		if (x1+(1<<i)<=xt&&psumx[x1+(1<<i)]<=s)
			x1+=1<<i;
	if (psumx[x1]!=s)
		return;
	s+=a[id[2]]+a[id[5]]+a[id[8]];
	for (int i=20;i>=0;i--)
		if (x2+(1<<i)<=xt&&psumx[x2+(1<<i)]<=s)
			x2+=1<<i;
	if (psumx[x2]!=s)
		return;
	s=a[id[1]]+a[id[2]]+a[id[3]];
	for (int i=20;i>=0;i--)
		if (y1+(1<<i)<=yt&&psumy[y1+(1<<i)]<=s)
			y1+=1<<i;
	if (psumy[y1]!=s)
		return;
	s+=a[id[4]]+a[id[5]]+a[id[6]];
	for (int i=20;i>=0;i--)
		if (y2+(1<<i)<=yt&&psumy[y2+(1<<i)]<=s)
			y2+=1<<i;
	if (psumy[y2]!=s)
		return;
	if (check(x1,x2,y1,y2)){
		printf("%.10lf %.10lf\n",0.5+hx.v[x1],0.5+hx.v[x2]);
		printf("%.10lf %.10lf\n",0.5+hy.v[y1],0.5+hy.v[y2]);
		exit(0);
	}
}
int main(){
	scanf("%d",&n);
	hx.clear(),hy.clear();
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		hx.push(x[i]),hy.push(y[i]);
	}
	for (int i=1;i<=9;i++)
		scanf("%d",&a[i]);
	hx.Hash(),hy.Hash();
	for (int i=1;i<=n;i++)
		x[i]=hx.find(x[i]),y[i]=hy.find(y[i]);
	xt=hx.tot,yt=hy.tot;
	for (int i=1;i<=xt;i++)
		points[i].clear();
	for (int i=1;i<=n;i++)
		points[x[i]].push_back(y[i]);
	build(root[0],1,yt);
	for (int i=1;i<=xt;i++)
		for (int j=0;j<points[i].size();j++)
			update(root[i-1],root[i],1,yt,points[i][j]);
	for (int i=1;i<=n;i++)
		psumx[x[i]]++,psumy[y[i]]++;
	for (int i=1;i<=xt;i++)
		psumx[i]+=psumx[i-1];
	for (int i=1;i<=yt;i++)
		psumy[i]+=psumy[i-1];
	n=9;
	for (int i=1;i<=n;i++)
		id[i]=i;
	for (int xxx=1;xxx<=362880;xxx++){
		Try();
		next_permutation(id+1,id+n+1);
	}
	puts("-1");
	return 0;
}