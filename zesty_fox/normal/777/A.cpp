#include<iostream>
using namespace std;
int a[1001][1001]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1},{0,1,2}};
int n,m;
int main()
{
    cin>>n>>m;
    cout<<a[n%6][m]<<endl;
    return 0;
}