#include <cstdio>
const int N=2e5+10;
int T,n;char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,s+1);int ans=1;
		for(int i=1;i<(n<<1);++i)ans+=s[i]=='('&&s[i+1]=='(';
		printf("%d\n",ans);
	}
	return 0;
}