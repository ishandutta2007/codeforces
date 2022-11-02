#include <iostream>
using namespace std;
int n;
int t[100009];
int db=0;
int leg;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>t[i];
        if(t[i]==i) db++;
    }
    leg=db;
    for(int i=0; i<n; i++)
    {
        if(t[i]==i) continue;
        if(t[i]!=i)
        {
            leg=max(leg, db+1);
        }
        if(i==t[t[i]])
        {
            leg=max(leg, db+2);
        }
    }
    cout<<leg;
    return 0;
}