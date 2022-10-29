#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
struct data{int lc,rc,sum;}s[maxn*30];
int rt[maxn],l,r,k,n,m,ptr;
void modify(int rt1,int& rt2,int l,int r,int k){
	rt2=++ptr,s[rt2]=s[rt1],s[rt2].sum++;
	if(l==r)return ;
	int mid=l+r>>1;
	if(k<=mid)modify(s[rt1].lc,s[rt2].lc,l,mid,k);
	else modify(s[rt1].rc,s[rt2].rc,mid+1,r,k);
}
int query(int rtl,int rtr,int l,int r,int x){
	if(s[rtr].sum-s[rtl].sum<=x)return 0;
	if(l==r)return l;
	int mid=l+r>>1,y=query(s[rtl].lc,s[rtr].lc,l,mid,x);
	if(y)return y;
	else return query(s[rtl].rc,s[rtr].rc,mid+1,r,x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),modify(rt[i-1],rt[i],1,n,x);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&l,&r,&k);
		int y=query(rt[l-1],rt[r],1,n,(r-l+1)/k);
		printf("%d\n",y?y:-1);
	}
}