#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=107;
int n;
char a[3][N];
inline void work(){
	n=read();
	for(int i=1;i<=2;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		if(a[1][i]=='1' && a[2][i]=='1'){
			puts("NO");
			return ;	
		}
	puts("YES");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}