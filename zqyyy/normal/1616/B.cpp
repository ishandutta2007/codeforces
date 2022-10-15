#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
int n;
char s[100007];
inline void work(){
	n=read(),scanf("%s",s+1),s[n+1]='z'+1;
	for(int i=2;i<=n+1;i++)if(s[i]>=s[i-1]+(i!=2)){
		for(int j=1;j<i;j++)putchar(s[j]);
		for(int j=i-1;j;j--)putchar(s[j]);
		putchar('\n');
		return;
	}
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}