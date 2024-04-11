#include <bits/stdc++.h>
using namespace std;
vector<int> prim;
int main()
{
    prim.push_back(2);
    for(int i=3; i<=100; i++)
    {
        bool pr=true;
        for(int j=2; j<i; j++)
        {
            if(i%j==0)
            {
                pr=false;
                break;
            }
        }
        if(pr)
        {
            prim.push_back(i);
        }
    }
    int akt=0;
    int dbyes=0;
    while(1)
    {
        if(akt>prim.size()-1 || prim[akt]>50)
        {
            cout<<"prime"<<endl;
            fflush(stdout);
            return 0;
        }
        cout<<prim[akt]<<endl;
        fflush(stdout);
        string s;
        cin>>s;
        if(s=="yes")
        {
            dbyes++;
            if(dbyes==2)
            {
                cout<<"composite"<<endl;
                fflush(stdout);
                return 0;
            }
            if(prim[akt]*prim[akt]<=100)
            {
                cout<<prim[akt]*prim[akt]<<endl;
            fflush(stdout);
            cin>>s;
            if(s=="yes")
            {
                cout<<"composite"<<endl;
                fflush(stdout);
                return 0;
            }
            }

        }
        akt++;
    }

    return 0;
}