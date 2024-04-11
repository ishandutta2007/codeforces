#include <iostream>
#include <vector>
using namespace std;
string s;
vector<int> ab;
vector<int> ba;
int main()
{
    cin>>s;
    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i]=='A' and s[i+1]=='B')
        {
            ab.push_back(i);
        }
        if(s[i]=='B' and s[i+1]=='A')
        {
            ba.push_back(i);
        }
    }
    for(int i=0; i<ab.size(); i++)
    {
        for(int j=0; j<ba.size(); j++)
        {
            if(ab[i]-ba[j]>=2 or ba[j]-ab[i]>=2)
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}