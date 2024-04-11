#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int x,y,s=0;
int main()
{   
    cin>>x>>y;
    s=abs(x)+abs(y);
    if(x>0 && y>0)
        cout<<"0 "<<s<<' '<<s<<" 0"<<endl;
    if(x>0 && y<0)
        cout<<"0 "<<-s<<' '<<s<<" 0"<<endl;
    if(x<0 && y>0)
        cout<<-s<<" 0 0 "<<s<<endl;
    if(x<0 && y<0)
        cout<<-s<<" 0 0 "<<-s<<endl;
    return 0;
}