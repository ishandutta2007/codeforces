#include <iostream>
using namespace std;
int n;
int t[100];
int x=0;
int db=0;
int main()
{
    cin>>n;
    cout<<n;
    for(int i=2; i<=1000000; i++)
    {
        if(n%i==0)
        {
            cout<<" "<<n/i;
            n/=i;
            if(n==1)
            {
                return 0;
            }
            i=1;
        }
    }




    return 0;
}