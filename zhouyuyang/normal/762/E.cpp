#include<stdio.h>
#include<algorithm>
using namespace std;
long long r;
struct Z{int x,r,f;}x[100000];
int i,j,n,k,lab,rt[10011],ls[3000000],rs[3000000],d[3000000];
void A(int&p,int L,int R,int x)
{
	if(!p)p=++lab;
	if(++d[p],L==R)return;
	int m=L+R>>1;
	m<x?A(rs[p],m+1,R,x):A(ls[p],L,m,x);
}
int Q(int&p,int L,int R,int l,int r)
{
	if(l<=L&&R<=r)return d[p];
	int m=L+R>>1;
	if(l>m)return Q(rs[p],m+1,R,l,r);
	if(r<=m)return Q(ls[p],L,m,l,r);
	return Q(ls[p],L,m,l,m)+Q(rs[p],m+1,R,m+1,r);
}
int main(){
	for(scanf("%d%d",&n,&k);i<n;++i)
		scanf("%d%d%d",&x[i].x,&x[i].r,&x[i].f);
	sort(x,x+n,[](const Z&a,const Z&b){return b.r<a.r;});
	for(i=0;i<n;++i)
	{
		for(j=max(1,x[i].f-k);j<=x[i].f+k;++j)
			r+=Q(rt[j],1,1e9,x[i].x-x[i].r,x[i].x+x[i].r);
		A(rt[x[i].f],1,1e9,x[i].x);
	}
	printf("%I64d",r);
}