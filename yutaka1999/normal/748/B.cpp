#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1005
#define ALP 30

using namespace std;
typedef pair <int,int> P;

char A[SIZE],B[SIZE];
int tg[ALP];

int main()
{
	scanf("%s",&A);
	scanf("%s",&B);
	int n=strlen(A);
	memset(tg,-1,sizeof(tg));
	for(int i=0;i<n;i++)
	{
		int l=A[i]-'a';
		int r=B[i]-'a';
		if(tg[l]!=-1&&tg[l]!=r)
		{
			puts("-1");
			return 0;
		}
		if(tg[r]!=-1&&tg[r]!=l)
		{
			puts("-1");
			return 0;
		}
		tg[l]=r;
		tg[r]=l;
	}
	vector <P> vec;
	for(int i=0;i<ALP;i++)
	{
		if(tg[i]>i)
		{
			vec.push_back(P(i,tg[i]));
		}
	}
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();i++)
	{
		P p=vec[i];
		printf("%c %c\n",'a'+p.first,'a'+p.second);
	}
	return 0;
}