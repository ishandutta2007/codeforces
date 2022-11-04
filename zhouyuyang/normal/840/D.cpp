#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+1;
struct nd{int ls,rs,tot;}t[N*15];
int rt[N],tot,a[N],n,m;
void build(int x,int &y,int l,int r,int k){
	y=++tot; t[y]=t[x]; t[y].tot++;
	if(l==r) return;
	int mid=l+r>>1;
	if(k<=mid) build(t[x].ls,t[y].ls,l,mid,k);
	else build(t[x].rs,t[y].rs,mid+1,r,k);
}
int get(int x,int y,int l,int r,int k){
	if(t[y].tot-t[x].tot<=k)return 1e9;
	if(l==r) return l;
	int mid=l+r>>1;
	return min(get(t[x].ls,t[y].ls,l,mid,k),get(t[x].rs,t[y].rs,mid+1,r,k));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)build(rt[i-1],rt[i],1,n,a[i]);
	for(int i=1,l,r,k;i<=m;++i){
		scanf("%d%d%d",&l,&r,&k);
		int ret=get(rt[l-1],rt[r],1,n,(r-l+1)/k);
		printf("%d\n",(ret==1e9?-1:ret));
	}
}