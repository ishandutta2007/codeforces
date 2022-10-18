#include<iostream>
using namespace std;
const long long P=998244353;
long long n,x,y;
int main()
{
	cin>>n;
	x=n;
	for(int i=1;i<=n;i++)
		(x*=i)%=P;
	for(int i=2;i<=n;i++)
		(y=(y+1)*i)%=P;
	cout<<(x-y+P)%P;
	return 0;
}