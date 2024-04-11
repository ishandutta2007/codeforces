#include <iostream>
using namespace std;
string s;
int k;
int d;
int abc[26];
bool a[26];
int main()
{
    cin>>k;
    cin>>s;
    for(int i=0; i<26; i++)
    {
        abc[i]=0;
    }
    for(int i=0; i<s.length(); i++)
    {
        abc[s[i]-'a']++;
    }
    d=0;
    for(int i=0; i<26; i++)
    {
        if(abc[i])
        {
            d++;
        }
    }
    if(d<k)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    for(int i=0; i<s.length(); i++)
    {
        if(k>0 and !a[s[i]-'a'])
        {
            cout<<endl<<s[i];
            k--;
            a[s[i]-'a']=true;
        }
        else
        {
            cout<<s[i];
        }
    }
    return 0;
}