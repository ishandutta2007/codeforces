#include <iostream>
using namespace std;
int n;
int db=0;
int t[40];
int asd(int x)
{
    int x2=x;
    if(x==0)
    {
        return 0;
    }
    int r[10];
    int c=0;
    while(x>0)
    {
        c++;
        r[c]=x%10;
        x/=10;
    }
    int z=1;
    for(int i=c-1; i>=1; i--)
    {
        if(r[i]>0)
        {
            z*=10;
            z++;
        }
        else
        {
            z*=10;
        }
    }
    db++;
    t[db]=z;
    asd(x2-z);
}
int main()
{
    cin>>n;
    asd(n);
    cout<<db<<endl;
    for(int i=1; i<=db; i++)
    {
        cout<<t[i]<<" ";
    }
    return 0;
}