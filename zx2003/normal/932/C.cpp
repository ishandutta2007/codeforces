#include<bits/stdc++.h>
const int N=1000005;
int f[N],pr[N],i,n,a,b,j,c[N],xb,lst;
char obuf[1<<25],*oh=obuf;
template<typename T>inline void write(T x){
	static int buf[30],xb;
	for(xb=0;x;x/=10)buf[++xb]=x%10;
	for(;xb;)*oh++=buf[xb--]|48;
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(*f=i=1;i<=n;++i){
		if(i>=a && f[i-a])f[i]=1,pr[i]=a;
		if(i>=b && f[i-b])f[i]=1,pr[i]=b;
	}
	if(!f[n])return puts("-1"),0;
	for(i=n;i;i-=pr[i])c[++xb]=pr[i];
	for(i=lst=1;i<=xb;++i){
		for(j=lst;j<lst+c[i]-1;++j)write(j+1),*oh++=' ';
		write(lst);*oh++=' ';lst+=c[i];
	}
	return fwrite(obuf,1,oh-obuf,stdout),0;
}