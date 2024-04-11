#include<iostream>
#include<cstdio>
#define C ch=getchar()
using namespace std;

int n,now,x,y,ans;
char ch;

int main()
{
	int i,j;
	cin>>n;
	C;
	for(i=1;i<=n;i++)
	{
		C;
		ch=='U'?x++:y++;
		if(x>y&&now!=1)
		{
			ans++;
			now=1;
		}
		else if(x<y&&now!=2)
		{
			ans++;
			now=2;
		}
//		cout<<ch<<" "<<x<<' '<<y<<" "<<ans<<" "<<now<<endl;
	}
	cout<<ans-1;
}