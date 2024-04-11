#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
ll n,m;
char s[20];
inline void work(){
	scanf("%s",s+1),m=strlen(s+1);
	bool _0=0,_5=0;
	for(int i=m;i;i--){
		if((s[i]=='0' || s[i]=='5') && _0){printf("%d\n",m-i-1);return;}
		if((s[i]=='2' || s[i]=='7') && _5){printf("%d\n",m-i-1);return;}
		_0|=s[i]=='0',_5|=s[i]=='5';
	}
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}