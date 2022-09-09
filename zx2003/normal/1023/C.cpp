#include<bits/stdc++.h>
const int N=200005;
int n,k,i,a[N],x,y;
char s[N];
bool b[N];
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	for(i=n;i;--i)a[i]=a[i+1]+(s[i]==')');
	for(i=1;i<=n;++i)
		if(s[i]=='('){
			if(y+(x+1)*2<=k && a[i+1]>=x+1)++x,b[i]=1;
		}else if(x)y+=2,--x,b[i]=1;
	for(i=1;i<=n;++i)if(b[i])putchar(s[i]);
	return 0;
}