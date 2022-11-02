#include <iostream>
using namespace std;
int main()
{
    int a, b, n, db;
    db=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a>>b;
        if(b-a>=2)
        {
            db++;
        }
    }
    cout<<db;
    return 0;
}