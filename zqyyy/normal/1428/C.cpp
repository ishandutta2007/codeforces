#include <cstdio>
#include <cctype>
#include <cstring>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int MAXN=2e5+1;
int n,ans,tp,id[MAXN];
char s[MAXN];
bool vis[MAXN];
inline void work(){
	scanf("%s",s+1);n=ans=strlen(s+1);
	for(re int i=1;i<=n;i++)vis[i]=0;
	tp=0;
	for(re int i=1;i<=n;i++){
		if(s[i]=='A')id[++tp]=i;
		else if(tp){
			vis[id[tp--]]=1;
			vis[i]=1,ans-=2;
		}
	}
	int sum=0;
	for(re int i=1;i<=n;i++){
		if(vis[i])continue;
		if(s[i]=='A')break;
		sum++;
	}
	ans-=(sum/2)<<1;
	printf("%d\n",ans);
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}