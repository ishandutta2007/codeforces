#include<stdio.h>
bool mk[100002];
int n,k,s,cnt,cntt=0;
bool gett(int id){
	printf("? %d\n",id+1);
	fflush(stdout);cntt++;
	char c=getchar();
	while(c<'!')c=getchar();
	return c=='Y';
}
void work(int tot,int bas){
	if(tot<=0){
		int CNT=0;
		for(int i=0;i<n;i++)CNT+=!mk[i];
		printf("! %d",CNT);
		return;
	}
	for(int i=1;i<tot-1;i++){
		for(int j=0;j<s;j++){
			int id=bas+j;
			mk[id]|=gett(id);
		}for(int j=0;j<s;j++){
			int id=bas+j+s*i;
			mk[id]|=gett(id);
		}for(int j=0;j<s;j++){
			int id=bas+j+s*(tot-1);
			mk[id]|=gett(id);
		}printf("R\n");
	}for(int j=0;j<s;j++){
		int id=bas+j;
		mk[id]|=gett(id);
	}for(int j=0;j<s;j++){
		int id=bas+j+s*(tot-1);
		mk[id]|=gett(id);
	}printf("R\n");
	work(tot-2,bas+s);
}
int main(){
	scanf("%d%d",&n,&k);
	if(n==1){
		printf("! 1");
		return 0;
	}
	s=k==1?1:k>>1;
	cnt=n/s;
	work(cnt,0);//return cntt;
}