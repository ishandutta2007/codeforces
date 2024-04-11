#include<bits/stdc++.h>
using namespace std;
 
string s;
 
int main()
{
    cin>>s;
    int ok=1;
    for(int i=2;i<s.size();i++)
        if(s[i]-'A'!=(s[i-1]-'A'+s[i-2]-'A')%26)
            ok=0;
    puts(ok?"YES":"NO");
}