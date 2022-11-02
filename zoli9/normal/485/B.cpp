#include <iostream>
using namespace std;
int n;
long long x[1001];
long long y[1001];
long long xmin, xmax, ymin, ymax;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i];
    }
    xmin=x[1];
    xmax=x[1];
    ymin=y[1];
    ymax=y[1];
    for(int i=2; i<=n; i++)
    {
        if(x[i]<xmin)
        {
            xmin=x[i];
        }
        if(x[i]>xmax)
        {
            xmax=x[i];
        }
        if(y[i]<ymin)
        {
            ymin=y[i];
        }
        if(y[i]>ymax)
        {
            ymax=y[i];
        }
    }


    cout<<max(xmax-xmin, ymax-ymin)*max(xmax-xmin, ymax-ymin);

    return 0;
}