#include <bits/stdc++.h>
using namespace std;
#define y1 ___y1__
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int W,H,x1,y1,x2,y2,w,h;
int n,m;
inline void work(){
	W=read(),H=read(),x1=read(),y1=read(),x2=read(),y2=read(),w=read(),h=read();
	if(x2-x1+w>W && y2-y1+h>H){puts("-1");return;}
	n=1e9,m=1e9;
	if(x2-x1+w<=W)n=max(0,w-max(x1,W-x2));
	if(y2-y1+h<=H)m=max(0,h-max(y1,H-y2));
	int ans=min(n,m);
	printf("%.9lf\n",(double)ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}