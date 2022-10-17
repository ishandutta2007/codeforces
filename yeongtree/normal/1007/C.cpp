#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long int n; cin>>n;
    long long int x1=1,x2=n+1,x3=n+1,y1=1,y2=n+1,y3=n+1;
    while(1)
    {
        long double _x1=x1,_x2=x2,_x3=x3,_y1=y1,_y2=y2,_y3=y3;
        long double A=(_x2-_x1)*(_y2-_y1);
        long double B=(_x3-_x2)*(_y2-_y1);
        long double C=(_x2-_x1)*(_y3-_y2);
        if(B>A+C)
        {
            long long int midy=(y1+y2)/2;
            cout<<x2<<" "<<midy<<endl;
            fflush(stdout);
            int ans; cin>>ans;
            if(!ans) break;
            switch(ans)
            {
            case 1:
                x1=x2+1; x2=x3; y3=y2;
                break;
            case 2:
                y1=midy+1;
                break;
            case 3:
                y2=midy;
                break;
            }
        }
        else if(C>A+B)
        {
            long long int midx=(x1+x2)/2;
            cout<<midx<<" "<<y2<<endl;
            fflush(stdout);
            int ans; cin>>ans;
            if(!ans) break;
            switch(ans)
            {
            case 1:
                x1=midx+1;
                break;
            case 2:
                y1=y2+1; y2=y3; x3=x2;
                break;
            case 3:
                x2=midx;
                break;
            }
        }
        else
        {
            long long int midx=(x1+x2)/2;
            long long int midy=(y1+y2)/2;
            cout<<midx<<" "<<midy<<endl;
            fflush(stdout);
            int ans; cin>>ans;
            if(!ans) break;
            switch(ans)
            {
            case 1:
                x1=midx+1;
                break;
            case 2:
                y1=midy+1;
                break;
            case 3:
                x2=midx; y2=midy;
                break;
            }
        }
    }
    return 0;
}