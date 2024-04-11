#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

char A[3][3];
char B[3][3];
vector <int> S,T;

int ctoi(char c)
{
	if(c=='A') return 0;
	if(c=='B') return 1;
	if(c=='C') return 2;
	return 3;
}
int main()
{
	for(int i=0;i<2;i++)
	{
		scanf("%s",&A[i]);
		if(i==0)
		{
			S.push_back(ctoi(A[i][0]));
			S.push_back(ctoi(A[i][1]));
		}
		else
		{
			S.push_back(ctoi(A[i][1]));
			S.push_back(ctoi(A[i][0]));
		}
	}
	for(int i=0;i<2;i++)
	{
		scanf("%s",&B[i]);
		if(i==0)
		{
			T.push_back(ctoi(B[i][0]));
			T.push_back(ctoi(B[i][1]));
		}
		else
		{
			T.push_back(ctoi(B[i][1]));
			T.push_back(ctoi(B[i][0]));
		}
	}
	for(int i=0;i<4;i++) if(S[i]==3) {S.erase(S.begin()+i);break;}
	for(int i=0;i<4;i++) if(T[i]==3) {T.erase(T.begin()+i);break;}
	for(int i=0;i<3;i++)
	{
		bool up=true;
		for(int j=0;j<3;j++)
		{
			int to=(i+j)%3;
			if(S[j]!=T[to])
			{
				up=false;
				break;
			}
		}
		if(up)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}