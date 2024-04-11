#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,m;
char s[N],t[N];
inline void work(){
	scanf("%s",s+1),scanf("%s",t+1);
	n=strlen(s+1),m=strlen(t+1);
	if(n<m){puts("NO");return;}
	for(int o=0;o<2;o++){
		int x=o,k=1,lst=0;
		for(int i=1;i<=n;i++)
			if(x==i%2 && s[i]==t[k] && k<=m)k++,lst=i,x^=1;
		if(k==m+1 && (n-lst+1)&1){puts("YES");return;}
	}
	puts("NO");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}