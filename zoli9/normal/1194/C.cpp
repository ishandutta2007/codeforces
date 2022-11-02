#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int test;
int kelldb[26];
int pdb[26];
string s, t, p;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>s>>t>>p;
        int si=s.size();
        int ti=t.size();
        int pi=p.size();
        int sind=0;
        for(int i=0; i<26; i++)
        {
            pdb[i]=0;
            kelldb[i]=0;
        }
        for(int i=0; i<ti; i++)
        {
            if(sind<si && s[sind]==t[i]) sind++;
            else
            {
                kelldb[t[i]-'a']++;
            }
        }
        if(sind<si)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0; i<pi; i++)
        {
            pdb[p[i]-'a']++;
        }
        bool ok=true;
        for(int i=0; i<26; i++)
        {
            if(pdb[i]<kelldb[i])
            {
                ok=false;
                break;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}