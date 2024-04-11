#include<iostream>
using namespace std;
int n,k;
int main()
{
	cin>>n>>k;
	cout<<(n*2-1)/k+(n*5-1)/k+(n*8-1)/k+3;
	return 0; 
}