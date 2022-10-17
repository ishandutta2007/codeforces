#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=107;
int n,x,a[N];
inline void work(){
	n=read(),x=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum==x){
			if(i<n)swap(a[i],a[i+1]);
			else {puts("NO");return;}
			break;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}