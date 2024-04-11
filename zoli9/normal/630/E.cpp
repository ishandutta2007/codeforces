#include <bits/stdc++.h>
using namespace std;
long long x1, z1, x2, z2;
int main()
{
    cin>>x1>>z1>>x2>>z2;
    cout<<((x2-x1)/2+1)*((z2-z1)/2+1)+((x2-x1)/2)*((z2-z1)/2);

    return 0;
}