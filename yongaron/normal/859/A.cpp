#include <iostream>

using namespace std;

int k;

int main()
{
    int ma, a;
    cin>>k;
    cin>>ma;
    for(int i = 1; i < k; i++)
    {
        cin>>a;
        if(a > ma)
            ma = a;
    }
    cout<<max(ma-25, 0)<<endl;
    return 0;
}