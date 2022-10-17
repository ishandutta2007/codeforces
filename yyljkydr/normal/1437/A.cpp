#include<bits/stdc++.h>
using namespace std;

const int N=1e3+7;

int q,n,t[N],f[N][N];

int main()
{
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<(l*2>r?"Yes":"No")<<endl;
	}
}