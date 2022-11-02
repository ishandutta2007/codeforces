#include <bits/stdc++.h>
using namespace std;
string s;
int nagy[26];
int kicsi[26];
int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if('a'<=s[i] && s[i]<='z')
        {
            kicsi[s[i]-'a']++;
        }
        else if('A'<=s[i] && s[i]<='Z')
        {
            nagy[s[i]-'A']++;
        }
    }
    int mini=1000000;
    mini=min(mini, nagy['B'-'A']);
    mini=min(mini, kicsi['u'-'a']/2);
    mini=min(mini, kicsi['l'-'a']);
    mini=min(mini, kicsi['b'-'a']);
    mini=min(mini, kicsi['a'-'a']/2);
    mini=min(mini, kicsi['s'-'a']);
    mini=min(mini, kicsi['r'-'a']);
    cout<<mini<<endl;

    return 0;
}