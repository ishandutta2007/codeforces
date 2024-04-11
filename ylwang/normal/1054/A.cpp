#include<bits/stdc++.h>
using namespace std;
long long x,y,z,t1,t2,t3;
long long walk;
long long e;
int main()
{
    cin>>x>>y>>z>>t1>>t2>>t3;
    walk=abs(x-y)*t1;//
    e=abs((x-y))*t2+abs((x-z))*t2+3*t3;//
    if(e<=walk)//
    printf("YES");
    else
    printf("NO");
    return 0;
}