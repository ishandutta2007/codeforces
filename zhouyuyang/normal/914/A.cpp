#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
inline void writeln(int x){
	write(x);puts("");
}
inline bool check(int x){
	if(x<0)return 0;
	return (int)sqrt(x)*sqrt(x)==x;
}
int n,a[100010];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=n;i;i--)if(!check(a[i])){
		writeln(a[i]);return 0;
	} 
}