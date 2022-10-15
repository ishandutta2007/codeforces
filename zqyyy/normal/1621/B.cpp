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
int n,mn,mx,c[N];
inline void work(){
	n=read(),mn=1e9+1,mx=0;
	int a=0,b=0,d=0;c[0]=2e9+1;
	for(int i=1;i<=n;i++){
		int l=read(),r=read();c[i]=read();
		if(mn>l)d=0,a=i;
		else if(mn==l && c[a]>c[i])a=i;
		if(mx<r)d=0,b=i;
		else if(mx==r && c[b]>c[i])b=i;
		if((mn>=l && mx<r) || (mn>l && mx<=r))d=i;
		else if(mn==l && mx==r && c[d]>c[i])d=i;
		mn=min(mn,l),mx=max(mx,r);
		printf("%d\n",min(c[a]+c[b],c[d]));
	}
}
int main(){
	int test=read();
	while(test--)work();
    return 0;
}