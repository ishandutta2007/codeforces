#include<bits/stdc++.h>
using namespace std;
int w,h,a,b,c,d;
int main()
{
	cin>>w>>h>>a>>b>>c>>d;
	for(int i=h;i>=1;i--)
	{
		w+=i;
		if(i==b)
			w=max(0,w-a);
		if(i==d)
			w=max(0,w-c);
	}
	cout<<w;
	return 0;
}