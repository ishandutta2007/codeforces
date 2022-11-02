#include <iostream>

using namespace std;
bool v=false;
int n;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin >> a;
        if(a==1)
        {
            v=true;
        }
    }
    if(v)
    {
        cout<<-1;
    }
    else
    {
        cout<<1;
    }
    return 0;
}