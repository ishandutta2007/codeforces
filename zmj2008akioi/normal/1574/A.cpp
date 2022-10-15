#include <cstdio>
int t,n;
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&n);
		for(register int j=0;j<n;++j){
			for(register int k=0;k<j;++k)putchar('(');
			for(register int k=0;k<j;++k)putchar(')');
			for(register int k=0;k<n-j;++k)putchar('(');
			for(register int k=0;k<n-j;++k)putchar(')');
			putchar('\n');
		}
	}
	return 0;
}