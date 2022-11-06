#include<stdio.h>
#include<vector>
#include<bitset>
std::bitset<2002>ans;
int n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans.reset();ans[0]=1;
		int cnt=1,maxx;scanf("%d",&maxx);
		for(int i=2;i<=n+n;i++){
			int p;scanf("%d",&p);
			if(p<maxx)cnt++;
			else{
				if(cnt<=n)ans|=ans<<cnt;cnt=1;maxx=p;
			}
		}if(cnt<=n)ans|=ans<<cnt;
		puts(ans[n]?"YES":"NO");
	}
}