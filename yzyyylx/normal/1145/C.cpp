#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 200100
using namespace std;

int n;

int main()
{
	int i,j;
	cin>>n;
	n^=8;
	if(n>=(1 << 3)) n^=4;
	if(n>=(1 << 3)+(1 << 2)) n^=2;
	if(n>=(1 << 3)+(1 << 2)+(1 << 1)) n^=1;
	cout<<n<<endl;
}