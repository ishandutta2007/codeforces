#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

struct dat
{
	bool b;int sz;bool first;
};
bool operator==(dat A,dat B){return A.b==B.b&&A.sz==B.sz&&A.first==B.first;}


char s[300];
dat calc()
{
	int n=strlen(s+1);vector<int> V;dat ret;ret.b=ret.sz=ret.first=0;//printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='B'){ret.b^=1;}
		else
		{
			if(V.empty())V.push_back(s[i]);
			else
			{
				if(V.back()==s[i])V.pop_back();else V.push_back(s[i]);
			}
		}
	}
	ret.sz=V.size();if(V.size()>=1&&V[0]=='C')ret.first=1;else ret.first=0;
	return ret;
}

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		scanf("%s",s+1);dat A=calc();
		scanf("%s",s+1);dat B=calc();
		puts(A==B?"YES":"NO");
	}
}