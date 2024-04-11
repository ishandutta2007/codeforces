#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 200100
using namespace std;

int n;
string s;

inline bool ask(char u)
{
	return u=='A'||u=='E'||u=='F'||u=='H'||u=='I'||u=='K'||u=='L'||u=='M'||u=='N'||u=='T'||u=='V'||u=='W'||u=='X'||u=='Y'||u=='Z';
}

int main()
{
	int i,j;
	cin>>s;
	for(i=0;i<s.size()-1;i++)
	{
		if(ask(s[i])!=ask(s[i+1]))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}