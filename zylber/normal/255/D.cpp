#include <iostream>
#include <algorithm>
using namespace std;

long long x, y;
long long n, c;

long long tr(long long t)
{
    return t*t;
}

long long p(long long mid)
{
    long long on=(mid+1LL)*(mid+1LL)+mid*mid;

            if(mid>x-1)
                on-=tr(mid-x+1);
            if(mid>y-1)
                on-=tr(mid-y+1);
            if(mid+y>n)
                on-=tr(mid+y-n);
            if(mid+x>n)
                on-=tr(mid+x-n);

            if(mid>x+y-1)
            {
                long long k=mid-x-y+1;
                on+=(k*(k+1))/2;
            }

            if(mid>y+n-x)
            {
                long long k=mid-y-n+x;
                on+=(k*(k+1))/2;
            }

            if(mid>x+n-y)
            {
                long long k=mid-x-n+y;
                on+=(k*(k+1))/2;
            }

            if(mid>n+n-x-y+1)
            {
                long long k=mid-n-n+x+y-1;
                on+=(k*(k+1))/2;
            }
    return on;
}

int main()
{
    cin >> n >> x >> y >> c;

    if(c==1)
        cout << 0 << endl;
    else
    {
        long long top=2LL*n, bot=0, mid=(top+bot)/2;
        while(top-bot>1)
        {
            long long on=p(mid);

            if(on>=c)
                top=mid;
            else
                bot=mid;

            mid=(top+bot)/2;
        }

        cout << top << endl;
    }

}