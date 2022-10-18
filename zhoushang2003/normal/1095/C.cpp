#include<bits/stdc++.h>
using namespace std;
const int K=2e5;
int n,k,A[K],s;
int main()
{
	cin>>n>>k;
	s=k;
	for(int i=0;i<k;i++)
		A[i]=1;
	for(int i=0;i<k;i++)
		while(s+A[i]<=n)
			s+=A[i],A[i]*=2;
	if(s!=n)
		cout<<"NO";
	else
	{
		cout<<"YES"<<endl;
		for(int i=0;i<k;i++)
			cout<<A[i]<<" ";
	}
	return 0;
}