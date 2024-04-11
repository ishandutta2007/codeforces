#include <iostream>

using namespace std;

int main()
{
    int n , k; cin>>n>>k;
    int div , mod = k-1;
    for(; n%mod; --mod) ;
    div = n/mod;
    cout<<div*k+mod<<endl;
    return 0;
}