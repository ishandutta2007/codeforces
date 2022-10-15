#include <cstdio>
int t,k,l;
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&k);
		l=0;
		while((l+1)*(l+1)<k)++l;
		k-=l*l;
		if(k<=l+1)printf("%d %d\n",k,l+1);
		else printf("%d %d\n",l+1,2*l+2-k);
		
	}
	return 0;
}