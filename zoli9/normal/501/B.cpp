#include <iostream>
using namespace std;
int q, db;
string ki[1001];
string ki2[1001];
string elso[1001];
string masodik[1001];
bool v[1001];
string akt1, akt2;
int main()
{
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        cin>>elso[i]>>masodik[i];
        v[i]=false;
    }
    db=0;

    for(int i=1; i<=q; i++)
    {
        if(!v[i])
        {
            v[i]=true;
            db++;
            ki[db]=elso[i];
            akt1=masodik[i];
            for(int j=i+1; j<=q; j++)
            {
                if(elso[j]==akt1)
                {
                    akt1=masodik[j];
                    v[j]=true;
                }
            }
            ki2[db]=akt1;
        }
    }
    cout<<db<<endl;
    for(int i=1; i<=db; i++)
    {
        cout<<ki[i]<<" "<<ki2[i]<<endl;
    }

    return 0;
}