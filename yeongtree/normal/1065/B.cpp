#include <iostream>

using namespace std;

int main()
{
    long long int n,m; cin>>n>>m;
    if(m==0) {cout<<n<<" "<<n; return 0;}
    long long int a=n-2*m;
    cout<<((a>0)?a:0);
    long long int i;
    for(i=2;(i*(i-1)/2)<m;i++) {}
    cout<<" "<<n-i;
    return 0;
}