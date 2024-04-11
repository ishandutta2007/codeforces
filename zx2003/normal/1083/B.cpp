#include<bits/stdc++.h>
const int N=5e5+5;
int n,i,j,a[N];
long long ans,z,k;
char s[N],t[N];
int main(){
	scanf("%d%lld%s%s",&n,&k,s+1,t+1);
	if(k==1){printf("%d\n",n);return 0;}
	for(i=1;i<=n && s[i]==t[i];++i);ans=n*2-i+1;k-=2;
	for(++i;i<=n;++i){
		if(s[i]=='a')++a[n-i+1];
		if(t[i]=='b')++a[n-i+1];
	}
	for(i=n;i && k>0;--i){
		int x=std::min(z+a[i],k);
		ans+=1ll*i*x;k-=x;z=z*2+a[i];
	}
	printf("%lld\n",ans);
}