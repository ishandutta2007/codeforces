#include <cstdio>
int t,n,m,k;
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d %d",&n,&m,&k);
		if(m<n-1||(long long)m>(long long)n*(n-1)/2)printf("No\n");
		else if(n==1){
			if(k<=1)printf("No\n");
			else printf("Yes\n");
		}
		else if(k<=2)printf("No\n");
		else if(k==3){
			if((long long)m==(long long)n*(n-1)/2)printf("Yes\n");
			else printf("No\n");
		}
		else printf("Yes\n");
	}
	return 0;
}