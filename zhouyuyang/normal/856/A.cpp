#include<bits/stdc++.h>
using namespace std;
int n,a[105],ans[105];
bool s[2000050];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(s,0,sizeof s);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans[0]=0;
		for(int i=1;i<=n;i++){
			for(int p=ans[i-1]+1;p<=1000000;p++){
				bool f=1;
				for(int j=1;j<=n;j++){
					if(s[a[j]+p]){
						f=0;
						break;
					}
				}
				if(f){
					ans[i]=p;
					for(int j=1;j<=n;j++)
						s[a[j]+ans[i]]=1;
					break;
				}
			}
		}
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}