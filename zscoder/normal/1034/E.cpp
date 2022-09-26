#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull; //might overflow, but we just need last 64 bits anyway

void encode(vector<ull> &a, int n) //ans[i] := sum_((j&i)==j)(4^(popcount(j))*a[j])
{
	for(int bit=0;bit<n;bit++)
	{
		for(int i=0;i<(1<<n);i++)
		{
			if(!(i&(1<<bit)))
			{
				a[i^(1<<bit)]<<=2;
				a[i^(1<<bit)]+=a[i];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ull> a(1<<n), b(1<<n);
	string A,B; cin>>A>>B;
	for(int i=0;i<(1<<n);i++) a[i]=A[i]-'0', b[i]=B[i]-'0';
	encode(a,n);
	encode(b,n);
	for(int i=0;i<(1<<n);i++) a[i]*=b[i];
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<(1<<n);i++) {if(i&(1<<j)) a[i]-=a[i^(1<<j)];}
	}
	for(int i=0;i<(1<<n);i++)
	{
		cout<<((a[i]>>(2*__builtin_popcount(i)))&3);
	}
	cout<<'\n';
}