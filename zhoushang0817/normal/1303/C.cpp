#include<bits/stdc++.h>
using namespace std;
const int N=27; 
int T,x,y,c[N],q[N],t,X,A[N],C;
bool p[N],v[N][N],b;
string s;
vector<int>a[N];
int main()
{
	cin>>T;
	while(T--&&cin>>s)
	{
		for(int i=0;i<26;i++)
			a[i].clear(),c[i]=0,p[i]=false;
		for(int i=0;i<26;i++)
			for(int j=0;j<26;j++)
				v[i][j]=false;
		for(int i=1;i<s.size();i++)
			if(!v[s[i]-'a'][s[i-1]-'a'])
				x=s[i]-'a',y=s[i-1]-'a',v[x][y]=v[y][x]=true,a[x].push_back(y),a[y].push_back(x),c[x]++,c[y]++;
		b=false;
		for(int i=0;i<26;i++)
			if(c[i]>2)
				b=true;
		if(b)
		{
			cout<<"NO"<<'\n';
			continue;
		}
		C=0;
		for(int i=0;i<26;i++)
			if(!p[i]&&c[i]==1)
			{
				q[++t]=i,p[i]=true,A[++C]=i;
				while(t)
				{
					X=q[t--];
					for(int j=0;j<a[X].size();j++)
						if(!p[a[X][j]])
							q[++t]=a[X][j],p[a[X][j]]=true,A[++C]=a[X][j];
				}
			}
		for(int i=0;i<26;i++)
			if(c[i]&&!p[i])
				b=true;
		if(b)
		{
			cout<<"NO"<<'\n';
			continue;
		}
		cout<<"YES"<<'\n';
		for(int i=1;i<=C;i++)
			cout<<(char)(A[i]+'a');
		for(int i=0;i<26;i++)
			if(!p[i])
				cout<<(char)(i+'a');
		cout<<'\n';
	}
	return 0;
}