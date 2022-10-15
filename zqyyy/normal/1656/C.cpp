#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,a[N];
inline void work(){
	n=read();
	bool fl0=0,fl1=0;
	for(int i=1;i<=n;i++)a[i]=read(),fl0|=!a[i],fl1|=a[i]==1;
	sort(a+1,a+n+1);
	if(!fl1){puts("Yes");return;}
	if(fl0){puts("No");return;}
	bool fl=1;
	for(int i=2;i<=n;i++)fl&=a[i]-a[i-1]!=1;
	puts(fl?"Yes":"No");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}