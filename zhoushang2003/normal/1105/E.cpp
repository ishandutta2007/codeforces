#include<bits/stdc++.h>
using namespace std;
const int M=40,K=1e4;
int n,m,t,c,f[M],A;
long long a[M],k;
string s;
map<string,int>p;
void S()
{
	for(int i=0;i<c;i++)
		if(k>>i&1)
			a[i]|=k;
	k=0;
}
int main()
{
	cin>>n>>m;
	while(n--&&cin>>t)
		if(t==2&&cin>>s)
		{
			if(!p.count(s))
				p[s]=c++;
			k|=(long long)1<<p[s];
		}
		else
			S();
	S();
	for(int i=0;i<m;i++)
		f[i]=i;
	for(int i=0;i<K;i++)
	{
		random_shuffle(f,f+m),k=c=0;
		for(int i=0;i<m&&k!=(long long)1<<m-1;i++)
			if(!(k>>f[i]&1))
				k|=a[f[i]],c++;
		A=max(A,c);
	}
	cout<<A;
	return 0;
}