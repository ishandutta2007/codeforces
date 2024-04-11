#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
inline void work(){
	int a=read(),b=read(),c=read(),m=read();
	if(a<b)swap(a,b);
	if(a<c)swap(a,c);
	if(b<c)swap(b,c);
	int mn=max(0,a-(b+c)-1);
	m-=mn,a-=mn;
	if(m<0){puts("NO");return;}
	if(max(a-1,0)+max(b-1,0)+max(c-1,0)>=m)puts("YES");
	else puts("NO");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}