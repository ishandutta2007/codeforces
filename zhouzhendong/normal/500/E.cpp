#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,L[N],R[N],Next[N][20],Cost[N][20];
int Max[N<<2];
void update(int rt,int L,int R,int x,int v){
	Max[rt]=max(Max[rt],v);
	if (L==R)
		return;
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		update(ls,L,mid,x,v);
	else
		update(rs,mid+1,R,x,v);
}
int query(int rt,int L,int R,int xL,int xR){
	if (L>xR||xL>R||xL>xR)
		return 0;
	if (xL<=L&&R<=xR)
		return Max[rt];
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	return max(query(ls,L,mid,xL,xR),query(rs,mid+1,R,xL,xR));
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&L[i],&R[i]),R[i]+=L[i];
	memset(Max,0,sizeof Max);
	L[n+1]=2e9;
	for (int i=0;i<20;i++)
		Next[n+1][i]=n+1;
	for (int i=n;i>=1;i--){
		int p=i;
		for (int j=19;j>=0;j--)
			if (p+(1<<j)<=n&&L[p+(1<<j)]<=R[i])
				p+=1<<j;
		R[i]=max(query(1,1,n,i+1,p),R[i]);
		update(1,1,n,i,R[i]);
		p=i;
		for (int j=19;j>=0;j--)
			if (p+(1<<j)<=n&&L[p+(1<<j)]<=R[i])
				p+=1<<j;
		Next[i][0]=p+1;
		Cost[i][0]=L[p+1]-R[i];
		for (int j=1;j<20;j++){
			Next[i][j]=Next[Next[i][j-1]][j-1];
			Cost[i][j]=Cost[i][j-1]+Cost[Next[i][j-1]][j-1];
		}
	}
/*	for (int i=1;i<=n;i++,puts(""))
		for (int j=0;j<20;j++)
			printf("(%d,%d)\n",Next[i][j],Cost[i][j]);*/
	scanf("%d",&q);
	while (q--){
		int a,b;
		scanf("%d%d",&a,&b);
		int ans=0;
		for (int i=19;i>=0;i--)
			if (Next[a][i]<=b){
				ans+=Cost[a][i];
				a=Next[a][i];
			}
		printf("%d\n",ans);
	}
	return 0;
}