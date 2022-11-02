#include <iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl<<1;
        return 0;
    }
    if(n==2)
    {
        cout<<1<<endl<<1;
        return 0;
    }
    if(n==3)
    {
        cout<<2<<endl<<1<<" "<<3;
        return 0;
    }
    if(n==4)
    {
        cout<<4<<endl<<2<<" "<<4<<" "<<1<<" "<<3;
        return 0;
    }
    cout<<n<<endl;
    for(int i=1; i<=n; i++)
    {
        if(i%2)
        {
            cout<<i<<" ";
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(!(i%2))
        {
            cout<<i<<" ";
        }
    }
    return 0;
}