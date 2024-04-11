#include <cstdio>
int t,n,ans;
char str[110];
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d\n%s",&n,str);
		ans=0;
		for(register int j=0;j<n;++j){
			if(str[j]!='0'){
				if(j==n-1)ans+=str[j]-'0';
				else ans+=str[j]-'0'+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}