#include<stdio.h>
long long n,k,h,mk[100002];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		if(k==1){
			for(int i=1,j;i<=n;i++)scanf("%d",&j);
			puts("YES");
		}else{
			bool f=1;
			for(int i=0;i<=100;i++)mk[i]=0;
			for(int i=1;i<=n;i++){
				scanf("%lld",&h);int j=0;
				while(h){
					int g=h%k;
					if(g){
						if(g>1||mk[j])f=0;
						mk[j]=1;
					}h/=k;j++;
				}
			}puts(f?"YES":"NO");
		}
	}
}