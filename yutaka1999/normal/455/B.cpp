#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;

struct T
{
	bool end;
	vector <T*> vec;
	vector <int> id;
	T(){}
};
T root;
char str[SIZE];

P solve(T *at)
{
	if(at->vec.size()==0)
	{
		return P(1,0);
	}
	int a=1,b=1;
	for(int i=0;i<at->vec.size();i++)
	{
		T *nxt=at->vec[i];
		P p=solve(nxt);
		if(p.first==1) a=0;
		if(p.second==1) b=0;
	}
	return P(a,b);
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		int len=strlen(str);
		T *at=&root;
		for(int j=0;j<len;j++)
		{
			int v=str[j]-'a';
			bool ok=false;
			T *nxt;
			for(int k=0;k<at->id.size();k++)
			{
				int g=at->id[k];
				if(g==v)
				{
					ok=true;
					nxt=at->vec[k];
					break;
				}
			}
			if(!ok)
			{
				nxt=new T();
				at->id.push_back(v);
				at->vec.push_back(nxt);
			}
			at=nxt;
		}
		at->end=true;
	}
	P p=solve(&root);
	int a=p.first,b=p.second;
	//printf("%d %d\n",a,b);
	if(a==0)
	{
		if(b==0)
		{
			puts("First");
		}
		else
		{
			if(k%2==1) puts("First");
			else puts("Second");
		}
	}
	else
	{
		puts("Second");
	}
	return 0;
}