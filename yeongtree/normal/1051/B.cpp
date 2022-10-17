#include <iostream>

using namespace std;

int main()
{
    long long int k,l; cin>>k>>l;
    cout<<"YES"<<endl;
    for(long long int i=k;i<l;i+=2)
    {
        cout<<i<<" "<<i+1<<endl;
    }
    return 0;
}