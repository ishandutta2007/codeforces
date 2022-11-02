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
const double eps(1e-8);
const double pi(3.14159265358979);
string s[2];
set<int> yellow[2];
set<int> red[2];
int main()
{	
	cin>>s[0]>>s[1];
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int t,num;
		char d,c;
		cin>>t>>d>>num>>c;
		bool dir=d=='a';
		if(c=='y')
		{
			if(yellow[dir].count(num))
			{
				yellow[dir].erase(num);
				red[dir].insert(num);
				cout<<s[dir]<<' '<<num<<' '<<t<<endl;
			}
			else
				if(!red[dir].count(num))
					yellow[dir].insert(num);
		}
		if(c=='r')
		{
			if(!red[dir].count(num))
			{
				red[dir].insert(num);
				cout<<s[dir]<<' '<<num<<' '<<t<<endl;
				yellow[dir].erase(num);
			}
		}
	}
	return 0;
}