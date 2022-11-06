#include<stdio.h>
#define inf 1000000007
char c[1000002];
int n,t,m,f;
long long ans=0;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,c+1);f=0;ans=0;
		for(int i=1;c[i];i++)ans=i;
		for(int i=1;i<=n;i++){
			if(c[i]=='2'){
				if(!f){
					int nlen=ans-i+ans,det=ans-i;
					for(int j=ans+1;j<=nlen&&j<=n;j++)c[j]=c[j-det];
					if(nlen>=n)f=1;
				}ans=ans+ans-i+inf;
				if(ans>=inf)ans-=inf;
				if(ans>=inf)ans-=inf;
			}else if(c[i]=='3'){
				if(!f){
					int nlen=ans-i+ans-i+ans,det=ans-i;
					for(int j=ans+1;j<=nlen&&j<=n;j++)c[j]=c[j-det];
					if(nlen>=n)f=1;
				}ans=ans+ans-i+ans-i+inf;
				if(ans>=inf)ans-=inf;
				if(ans>=inf)ans-=inf;
				if(ans>=inf)ans-=inf;
			}
		}printf("%lld\n",ans);
	}
}