#include<iostream>
using namespace std;
const int N=100;
bool a[N];
int n,A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		if(a[i-1]&&!a[i]&&a[i+1])
			a[i+1]=false,A++;
	cout<<A;
	return 0;
}