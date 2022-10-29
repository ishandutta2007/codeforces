#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define maxn 510
using namespace std;
int a[maxn],b[maxn],s[maxn],c[maxn],p[maxn],n,k,i,j;
int ope[maxn][2],otop;
bool check(int l,int r,int xd){
//	printf("<%d,%d,%d>",l,r,xd);
	for(int i=l;i<r;++i){
//		for(int j=l;j<=r-(i-l);++j)printf("%d ",a[j]);
//		putchar(10);
		int mx=0,p=0,q=0;
		for(int j=l;j<r-(i-l);++j)
			if(mx<=a[j]+a[j+1]&&a[j]!=a[j+1])mx=a[j]+a[j+1],p=j;
//		printf("[%d,%d]",mx,p);
		if(!mx)return false;
		if(a[p]<a[p+1]){
			ope[otop][0]=p+1+xd;
			ope[otop++][1]=1;
		} else {
			ope[otop][0]=p+xd;
			ope[otop++][1]=2;
		} 
		a[p]=a[p]+a[p+1];
		if(i==r-1)return true;
		for(int j=p+2;j<=r-(i-l);++j)
			a[j-1]=a[j];
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),s[i]=a[i]+s[i-1];
	scanf("%d",&k);
	for(int i=1;i<=k;++i)
		scanf("%d",&b[i]);
	bool fla=false;
	for(i=1,j=1;i<=k;++i){
		for(;j<=n&&b[i]!=s[j]-s[p[i-1]];++j);
		if(j<=n&&b[i]==s[j]-s[p[i-1]])p[i]=j;
		else {
			printf("NO");return 0;
		}
	}
	if(j<n){
		printf("NO");
		return 0;
	}
	for(int i=1;i<=k;++i){
		if(!check(p[i-1]+1,p[i],-(p[i-1]-i+1))){
			printf("NO");return 0;
		}
	}
	printf("YES\n");
	for(int i=0;i<otop;++i){
		printf("%d %c\n",ope[i][0],ope[i][1]==1?'L':'R');
	}
}