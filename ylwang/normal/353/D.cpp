#include <bits/stdc++.h> 
using namespace std;
string s;
int main()
{
    cin>>s;
    int ans=0,m=0;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='M') 
        {
            m++;
        }
        if(s[i]=='F'&&m>0)
        {
            ans=max(ans+1,m);
        }
    }
    printf("%d\n",ans);
    return 0;
}