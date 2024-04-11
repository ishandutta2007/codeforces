#include <cstdio>
int t,a,b,c;
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d %d",&a,&b,&c);
		if(a>b)a^=b^=a^=b;
		if(a>b/2||c>(b-a)*2)printf("-1\n");
		else if(c<=b-a)printf("%d\n",c+(b-a));
		else printf("%d\n",c-(b-a));
	}
}