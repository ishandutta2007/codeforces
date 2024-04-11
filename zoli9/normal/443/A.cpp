#include <iostream>
using namespace std;
char s[4000];
int db=0;
int cnt=0;
bool abc[26];
int main()
{
    cin>>s[0];
    cnt++;
    while(s[cnt-1]!='}')
    {
        cin>>s[cnt];
        cnt++;
    }
    for(int i=0; i<cnt; i++)
    {
        if('a'<=s[i] and s[i]<='z')
        {
            abc[s[i]-'a']=true;
        }
    }
    for(int i=0; i<26; i++)
    {
        if(abc[i])
        {
            db++;
        }
    }
    cout<<db;
    return 0;
}