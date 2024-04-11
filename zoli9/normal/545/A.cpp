#include  <iostream>
using namespace std;
int n, a, db;
bool jo[209];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        jo[i]=true;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a;
            if(a==1 || a==3)
            {
                jo[i]=false;
            }
        }
    }
    db=0;
    for(int i=1; i<=n; i++)
    {
        if(jo[i])
        {
            db++;
        }
    }
    cout<<db<<endl;
    for(int i=1; i<=n; i++)
    {
        if(jo[i])
        {
            cout<<i<<" ";
        }
    }
    return 0;
}