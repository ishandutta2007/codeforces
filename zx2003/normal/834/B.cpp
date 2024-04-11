#include<cstdio>
#include<cstring>
const int N=1000005;
int n,k,a[N],i;
bool b[300];
char s[N];
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	for(i=1;i<=n;++i)a[i]+=!b[s[i]],b[s[i]]=1;
	memset(b,0,sizeof b);
	for(i=n;i;--i)a[i+1]-=!b[s[i]],b[s[i]]=1;
	for(i=1;i<=n && a[i-1]<=k;++i)a[i]+=a[i-1];
	return puts(i<=n?"YES":"NO"),0;
}