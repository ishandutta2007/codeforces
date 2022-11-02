#include <iostream>
using namespace std;
int n;
int min1, min2, min3, max1, max2, max3;
int db1, db2, db3;
int main()
{
    cin>>n>>min1>>max1>>min2>>max2>>min3>>max3;
    db1=min1;
    db2=min2;
    db3=min3;
    max1-=min1;
    max2-=min2;
    max3-=min3;
    n-=db1;
    n-=db2;
    n-=db3;
    if(n>max1)
    {
        db1+=max1;
        n-=max1;
        if(n>max2)
        {
            db2+=max2;
            n-=max2;
            //cout<<max2;
            db3+=n;
        }
        else
        {
            db2+=n;
        }
    }
    else
    {
        db1+=n;
    }
    cout<<db1<<" "<<db2<<" "<<db3;
    return 0;
}