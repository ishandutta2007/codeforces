#include <cstdio>
const int N=1e6+10;
int T,n,m,k,a[N],b[N];
long long ca[N];
bool chk(int x){
	while(x%m==0)x/=m;
	return x==1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]),ca[i]=1;
			while(a[i]%m==0)a[i]/=m,ca[i]*=m;
		}
		a[n+1]=0,scanf("%d",&k);int p=1;bool tag=true;
		for(int i=1;i<=k;++i)scanf("%d",&b[i]);
		for(int i=1;i<=k;++i){
			while(p<=n&&!ca[p])++p;
			if(p>n||b[i]%a[p]!=0||!chk(b[i]/a[p])){tag=false;break;}
			while(a[p]==a[p+1])ca[p+1]+=ca[p],++p;
			if(ca[p]<b[i]/a[p]){tag=false;break;}
			ca[p]-=b[i]/a[p];
		}
		tag&=p==n&&ca[n]==0,puts(tag?"Yes":"No");
	}
	return 0;
}