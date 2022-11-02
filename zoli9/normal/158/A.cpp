#include <iostream>
using namespace std;
int t[60];
int n, k;
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];

    }
    int db=0;
    for(int i=1; i<=n; i++)
    {
        if(t[i]>0 && t[i]>=t[k])
        {
            db++;
        }
    }
    cout<<db;

    return 0;
}