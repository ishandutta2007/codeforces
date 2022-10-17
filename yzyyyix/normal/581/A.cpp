#include<bits/stdc++.h>
using namespace std;

long long a,b;

int main()
{
	cin>>a>>b;
	cout<<min(a,b)<<" "<<(a+b-min(a,b)*2)/2;
}