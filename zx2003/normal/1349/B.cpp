#include<bits/stdc++.h>
const int N=1e5+5;
int T,n,k,a[N],i,s,mn;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&k);mn=1<<25;s=0;
		bool fl1=0,fl2=0;
		for(i=1;i<=n;++i){
			scanf("%d",a+i);
			fl1|=a[i]==k;
			int os=s;
			s+=a[i]>=k?1:-1;
			fl2|=s-mn>=1;
			mn=std::min(mn,os);
		}
		puts(fl1 && (n==1 || fl2)?"yes":"no");
	}
}