#include <iostream>
using namespace std;
int n;
int db;
int indexek[100005];
int t[100005];
int main()
{
    cin>>n;
    db=0;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        if(db==0 || t[db]!=a)
        {
            db++;
            t[db]=a;
            indexek[db]=i;
        }
    }

    for(int i=2; i<=db-1; i++)
    {
        if(t[i-1]<t[i] && t[i]>t[i+1])
        {
            cout<<3<<endl;
            cout<<indexek[i-1]<<" "<<indexek[i]<<" "<<indexek[i+1];
            return 0;
        }
        if(t[i-1]>t[i] && t[i]<t[i+1])
        {
            cout<<3<<endl;
            cout<<indexek[i-1]<<" "<<indexek[i]<<" "<<indexek[i+1];
            return 0;
        }
    }
    cout<<0;
    return 0;
}