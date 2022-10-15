#include <cstdio>
#include <algorithm>
const int N=1e5+10;
int T,n;
char a[N],b[N];
bool tag;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,a+1);
		if(a[1]!='1')for(int i=1;i<=n+1;++i)b[i]='1';
		else for(int i=1;i<=n;++i)b[i]='9';
		std::reverse(a+1,a+n+1);
		for(int i=1;i<=n;++i){
			b[i]-=a[i]^48;
			if(b[i]<'0')b[i]+=10,b[i+1]--;
		}
		std::reverse(b+1,b+n+1);
		b[n+1]='\0',puts(b+1);
	}
	return 0;
}