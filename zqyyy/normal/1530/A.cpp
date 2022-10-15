#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n;
char s[15];
inline void work(){
	scanf("%s",s+1),n=strlen(s+1);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,s[i]-'0');
	cout<<ans<<endl;
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}