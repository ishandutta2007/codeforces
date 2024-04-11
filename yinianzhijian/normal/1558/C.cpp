#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2055;
int T,n,a[xx];
int main(){//5 
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int vis=0;
		for(int i=1;i<=n;i++)
		{
			if((a[i]&1)!=(i&1))
			{
				puts("-1");
				vis=1;
				break;
			}
		}
		if(vis)continue;
		vector<int>v;
		reverse(v.begin(),v.end());
		for(int i=n;i>=3;i-=2)
		{
			if(a[i]==i&&a[i-1]==i-1)continue;
//			if(a[2]!=i-1)
//			{
//				for(int j=1;j<=n;j++)
//				{
//					if(a[j]==i-1)
//					{
//						v.push_back(j+1);
//						reverse(a+1,a+j+1+1);
//						break;
//					}
//				}
//			}
			if(a[1]!=i)
			{
//				cout<<i<<"!!!\n";
				for(int j=1;j<=n;j++)
				{
					if(a[j]==i)
					{
						v.push_back(j);
						reverse(a+1,a+j+1);
//						v.push_back(i-2);
//						reverse(a+1,a+i-2+1);
						break;
					}
				}
			}
			int id=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]==i-1)
				{
					if(a[j-1]!=i)
					{
						v.push_back(j-1);
						reverse(a+1,a+j);
					}
					id=j+1;
					break;
				}
			}
			if(id!=3)
			{
				v.push_back(id);
				reverse(a+1,a+id+1);
				v.push_back(3);
				reverse(a+1,a+3+1);
			}
			v.push_back(i);
			reverse(a+1,a+i+1);
			
		}
//		if(v.size()>5*n/2)
//		{
//			puts("-1");
//			continue;
//		}
		cout<<v.size()<<"\n";
		for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
		puts("");
//		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//		puts("");
	}
	return 0;
}