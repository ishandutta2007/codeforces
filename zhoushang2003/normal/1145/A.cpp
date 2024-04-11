#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	    cin>>a[i];
	for(int i=n;i>0;i/=2)
		for(int j=0;j<n;j+=i)
			if(is_sorted(a+j,a+j+i))
			{
			    cout<<i;
			    return 0;
			}
}