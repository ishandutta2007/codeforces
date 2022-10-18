#include<iostream>
using namespace std;
const int N=2e5+1;
long long n,k,A[N][2],c;
int main()
{
	cin>>n>>k;
	if(k*(k-1)<n)
	{
		cout<<"NO";
		return 0;
	}
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
		{
			c++;
			if(i!=A[c-1][0]&&j!=A[c-1][1])
				A[c][0]=A[c+1][1]=i,A[c][1]=A[c+1][0]=j;
			else
				A[c][0]=A[c+1][1]=j,A[c][1]=A[c+1][0]=i;
			c++;
			if(c>=n)
				i=j=k;
		}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<A[i][0]<<" "<<A[i][1]<<endl;
	return 0;
}