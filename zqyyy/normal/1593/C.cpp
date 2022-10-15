#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=4e5+7;
int n,m,a[N];
inline void work(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)a[i]=n-read();
	sort(a+1,a+m+1);
	int ans=0,cat=0;
	for(int i=1;i<=m;i++){
		cat+=a[i];
		if(cat>=n)break;
		ans++;
	}
	printf("%d\n",ans);		
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}