#include <iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    int sum=0;
    int i=0;
    while(sum<=n)
    {
        i++;
        sum+=i*(i+1)/2;
    }
    cout<<i-1;




    return 0;
}