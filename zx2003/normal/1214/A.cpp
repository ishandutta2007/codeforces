#include<bits/stdc++.h>
const int N=1e8+5;
bool f[N];
int n,d,e,i;
int main(){
	scanf("%d%d%d",&n,&d,&e);e*=5;
	*f=1;
	for(i=1;i<=n;++i)f[i]=(i>=d && f[i-d]) || (i>=e && f[i-e]);
	for(i=n;!f[i];--i);printf("%d\n",n-i);
	return 0;
}