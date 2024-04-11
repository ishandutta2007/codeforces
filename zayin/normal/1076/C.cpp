#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double d;
        cin>>d;
        double t=d*d-4*d;
        if (t<0)
            puts("N");
        else
        {
            t=sqrt(t);
            printf("Y %.9lf %.9lf\n",(d+t)/2,(d-t)/2);
        }
    }
    return 0;
}