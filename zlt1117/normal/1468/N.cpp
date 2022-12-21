#include<bits/stdc++.h>
using namespace std;
int read()
{
	int res=0,fl=0; char a=getchar();
	while(a<'0'||a>'9') fl|=a=='-',a=getchar();
	while(a>='0'&&a<='9') res=res*10+a-'0',a=getchar();
	return fl? -res:res; 
}
int main()
{
	int i,j,t=read();
	while(t--)
	{
		int c1=read(),c2=read(),c3=read(),a1=read(),a2=read(),a3=read(),a4=read(),a5=read();
		c1-=a1,c2-=a2,c3-=a3;
		if(c1<0||c2<0||c3<0) cout<<"NO\n";
		else if(max(a4-c1,0)+max(a5-c2,0)>c3) cout<<"NO\n";
			else cout<<"YES\n";
	}
	return 0;
}