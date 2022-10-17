#include <iostream>

using namespace std;

void f(int x,int y)
{
    if(x==1)
    {
        cout<<y;
        return;
    }
    if(x==2)
    {
        cout<<y<<" "<<2*y;
        return;
    }
    if(x==3)
    {
        cout<<y<<" "<<y<<" "<<3*y;
        return;
    }
    for(int i=0;i<(x+1)/2;i++) cout<<y<<" ";
    f(x/2,y*2);
    return;
}

int main()
{
    int n; cin>>n;
    f(n,1);
    return 0;
}