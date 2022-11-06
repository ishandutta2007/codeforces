#include<stdio.h>
#define mod 998244353
void qwq(int *a,int n){
	for(int i=0;i<n;i++)if(i<(i^n-1))a[i]^=a[i^n-1]^=a[i]^=a[i^n-1];
}
void qwq(int *a,int *b,int n){
	for(int i=0;i<n;i++)a[i]=(long long)a[i]*(long long)b[i]%mod;
}
void qwq(int *a,int *b,int n,bool typ){
	for(int i=0;i<n;i++){
		a[i]+=typ?-b[i]:b[i];
		while(a[i]>=mod)a[i]-=mod;
		while(a[i]<0)a[i]+=mod;
	}
}
void change(int &a,int &b,bool typ1,int typ2){//&^|
	typ2&1?(a+=b,b=a-b-b,typ1?(a=a&1?(long long)a+mod>>1:a>>1,b=b&1?b+mod>>1:b>>1):0):typ2?typ1?(b-=a):(b+=a):typ1?(a-=b):(a+=b);
	while(a>=mod)a-=mod;while(a<0)a+=mod;
	while(b>=mod)b-=mod;while(b<0)b+=mod;
}
void fwt(int *a,int *b,int n,bool typ1,int typ2){
	for(int i=0;i<n;i++)b[i]=a[i];
	for(int i=1;i<n;i<<=1)for(int j=0;j<n;j+=i<<1)for(int k=0;k<i;k++)change(b[j+k],b[i+j+k],typ1,typ2);
}
void fwt(int *a,int *b,int *c,int *d,int n,int typ){
	fwt(a,c,n,0,typ);
	fwt(b,d,n,0,typ);
	qwq(d,c,n);
	fwt(d,c,n,1,typ);
}
int a[1048576],b[1048576],c[1048576],d[1048576],n,m,gg[1048576];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		while(getchar()!='\n');
		for(int j=0;j<m;j++)gg[j]+=getchar()-'0'<<i;
	}n=1<<n;
	for(int i=0;i<m;i++)a[gg[i]]++;
	for(int i=1;i<n;i++)b[i]=b[i-(i&-i)]+1;
	for(int i=1;i<n;i++)if(b[i]>b[i^n-1])b[i]=b[i^n-1];
	fwt(a,b,c,d,n,1);int ans=1000000007;
	for(int i=0;i<n;i++)if(ans>c[i])ans=c[i];
	printf("%d",ans);
}