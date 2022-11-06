#include<stdio.h>
int m,cnt[3],a,t;
int main(){
	if(!t)scanf("%d",&t);
	scanf("%d",&m);t--;cnt[0]=cnt[1]=cnt[2]=0;
	while(m--)scanf("%d",&a),cnt[a%3]++;
	printf("%d\n",cnt[0]+(cnt[1]<cnt[2]?cnt[1]:cnt[2])+(cnt[1]<cnt[2]?(cnt[2]-cnt[1]):(cnt[1]-cnt[2]))/3);
	if(t)main();
}