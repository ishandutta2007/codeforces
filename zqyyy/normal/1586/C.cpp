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
int n,m,v[N];
string s[N];
int main(){
	n=read(),m=read();
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=1;i<n;i++)
		for(int j=0;j<m-1;j++)
			if(s[i][j]=='X' && s[i-1][j+1]=='X')v[j+1]=1;
	for(int i=1;i<=m;i++)v[i]+=v[i-1];
	int Q=read();
	while(Q--){
		int l=read(),r=read();
		puts(v[r-1]-v[l-1]?"NO":"YES");	
	}
	return 0;
}