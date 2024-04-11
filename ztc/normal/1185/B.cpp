#include<stdio.h>
char a[1000002],k;
int t,n,p;
main(){
	if(t==0)scanf("%d",&t);
	n=1;p=1;t--;
	while((a[1]=getchar())<'!');
	while((a[++n]=getchar())>='!');n--;
	while((k=getchar())<'!');
	if(k!=a[p]){
		printf("NO\n");
		while(getchar()>='!');
		if(t>0)return main();
		return 0;
	}p++;
	while((k=getchar())>='!'){
		if(k==a[p]&&p<=n)p++;
		else if(k!=a[p-1]){
			printf("NO\n");
			while(getchar()>='!');
			if(t>0)return main();
			return 0;
		}
	}
	printf("%s\n",p>n?"YES":"NO");
	if(t>0)return main();
}