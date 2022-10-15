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
int n,m;
bool v[N];
inline void work(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)v[i]=0;
	for(int i=1;i<=m;i++)read(),v[read()]=1,read();
	for(int i=1;i<=n;i++)
		if(!v[i]){
			for(int j=1;j<=n;j++)
				if(i!=j)printf("%d %d\n",i,j);
			return;	
		}
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}