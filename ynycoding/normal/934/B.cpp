#include <bits/stdc++.h>
#define ll long long
#define rg register
using namespace std;

inline int read()
{
    int X=0,w=1; char ch=0;
    while(ch<'0' || ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}
inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
int num[10]={1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int main()
{
	int n=read();
	if(n>36)
	{
		cout<<-1;
		return 0;
	}
	while(n>=2)
	{
		cout<<8;
		n-=2;
	}
	if(n) cout<<6;
	return 0;
}