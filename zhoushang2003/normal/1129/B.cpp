#include<iostream>
using namespace std;
const int N=1e6;
int k;
int main()
{
	cin>>k;
	for(int n=2;;n++)
		if((n-1)*N-n>=k)
		{
			cout<<n<<'\n'<<-1<<" ";
			for(int i=2;i<n;i++)
				cout<<N<<" ";
			cout<<k-(n-2)*N+n;
			break;
		}
	return 0;
}