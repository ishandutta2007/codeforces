#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int main()
{
	cin>>n;
	for(int i=2;i<N;i++)
		if(i/2*((i+1)/2)>=n)
			cout<<i,i=N;
	return 0;
}