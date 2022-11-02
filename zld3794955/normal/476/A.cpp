#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=m;i<=n;i+=m)
        if(i*2>=n && i<=n)
        {
            cout<<i<<endl;
            return 0;
        }
    cout<<-1<<endl;
    return 0;
}