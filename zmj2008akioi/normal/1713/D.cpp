#include <cstdio>
const int N=2e5+10;
int T,n,f[N],g[N];
int query(int a,int b){
	printf("? %d %d\n",a,b),fflush(stdout);
	int t;scanf("%d",&t);return t;
}
void answer(int x){printf("! %d\n",x),fflush(stdout);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=(1<<n);++i)f[i]=i;
		while(n>=2){
			for(int j=1;j<=(1<<(n-2));++j){
				int t=(j-1)<<2,a=f[t+1],b=f[t+2],c=f[t+3],d=f[t+4];
				int p=query(b,c);
				if(!p){
					int w=query(a,d);
					if(w==1)g[j]=a;
					else g[j]=d;
				}
				else{
					if(p==1){
						int w=query(b,d);
						if(w==1)g[j]=b;
						else g[j]=d;
					}
					else{
						int w=query(a,c);
						if(w==1)g[j]=a;
						else g[j]=c;
					}
				}
			}
			n-=2;
			for(int j=1;j<=(1<<n);++j)f[j]=g[j];
		}
		if(n==1){
			int w=query(f[1],f[2]);
			if(w==1)answer(f[1]);
			else answer(f[2]);
		}
		else answer(f[1]);
	}
	return 0;
}