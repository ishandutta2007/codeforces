#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,k;
int main(){
	n=read(),k=read();
	int x=(n-1)/k,y=(n-1)%k;
	int tot=x*2;
	if (y>=1)
		tot++;
	if (y>=2)
		tot++;
	printf("%d\n",tot);
	for (int i=n;i>1;i--)
		printf("%d %d\n",i,max(i-k,1));
	return 0;
}