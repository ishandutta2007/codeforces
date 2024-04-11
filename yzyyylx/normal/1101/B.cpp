#include<bits/stdc++.h>
using namespace std;

int ans;
string str;

int main()
{
    int i,j,p,q;
    cin>>str;
    for(i=0;i<str.size();i++) if(str[i]=='[') break;
    for(;i<str.size();i++) if(str[i]==':') break;
    p=i;
    for(i=str.size()-1;i>=0;i--) if(str[i]==']') break;
    for(;i>=0;i--) if(str[i]==':') break;
    q=i;
    if(p>=q)
    {
    	puts("-1");
    	return 0;
	}
	ans=4;
	for(i=p+1;i<q;i++) if(str[i]=='|') ans++;
	cout<<ans;
}