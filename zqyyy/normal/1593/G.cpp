#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e6+7;
int n,Q,s[N][2][2];
char str[N];
inline void work(){
	scanf("%s",str+1),n=strlen(str+1),Q=read();
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++)for(int k=0;k<2;k++)s[i][j][k]=s[i-1][j][k];
		s[i][i&1][str[i]=='[' || str[i]==']']++;
	}
	while(Q--){
		int l=read(),r=read(),ans=0;
		for(int o=0;o<2;o++)ans+=abs(s[r][0][o]-s[l-1][0][o]-(s[r][1][o]-s[l-1][1][o]));
		ans>>=1,printf("%d\n",ans);
	}
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}