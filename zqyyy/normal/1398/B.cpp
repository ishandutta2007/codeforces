#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int a[101];
char s[105];
int l,cnt;
inline void work(){
	scanf("%s",s+1);l=strlen(s+1);
	cnt=0;int i=1;
	while(i<=l){
		if(s[i]=='0'){++i;continue;}
		int x=0;
		while(s[i]=='1'){
			x++,i++;
			if(i>l)break;
		}
		a[++cnt]=x;
	}
	sort(a+1,a+cnt+1);
	int ans=0;
	for(re int i=cnt;i>0;i-=2)ans+=a[i];
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}