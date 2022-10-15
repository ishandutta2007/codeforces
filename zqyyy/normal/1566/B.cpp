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
int n;
char s[N];
inline void work(){
	scanf("%s",s+1),n=strlen(s+1);
	int cnt=0;bool _1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			while(s[i]=='0' && i<=n)i++;
			cnt++;
		}else _1=1;
	}
	if(!cnt)puts("0");
	else if(cnt==1)puts("1");
	else puts("2");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}