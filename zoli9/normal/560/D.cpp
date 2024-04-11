#include <iostream>
using namespace std;
string s1, s2;
bool egyenlo(string a1, string a2)
{
    int r1[26];
    int r2[26];
    if(a1.size()!=a2.size())
    {
        return false;
    }
    bool q=true;
    for(int i=0; i<26; i++)
    {
        r1[i]=0;
        r2[i]=0;
    }
    for(int i=0; i<a1.size(); i++)
    {
        if(a1[i]!=a2[i])
        {
            q=false;
            r1[a1[i]-'a']++;
            r2[a2[i]-'a']++;
        }
    }
    if(q) return true;
    if(a1.size()%2) return false;
    q=true;
    for(int i=0; i<26; i++)
    {
        if(r1[i]!=r2[i])
        {
            q=false;
        }
    }
    if(!q) return false;
    int x1=a1.size();
    int x2=a2.size();
    string b1=a1.substr(0, x1/2);
    string b2=a1.substr(x1/2, x1/2);
    string c1=a2.substr(0, x2/2);
    string c2=a2.substr(x2/2, x2/2);
    if((egyenlo(b1, c1) && egyenlo(b2, c2)) || (egyenlo(b2, c1) && egyenlo(b1, c2))) return true;
    return false;
}
int main()
{
    cin>>s1>>s2;
    if(egyenlo(s1, s2)) cout<<"YES";
    else cout<<"NO";
    return 0;
}