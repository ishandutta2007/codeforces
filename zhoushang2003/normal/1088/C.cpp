#include<iostream>
using namespace std;
const int N=2e3+1;
int n,a[N],k; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		a[i]%=n;
	cout<<n+1<<endl;
	for(int i=n;i>=1;i--)
		cout<<1<<" "<<i<<" "<<i-1+n*2-k-a[i]<<endl,(k+=i-1+n*2-k-a[i])%=n;
	cout<<2<<" "<<n<<" "<<n;
	return 0;
}