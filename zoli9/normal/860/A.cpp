#include <bits/stdc++.h>
using namespace std;
string s;
bool mag(char c)
{
    if(c=='a') return true;
    if(c=='e') return true;
    if(c=='i') return true;
    if(c=='o') return true;
    if(c=='u') return true;
    return false;
}
char ua='.';
int hossz;
int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(mag(s[i]))
        {
            cout<<s[i];
            hossz=0;
            ua='.';
            continue;
        }
        hossz++;
        if(ua=='.' || ua==s[i])
        {
            ua=s[i];
            cout<<s[i];
            continue;
        }
        ua='!';
        if(hossz>=3)
        {
            cout<<" "<<s[i];
            ua=s[i];
            hossz=1;
            continue;
        }
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}