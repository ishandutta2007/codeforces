#include<cstdio>
int a[2005],i,j,n,d,x,s;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	if(n==1)return puts(a[1]==1?"0":"-1"),0;
	for(i=1;i<=n;++i)x+=a[i]>1;
	for(d=gcd(a[1],a[2]),i=2;i<n;++i)d=gcd(d,gcd(a[i],a[i+1]));
	if(d>1)return puts("-1"),0;s=n;
	for(i=1;i<=n;++i)if(a[i]==1)s=1;
	if(s==1)return printf("%d\n",x),0;
	for(i=1;i<n;++i){
		for(d=gcd(a[i],a[i+1]),j=i+1;d>1 && j<n;++j)
			d=gcd(d,gcd(a[j],a[j+1]));
		if(d==1 && j-i+1<s)s=j-i+1;
	}
	printf("%d\n",x+s-2);
	return 0;
}