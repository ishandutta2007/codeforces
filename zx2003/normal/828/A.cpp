#include<cstdio>
int n,a,b,c,d,i,t;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;++i){
		scanf("%d",&t);
		if(t==1){
			if(a==0){
				if(b==0){
					if(c==0)++d;
						else --c;
				}else --b,++c;
			}else --a;
		}else{
			if(b)--b;
				else d+=2;
		}
	}
	printf("%d\n",d);
	return 0;
}