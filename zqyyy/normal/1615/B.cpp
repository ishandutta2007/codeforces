#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int l,r,s[18][N];
inline void work(){
	l=read(),r=read();
	int mx=0;
	for(int i=0;i<18;i++)mx=max(mx,s[i][r]-s[i][l-1]);
	printf("%d\n",r-l+1-mx);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	for(int i=1;i<=2e5;i++)
		for(int j=0;j<18;j++)
			if(i>>j&1)s[j][i]++;
	for(int j=0;j<18;j++)
		for(int i=1;i<=2e5;i++)s[j][i]+=s[j][i-1];
	int test=read();
	while(test--)work();
    return 0;
}