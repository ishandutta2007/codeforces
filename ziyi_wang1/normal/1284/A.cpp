#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
char c[30][30],s[30][30];
int n,m,T,x,y;
int main(){
	cin>>n>>m;
	F(i,1,n)cin>>c[i]+1;
	F(i,1,m)cin>>s[i]+1;
	cin>>T;
	while(T--){
		cin>>x;y=x;
		x%=n;y%=m;
		if(!x)x=n;if(!y)y=m;
		printf("%s%s\n",c[x]+1,s[y]+1);
	}
	return 0;
}