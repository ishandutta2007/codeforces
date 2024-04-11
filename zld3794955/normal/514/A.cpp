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
#include<numeric>
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
int main()
{
	char ch=getchar();
	if('5'<=ch && ch<='8')
		putchar(9-(ch-'0')+'0');
	else
		putchar(ch);
	while((ch=getchar())!=EOF)
		if('5'<=ch && ch<='9')
			putchar(9-(ch-'0')+'0');
		else
			putchar(ch);
	putchar('\n');
	return 0;
}