#include<bits/stdc++.h>
using namespace std;
int main()	{
	int c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if ((!c3||(c1&&c4))&&c1==c4)
		puts("1");
	else
		puts("0");
	return 0;
}