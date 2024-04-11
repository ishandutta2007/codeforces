#include<stdio.h>
long long cnt=0,ans=1,n,m,k,tot=0,pg;
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	while(m--){
		scanf("%lld",&n);n-=tot+1;
		if(cnt==0&&ans==1&&tot==0){
			cnt=1;
			pg=n/k;
		}else{
			if(n/k!=pg){
				ans++;
				tot+=cnt;
				n-=cnt;
				cnt=1;
				pg=n/k;
			}else cnt++;
		}
	}printf("%lld ",ans);
}