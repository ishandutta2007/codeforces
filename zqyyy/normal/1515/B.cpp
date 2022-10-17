#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
inline bool is_sqr(int n){
	for(int i=1;i*i<=n;i++)
		if(i*i==n)return 1;
	return 0;
}
int n;
inline void work(){
	n=read();
	if(((n%4==0 && is_sqr(n/4)) || (n%2==0 && is_sqr(n/2))) && n!=1)puts("YES");
	else puts("NO");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}