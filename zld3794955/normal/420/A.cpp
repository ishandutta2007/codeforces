#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
//Can: AHIMOTUVWXY;
char ch[100100]={};
bool b[300]={};
int main()
{	
	gets(ch);
	int l=strlen(ch);
	b['A']=b['H']=b['I']=b['M']=b['O']=b['T']=b['U']=b['V']=true;
	b['W']=b['X']=b['Y']=true;
	bool can=true;
	for(int i=0;i<l;++i)
		if(!b[ch[i]] || ch[i]!=ch[l-i-1])
		{
			can=false;
			break;
		}
	if(can)
		puts("YES");
	else
		puts("NO");
	return 0;
}