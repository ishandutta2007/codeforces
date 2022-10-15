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
inline void work(){
	n=read();int sum=0;
	for(int i=1;i<=n;i++)sum+=read();
	printf("%d\n",sum%n!=0?1:0);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}