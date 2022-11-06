#include<stdio.h>
#include<memory.h>
int p[22][22],n,t;
char c[200002],d[200002];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s%s",&n,c+1,d+1);
		memset(p,0,sizeof(p));
		bool f=0;
		for(int i=1;i<=n;i++){
			if(c[i]>d[i])f=1;p[c[i]-'a'][d[i]-'a']=1;
		}if(f){puts("-1");continue;}int ans=0;
		for(int i=0;i<20;i++){
			int minp=-1;
			for(int j=i+1;j<20;j++)if(p[i][j]){minp=j;break;}
			if(~minp){
				for(int j=minp+1;j<20;j++)if(p[i][j]&&j!=minp)p[minp][j]=1;
				ans++;
			}
		}printf("%d\n",ans);
	}
}