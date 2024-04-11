#include <bits/stdc++.h>
#define re register
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int a[51],b[51];
int main(){
	int t=read();
	while(t--){
		int n=read(),x=read();
		for(re int i=1;i<=n;i++)a[i]=read();
		for(re int i=1;i<=n;i++)b[i]=read();
		reverse(b+1,b+n+1);
		bool flg=1;
		for(re int i=1;i<=n;i++)
			if(a[i]+b[i]>x){flg=0;break;}
		puts(flg?"Yes":"No");
	}
	return 0;
}