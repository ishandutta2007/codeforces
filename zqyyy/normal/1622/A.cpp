#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
int l[4];
inline void work(){
	l[1]=read(),l[2]=read(),l[3]=read();
	sort(l+1,l+4);
	if(l[1]+l[2]==l[3] || (l[1]%2==0 && l[2]==l[3]) || (l[3]%2==0 && l[1]==l[2]))puts("YES");
	else puts("NO");	
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}