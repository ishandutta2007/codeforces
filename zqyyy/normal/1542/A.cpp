#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=105;
int n;
inline void work(){
	n=read();int odd=0,even=0;
	for(int i=1;i<=n*2;i++)
		if(read()&1)odd++;
		else even++;
	if(odd==even)puts("Yes");
	else puts("No");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}