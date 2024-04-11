#include<iostream>
using namespace std;
const int N=6;
int t;
long long n,m,x[N],y[N],A,B;
long long W(long long a,long long b,long long c,long long d)
{
	return (c-a+1)*(d-b+1)/2+(a%2==b%2&&b%2==c%2&&c%2==d%2);
}
long long S(long long a,long long b,long long c,long long d)
{
	return (c-a+1)*(d-b+1);
}
int main()
{
	cin>>t;
	while(t--&&cin>>n>>m>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3])
	{
		x[4]=y[4]=0,x[5]=y[5]=-1;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					for(int l=0;l<4;l++)
						if(x[i]<=x[k]&&y[j]<=y[l]&&x[0]<=x[i]&&x[k]<=x[1]&&y[0]<=y[j]&&y[l]<=y[1]&&x[2]<=x[i]&&x[k]<=x[3]&&y[2]<=y[j]&&y[l]<=y[3]&&S(x[i],y[j],x[k],y[l])>S(x[4],y[4],x[5],y[5]))
							x[4]=x[i],y[4]=y[j],x[5]=x[k],y[5]=y[l];
		A=W(1,1,m,n)+S(x[0],y[0],x[1],y[1])-W(x[0],y[0],x[1],y[1])-W(x[2],y[2],x[3],y[3])-S(x[4],y[4],x[5],y[5])+W(x[4],y[4],x[5],y[5]),B=n*m-A;
		cout<<A<<" "<<B<<endl;
	}
	return 0;
}