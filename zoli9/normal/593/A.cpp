#include <bits/stdc++.h>
using namespace std;
int n;
string s[109];
bool hasznal[109][30];
int ans=0;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
        for(int j=0; j<s[i].size(); j++)
        {
            hasznal[i][s[i][j]-'a']=true;
        }
    }
    int akt;
    for(int i=0; i<26; i++)
    {
        for(int j=i+1; j<26; j++)
        {
            akt=0;
            for(int k=1; k<=n; k++)
            {
                bool joszo=true;
                for(int l=0; l<26; l++)
                {
                    if(hasznal[k][l] && l!=i && l!=j) joszo=false;
                }
                if(joszo) akt+=s[k].size();
            }
            ans=max(ans, akt);
        }
    }
    cout<<ans;
    return 0;
}