#include<stdio.h>
int p[100002],n,t,mk[100002];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)mk[i]=0;
		for(int i=1;i<=n;i++){
			int k;scanf("%d",&k);p[i]=0;
			while(k--){
				int q;scanf("%d",&q);
				if(!p[i]&&!mk[q])p[i]=q,mk[q]=1;
			}
		}bool f=0;
		for(int i=1;i<=n;i++){
			if(!p[i]){
				int ans=0;
				for(int j=1;j<=n;j++)if(!mk[j])ans=j;
				printf("IMPROVE\n%d %d\n",i,ans);f=1;
				break;
			}
		}if(!f)puts("OPTIMAL");
	}
}