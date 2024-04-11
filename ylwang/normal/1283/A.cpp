#include<bits/stdc++.h>  //
using namespace std;
int main() //
{
    int h,m,t; //
    cin>>t;
    for(int i=1;i<=t;i++) //
    {
        cin>>h>>m;
        cout<<60*(24-h-1)+60-m<<endl; //
    }
    return 0; //
 }