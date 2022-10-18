#include<iostream>
using namespace std;
const int N=1e3,M=1e6,K=10,X[4]={-1,0,0,1},Y[4]={0,-1,1,0};
bool v[N][N],f;
char c[N][N];
int n,m,p,s[K],P[K][M],Q[K][M],S[K],T[K],d[N][N],U,V;
string t[N];
int main()
{
	cin>>n>>m>>p;
	for(int i=1;i<=p;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		cin>>t[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			c[i][j]=t[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			for(int k=1;k<=p;k++)
				if(c[i][j]-'0'==k)
					P[k][T[k]]=i,Q[k][T[k]++]=j,c[i][j]='#';
	while(1)
	{
		f=true;
		for(int i=1;i<=p;i++)
			if(S[i]<T[i])
				f=false;
		if(f)
			break;
		for(int i=1;i<=p;i++)
		{
			for(int j=S[i];j<T[i];j++)
				d[P[i][j]][Q[i][j]]=0;
			while(S[i]<T[i]&&d[P[i][S[i]]][Q[i][S[i]]]<s[i])
			{
				U=P[i][S[i]],V=Q[i][S[i]++];
				for(int j=0;j<4;j++)
					if(0<=U+X[j]&&U+X[j]<n&&0<=V+Y[j]&&V+Y[j]<m&&c[U+X[j]][V+Y[j]]!='#')
						P[i][T[i]]=U+X[j],Q[i][T[i]++]=V+Y[j],c[U+X[j]][V+Y[j]]='#',d[U+X[j]][V+Y[j]]=d[U][V]+1;
			}
		}
	}
	for(int i=1;i<=p;i++)
		cout<<T[i]<<" ";
	return 0;
}