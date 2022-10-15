#include <iostream>
using namespace std;
int a,n;
int main()
{
    cin>>n>>a;
    if (a%2==1) cout<<a/2+1<<endl;
    else cout<<n/2-a/2+1<<endl;
    return 0;
}