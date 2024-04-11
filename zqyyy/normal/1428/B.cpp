#include <cstdio>
#include <cctype>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int MAXN=3e5+1;
int n,ans;
bool flg1,flg2,a[MAXN];
char s[MAXN];
inline void work(){
	n=read(),scanf("%s",s);
	flg1=flg2=1;ans=0;
	for(re int i=0;i<n;i++)a[i]=1;
	for(re int i=0;i<n;i++){
		flg1&=(s[i]=='-' || s[i]=='<');
		flg2&=(s[i]=='-' || s[i]=='>');
		if(s[i]=='-')ans+=a[i]+a[(i+1)%n],a[i]=a[(i+1)%n]=0;
	}
	if(flg1 || flg2)printf("%d\n",n);
	else printf("%d\n",ans);
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}