#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 200011
//#define DEBUG
#define BIT 31
using namespace std;
long long d[maxn],b[maxn],c[maxn],a[maxn];
int n;
bool checker(){
	static int B[30]={0};
	static long long p[maxn]={0},q[maxn]={0};
	for(int i=BIT;i>=0;--i)
		for(int j=1;j<=n;++j)
			if((a[j]>>i)&1)B[i]++;
	for(int i=1;i<=n;++i){
		long long res=0;
		for(int j=0;j<=BIT;++j)if((a[i]>>j)&1)
			res+=(1ll*B[j])<<j;
		p[i]=res;res=0;
		for(int j=0;j<=BIT;++j){
			if((a[i]>>j)&1)res+=1ll*n*(1ll<<j);
			else res+=(1ll*B[j])<<j;
		}
		q[i]=res;
	}
	for(int i=1;i<=n;++i)if(p[i]!=b[i])return false;
	for(int i=1;i<=n;++i)if(q[i]!=c[i])return false;
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&b[i]);
	for(int i=1;i<=n;++i)scanf("%I64d",&c[i]);
	for(int i=1;i<=n;++i){
		if(b[i]<0||c[i]<0){
			puts("-1");return 0;
		} else d[i]=b[i]+c[i];
	}
	long long ls=0,rs;
	for(int i=1;i<=n;++i)ls+=d[i];
	if(ls%(2*n)!=0){
		puts("-1");return 0;
	} else rs=ls/(2*n);
	for(int i=1;i<=n;++i){
		if((d[i]-rs)%n!=0||d[i]<rs){
			puts("-1");return 0;
		} else a[i]=(d[i]-rs)/n;
	}
	if(!checker()){
		puts("-1");return 0;
	}
	//Warning!!!!!!
//	#ifdef DEBUG
//	printf("%d \n",n);
//	#endif
	for(int i=1;i<=n;++i)printf("%I64d ",a[i]);
}