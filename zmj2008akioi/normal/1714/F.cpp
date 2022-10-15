#include <cstdio>
const int N=2e5+10;
int T,n,a,b,c,stk[N];
void calc(int p,int q,int r,int a,int b,int c){
	puts("YES");int cnt=3,top=0;
	stk[++top]=p;
	for(int i=1;i<a;++i)stk[++top]=++cnt;
	stk[++top]=q;
	int dis=(b+c-a)>>1;
	if(b+c==a){
		if(a!=n-1){
			printf("1 %d\n",stk[b-dis+1]);
			stk[b-dis+1]=r;
			for(int i=1;i<top;++i)printf("%d %d\n",stk[i],stk[i+1]);
		}
		else{
			cnt=3;
			for(int i=2;i<top;++i)stk[i]=0;
			stk[b+1]=r;
			for(int i=2;i<top;++i)if(!stk[i])stk[i]=++cnt;
			for(int i=1;i<top;++i)printf("%d %d\n",stk[i],stk[i+1]);
		}
	}
	else{
		for(int i=1;i<top;++i)printf("%d %d\n",stk[i],stk[i+1]);
		int k=stk[b-dis+1];stk[top=1]=k;
		for(int i=1;i<dis;++i)stk[++top]=++cnt;
		stk[++top]=r;
		for(int i=1;i<top;++i)printf("%d %d\n",stk[i],stk[i+1]);
	}
	while((++cnt)<=n)printf("1 %d\n",cnt);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&n,&a,&b,&c);
		if((a+b+c)&1){puts("NO");continue;}
		if(a+b<c||a+c<b||b+c<a){puts("NO");continue;}
		if(((a+b+c+2)>>1)>n){puts("NO");continue;}
		calc(1,2,3,a,c,b);
	}
	return 0;
}