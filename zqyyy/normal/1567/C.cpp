#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
char s[14];
inline void work(){
	scanf("%s",s+1);int n=strlen(s+1),x=0,y=0;
	for(int i=1;i<=n;i+=2)x=x*10+s[i]-'0';
	for(int i=2;i<=n;i+=2)y=y*10+s[i]-'0';
	x++,y++;
	printf("%lld\n",1ll*x*y-2);	
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}