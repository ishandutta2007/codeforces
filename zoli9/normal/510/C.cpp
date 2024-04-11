#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int n;
string s[110];
vector <int> graf[110];
vector <int> sor;
bool bejar[30];
int mely(int p)
{
    bejar[p]=true;
    for(int i=0; i<graf[p].size(); i++)
    {
        if(!bejar[graf[p][i]])
        {
            mely(graf[p][i]);
        }
    }
    sor.push_back(p);
    return 0;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    for(int i=1; i<n; i++)
    {
        int id=0;
        while(s[i].size()>id+1 && s[i-1].size()>id+1 &&  s[i][id]==s[i-1][id])
        {
            id++;
        }
        if(s[i-1][id]==s[i][id])
        {
            if(s[i].size()<s[i-1].size())
            {
                cout<<"Impossible";
                return 0;
            }
        }
        else

        {
            if(s[i][id]!=s[i-1][id])
        {
            graf[s[i-1][id]-'a'].push_back(s[i][id]-'a');
        }
        }

    }

    for(int i=0; i<26; i++)
    {
        if(!bejar[i])
        {
            mely(i);
        }
    }

    for(int i=25; i>=0; i--)
    {
        for(int j=0; j<graf[sor[i]].size(); j++)
        {
            bool vv=false;
            for(int k=0; k<i; k++)
            {
                if(sor[k]==graf[sor[i]][j])
                {
                    vv=true;
                }
            }
            if(!vv)
            {
                cout<<"Impossible";
                return 0;
            }
        }
    }
for(int i=25; i>=0; i--)
{
    cout<<char(sor[i]+'a');
}
//(char)(5+'a');
    return 0;
}