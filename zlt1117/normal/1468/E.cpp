#include <bits/stdc++.h>
#define ll long long 
#define il inline 
#define re register int 
using namespace std;
int T,f[10];
il int read(){
	char c=getchar();int z=0,f=1;
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') z=z*10+c-'0',c=getchar();
	return z*f;
}

il void work(){
	for(re i=1;i<=4;i++) f[i]=read();
	sort(f+1,f+1+4);
	cout<<f[1]*f[3]<<'\n';
}
int main (){
	T=read();
	while(T--) work();
	return 0;
}