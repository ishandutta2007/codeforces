#include <iostream>

using namespace std;

int main()
{
    int T; cin>>T;
    while(T--)
    {
        long long int n,m,k; cin>>n>>m>>k;
        if(n>k||m>k) {cout<<"-1"<<endl; continue;}
        long long int _x=k-n; long long int _y=k-m;
        if(_x%2) k--; if(_y%2) k--;
        cout<<k<<endl;
    }
    return 0;
}