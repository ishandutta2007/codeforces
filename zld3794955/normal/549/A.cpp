#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=55,M=55,x_[4]={0,0,1,1},y_[4]={0,1,0,1};
const char c[4]={'f','a','c','e'};
int n,m,ans=0;
char ch[N][M]={};
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>(ch[i]+1);
	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j)
		{
			bool f1=true;
			for(int k=0;k<4;++k)
			{
				bool f2=false;
				for(int l=0;l<4;++l)
					if(ch[i+x_[l]][j+y_[l]]==c[k])
						f2=true;
				if(!f2)
					f1=false;
			}
			ans+=f1;
		}
	cout<<ans<<endl;
	return 0;
}