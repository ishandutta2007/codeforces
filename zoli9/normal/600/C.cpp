#include <bits/stdc++.h>
using namespace std;
string s;
vector<char> help;
int db[26];
vector<int> ptl;
int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        db[s[i]-'a']++;
    }
    for(int i=0; i<26; i++)
    {
        if(db[i]%2)
        {
            ptl.push_back(i);
        }
    }
    int e=0;
    int u=ptl.size()-1;
    while(e<u)
    {
        db[ptl[e]]++;
        db[ptl[u]]--;
        e++;
        u--;
    }
    char w='-';
    for(int i=0; i<26; i++)
    {
        if(db[i]%2) w='a'+i;
        for(int j=1; j<=db[i]/2; j++)
        {
            help.push_back('a'+i);
        }
    }
    for(int i=0; i<help.size(); i++)
    {
        cout<<help[i];
    }
    if(w!='-') cout<<w;
    for(int i=help.size()-1; i>=0; i--)
    {
        cout<<help[i];
    }
    return 0;
}