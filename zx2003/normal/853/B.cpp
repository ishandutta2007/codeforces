#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=100005,K=N*10;
ll succ[K],prec[K],s,ans;
int n,m,k,i,mt,x,b[N],j;
struct data{
	int d,f,t,c;
	bool operator<(const data&rhs)const{
		return d<rhs.d;
	}
}a[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;++i)scanf("%d%d%d%d",&a[i].d,&a[i].f,&a[i].t,&a[i].c),mt=max(mt,a[i].d);
	sort(a+1,a+m+1);
	for(i=1,x=n;i<=n;++i)b[i]=-1;
	for(i=j=1;i<=mt;++i){
		for(;j<=m && a[j].d<=i;++j)
			if(a[j].t==0){
				if(b[a[j].f]==-1)s+=b[a[j].f]=a[j].c,--x;
					else s-=b[a[j].f],s+=b[a[j].f]=min(b[a[j].f],a[j].c);
			}
		if(!x)prec[i]=s;
			else prec[i]=-1;
	}
	for(i=1,x=n;i<=n;++i)b[i]=-1;
	ans=-1;
	for(i=mt,s=0,j=m;i;--i){
		for(;j && a[j].d>=i;--j)
			if(a[j].f==0){
				if(b[a[j].t]==-1)s+=b[a[j].t]=a[j].c,--x;
					else s-=b[a[j].t],s+=b[a[j].t]=min(b[a[j].t],a[j].c);
			}
		if(!x && i-k-1>=1 && prec[i-k-1]!=-1 && (ans==-1 || prec[i-k-1]+s<ans))
			ans=prec[i-k-1]+s;
	}
	cout<<ans<<endl;
	return 0;
}