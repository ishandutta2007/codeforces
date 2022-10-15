#include <cstdio>
int t,n;
char str[100010];
bool tag;
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&n);
		scanf("%s",str+1);
		tag=0;
		for(register int j=1;j<=n/2;++j){
			if(str[j]=='0'){
				if(!tag){
					tag=true;
					printf("%d %d %d %d\n",j+1,n,j,n);
				}
			}
		}
		for(register int j=n/2+1;j<=n;++j){
			if(str[j]=='0'){
				if(!tag){
					tag=true;
					printf("%d %d %d %d\n",1,j,1,j-1);
				}
			}
		}
		if(!tag)printf("%d %d %d %d\n",1,n/2*2,1,n/2);
	}
	return 0;
}