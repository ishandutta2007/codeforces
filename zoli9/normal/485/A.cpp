#include <iostream>
using namespace std;
long long a, m;
int main()
{
    cin>>a>>m;
    a=a%m;
    for(int i=1; i<=m; i++)
    {
        a*=2;
        a%=m;
        if(a==0)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;


    return 0;
}