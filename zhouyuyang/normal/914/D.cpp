#include<bits/stdc++.h>
#define N 500005
using namespace std;
int a[N];
int G[N*3];
int id[100],L[100],R[100];
int n,q,tot;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void build(int k,int l,int r){
	if (l==r) return G[k]=a[l],void(0);
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	G[k]=gcd(G[k*2],G[k*2+1]);
}
void change(int k,int l,int r,int p,int v){
	if (l==r) return G[k]=v,void(0);
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	G[k]=gcd(G[k*2],G[k*2+1]);
}
void getblock(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		id[++tot]=k;
		L[tot]=l; R[tot]=r;
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) getblock(k*2,l,mid,x,y);
	else if (x>mid) getblock(k*2+1,mid+1,r,x,y);
	else getblock(k*2,l,mid,x,mid),
		 getblock(k*2+1,mid+1,r,mid+1,y);
}
bool check(int k,int l,int r,int v){
	if (l==r) return 1;
	if ((G[k*2]%v!=0)&&(G[k*2+1]%v!=0))
		return 0;
	int mid=(l+r)/2;
	if (G[k*2]%v!=0) return check(k*2,l,mid,v);
	if (G[k*2+1]%v!=0) return check(k*2+1,mid+1,r,v);
	return 1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&q);
	while (q--){
		int fl,x,y,z;
		scanf("%d%d%d",&fl,&x,&y);
		if (fl==2){
			change(1,1,n,x,y);
			continue;
		}
		scanf("%d",&z);
		tot=0;
		getblock(1,1,n,x,y);
		int sum=0;
		for (int i=1;i<=tot;i++)
			if (G[id[i]]%z) sum++;
		//printf("%d",sum);
		if (sum==0){
			puts("YES");
			continue;
		}
		if (sum>1){
			puts("NO");
			continue;
		}
		for (int i=1;i<=tot;i++)
			if (G[id[i]]%z){
				if (check(id[i],L[i],R[i],z))
					puts("YES");
				else puts("NO");
			}
	}
}