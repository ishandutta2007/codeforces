#import<bits/stdc++.h>
using namespace std;
int n;
void V(int x,int y,int z)
{
	cout<<3<<' '<<x<<' '<<y<<' '<<z<<'\n';
}
void W(int x,int y,int z,int w)
{
	cout<<4<<' '<<x<<' '<<y<<' '<<z<<' '<<w<<'\n';
}
main()
{
	cin>>n;
	cout<<(n&1?n/2*(n/2+1):n*n/4-1)<<'\n';
	if(n&1)
		for(int i=2;i<=n;i+=2)
		{
			V(1,i,i+1),V(1,i,i+1);
			for(int j=2;j<i;j+=2)
				W(i,j,i+1,j+1),W(i,j,i+1,j+1);
		}
	else
	{
		W(1,2,3,4),W(1,2,4,3),W(1,4,2,3);
		for(int i=5;i<=n;i+=2)
		{
			W(1,i,2,i+1),V(1,i,i+1),V(2,i,i+1);
			for(int j=3;j<i;j+=2)
				W(i,j,i+1,j+1),W(i,j,i+1,j+1);
		}
	}
}