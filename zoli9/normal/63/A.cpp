#include <iostream>
#include <map>
using namespace std;
map <string, int> m;
int n;
string nev[200];

int tul[200];
int main()
{
    cin>>n;
    m["rat"]=1;
    m["child"]=2;
    m["woman"]=3;
    m["man"]=4;
    m["captain"]=5;
    for(int i=1; i<=n; i++)
    {
        cin>>nev[i];
        string s;
        cin>>s;
        tul[i]=m[s];
    }
    for(int i=1; i<=n; i++)
    {
        if(tul[i]==1)
        {
            cout<<nev[i]<<endl;
        }
    }

        for(int i=1; i<=n; i++)
    {
        if(tul[i]==2 || tul[i]==3)
        {
            cout<<nev[i]<<endl;
        }
    }

        for(int i=1; i<=n; i++)
    {
        if(tul[i]==4)
        {
            cout<<nev[i]<<endl;
        }
    }

        for(int i=1; i<=n; i++)
    {
        if(tul[i]==5)
        {
            cout<<nev[i]<<endl;
        }
    }

    return 0;
}