#include <cstdio>
int t,k,cnt,now=1,arr[1010];
int main(){
	scanf("%d",&t);
	while(cnt<1000){
		while(now%3==0||now%10==3)++now;
		arr[++cnt]=now++;
	}
	for(register int i=0;i<t;++i){
		scanf("%d",&k);
		printf("%d\n",arr[k]);
	}
}