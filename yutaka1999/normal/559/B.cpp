#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <queue>
#include <cmath>
#include <stack>
#include <string>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

string transform(string s)
{
	if(s.size()%2==1) return s;
	string a="",b="";
	int l=s.size();
	for(int i=0;i<l/2;i++) a+=s[i];
	for(int i=l/2;i<l;i++) b+=s[i];
	a=transform(a);
	b=transform(b);
	if(a>b) swap(a,b);
	return a+b;
}
char str[SIZE];
int main()
{
	scanf("%s",&str);
	string a=str;
	scanf("%s",&str);
	string b=str;
	a=transform(a);
	b=transform(b);
	if(a==b) puts("YES");
	else puts("NO");
	return 0;
}