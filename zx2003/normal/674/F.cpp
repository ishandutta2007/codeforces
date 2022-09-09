#include<bits/stdc++.h>
typedef unsigned ui;
ui mi,ans,a[135],b[135],c[135],r,n,p,q,i,j;
inline void mul(ui*a,ui*b){
	memset(c,0,p+1<<2);
	for(int i=0;i<=p;++i)for(int j=0;i+j<=p;++j)c[i+j]+=a[i]*b[j];
	memcpy(a,c,p+1<<2);
}
int main(){
	std::cin>>n>>p>>q;n<=p?p=n-1:0;
	*a=a[1]=*b=1;
	for(i=0;i<30;++i,mul(a,a))if(n>>i&1)mul(b,a);
	for(i=1;i<=q;ans^=i*r,++i)
		for(j=r=0,mi=1;j<=p;++j)r+=b[j]*mi,mi*=i;
	std::cout<<ans<<'\n';
	return 0;
}