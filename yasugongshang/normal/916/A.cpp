#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
bool check(int x)
{
	int a=x%10,b=x/10;
	if (a==7 || b==7) return 1;
	return 0;
}
int main()
{
	int x,a,b;
	cin>>x>>a>>b;
	int ans=0;
	while (1){
		if (check(a) || check(b)) break;
		if (b>=x) b-=x;
		else
		{
			a--;
			b=60-(x-b);
		}
		if (a<0) a=23;
		ans++;
	}
	cout<<ans<<endl;
}