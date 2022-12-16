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
int n,Q,cnt,a[N];
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;i++)a[i]=read(),cnt+=a[i];
	while(Q--){
		int op=read(),x=read();
		if(op==1){
			if(a[x])cnt--;
			else cnt++;
			a[x]^=1;
		}else puts(x<=cnt?"1":"0");
	}
	return 0;
}