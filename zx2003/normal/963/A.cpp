#include<bits/stdc++.h> 
const int N=100005,mo=1000000009;
int pow(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int n,a,b,k,i,p,q,ans;
char c[N];
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&k);
	scanf("%s",c);
	p=1ll*b*pow(a,mo-2)%mo;q=1;
	for(i=0;i<=k-1;++i){
	//	if(i)
	//	ans=(ans+mo+1ll*(c[i]=='+'?1:-1)
	//		*(1ll*(pow(p,i*(n+1)/k+i)+mo-1)*pow(pow(p,i)+mo-1,mo-2)%mo+mo-1))%mo;
				//else ans=(ans+mo+(c[i]=='+'?1:-1))%mo;
		ans=(ans+1ll*q*(c[i]=='+'?1:mo-1))%mo;
		q=1ll*q*p%mo;
	}
	if(q==1)ans=1ll*ans*((n+1)/k)%mo*pow(a,n)%mo;else{
		p=pow(q,(n+1)/k);
		p=1ll*(p+mo-1)*pow(q+mo-1,mo-2)%mo;
		ans=1ll*ans*pow(a,n)%mo*p%mo;
	}
	std::cout<<ans<<'\n';
	return 0;
}