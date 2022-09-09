#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mo=998244353;
int a[N],n,i,j,k,xb,mi[30],f1[30],f2[30],c[30],ans;
int main(){
	for(i=*mi=1;i<30;++i)mi[i]=10ll*mi[i-1]%mo;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		static int b[N];
		for(xb=0,j=a[i];j;j/=10)b[++xb]=j%10;
		++c[xb];
		for(j=1;j<=10;++j)
			for(k=1;k<=xb;++k)
				f1[j]=(f1[j]+1ll*mi[k-1+min(j,k)]*b[k])%mo,
				f2[j]=(f2[j]+1ll*mi[k-1+min(j,k-1)]*b[k])%mo; 
	}
	for(j=1;j<=10;++j)ans=(ans+1ll*(f1[j]+f2[j])*c[j])%mo;
	printf("%d\n",ans);
	return 0;
}