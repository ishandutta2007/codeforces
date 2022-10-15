#include <cstdio>
const int N=1e6+10;
int T,n,m;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		if(n>m||(n%2==0&&m%2!=0)){puts("No");continue;}
		puts("Yes");
		if(n%2==0){
			for(int i=0;i<n-2;++i)--m,printf("1 ");
			m>>=1,printf("%d %d\n",m,m);
		}
		else{
			for(int i=0;i<n-1;++i)--m,printf("1 ");
			printf("%d\n",m);
		}
	}
	return 0;
}