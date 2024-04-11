#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int n, r;
int x[1005];
int top[1005];
double y[1005];

int main()
{
    cin>>n>>r;
    for(int i = 0; i <= 1000; i++)
        top[i] = -1;
    for(int i = 0; i < n; i++)
    {
        double ma = r;
        cin>>x[i];
        for(int j = -r; j <= r; j++)
        {
            if(x[i]+j >= 0 && x[i]+j <= 1000)
            {
                int d = top[x[i]+j];
                if(d >= 0)
                {
                    double s = x[d];
                    double mid = (s+x[i])/2;
                    double u = mid-s;
                    double v = 2*sqrt((double)(r*r)-(double)(u*u))+y[d];
                    if(v > ma)
                        ma = v;
                }
                top[x[i]+j] = i;
            }
        }
        y[i] = ma;
    }
    for(int i = 0; i < n; i++)
        printf("%f ", y[i]);
    cout<<endl;
    return 0;
}