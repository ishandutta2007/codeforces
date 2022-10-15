#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e4+7;
int n;
char s[N];
inline void work(){
	n=read(),scanf("%s",s+1);
	int k=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='0')k=i;
	if(!k){printf("1 %d %d %d\n",n/2,n-(n/2)+1,n);return;}
	if(k<=n/2)printf("%d %d %d %d\n",k,n,k+1,n);
	else printf("%d %d %d %d\n",1,k,1,k-1);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}