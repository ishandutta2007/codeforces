#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,k,a[N],T;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int n,c0,c1,h;
		cin>>n>>c0>>c1>>h;
		string s;
		cin>>s;
		int C[2]={min(c0,c1+h),min(c1,c0+h)};
		int ans=0;
		for(int i=0;i<s.size();i++)
			ans+=C[s[i]-'0'];
		cout<<ans<<endl;
	}
}