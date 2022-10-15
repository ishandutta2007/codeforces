#include <cstdio>
int t,l,r;
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d",&l,&r);
		if(l>r/2)printf("%d\n",r-l);
		else printf("%d\n",(r-1)/2);
	}
	return 0;
}