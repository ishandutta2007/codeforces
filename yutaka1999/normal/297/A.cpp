#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string a,b;

int main()
{
	cin>>a>>b;
	int as=a.size(),bs=b.size();
	int an=0,bn=0;
	for(int i=0;i<as;i++) if(a[i]=='1') an++;
	for(int i=0;i<bs;i++) if(b[i]=='1') bn++;
	an+=an%2;
	if(an>=bn) printf("YES\n");
	else printf("NO\n");
	return 0;
}