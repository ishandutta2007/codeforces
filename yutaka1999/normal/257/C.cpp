#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define PI 3.1415926535897932384626

using namespace std;

double in[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==0&&y==0) continue;
        if(x==0)
        {
            if(y>0) in[i]=90.0;
            else in[i]=270.0;
        }
        else if(y==0)
        {
            if(x>0) in[i]=0.0;
            else in[i]=180.0;
        }
        else
        {
            int x1=max(x,-x);
            int y1=max(y,-y);
            double a=atan((double) y1/x1)/PI*180;
            if(0<y&&0<x) in[i]=a;
            else if(0<y) in[i]=180-a;
            else if(0<x) in[i]=360-a;
            else in[i]=180+a;
        }
    }
    sort(in,in+n);
    double ret=0;
    for(int i=1;i<n;i++)
    {
        ret=max(ret,in[i]-in[i-1]);
    }
    ret=max(ret,360-(in[n-1]-in[0]));
    printf("%.10lf\n",360-ret);
    return 0;
}