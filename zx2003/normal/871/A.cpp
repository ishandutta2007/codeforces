#include<cstdio> 
int q,n,m;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		if(n<4){
			puts("-1");continue;
		}
		m=n&3;
		if(m==0)printf("%d\n",n>>2);
		if(m==1){
			if(n<9)puts("-1");
				else printf("%d\n",(n-5)>>2);
		}
		if(m==2){
			if(n<6)puts("-1");
				else printf("%d\n",(n-2)>>2);
		}
		if(m==3){
			if(n<15)puts("-1");
				else printf("%d\n",(n-11)/4+1);
		}
	}
}