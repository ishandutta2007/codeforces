#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld eps = 1e-10;

const int N = 200006;

long long a[N];
int t[N];

bool eq(ld a,ld b)
{
    return fabs(a-b) <= eps;
}

#define check(up,down,T) if(eq(up/down,T)){cout<< fixed<<setprecision(15)<<down<<endl;return 0;}

int main ()
{
    int n,T;
    cin >> n >> T;
    vector<int> v;
    bool gee1=0,gee2=0;
    bool gee3 = 0;
    for (int i=1;n>=i;i++)
    {
        cin >> a[i];
        v.push_back(i);
    }
    ld down=0;
    ld up = 0;
    for (int i=1;n>=i;i++)
    {
        cin >> t[i];
        if (t[i] > T) gee1 = true;
        if (t[i] < T) gee2 = true;
        if (t[i] == T) gee3 = true;
        down += a[i];
        up += t[i]*1LL*a[i];
    }
    if (((gee1 ^ gee2)) && !gee3)
    {
        cout << 0 << endl;
        return 0;
    }
    check(up,down,T);
    sort(v.begin(),v.end(),[](const int &a,const int &b)
     {
         return t[a] < t[b];
     });
    if (up/down > T)
    {
        //erase big value
        //cout << "in 2 "<<endl;
        reverse(v.begin(),v.end());
        for (int i:v)
        {
            //first delete all
            up -= a[i] * t[i];
            down -= a[i];
            check(up,down,T);
            //cout << "up = "<<up<<" , down = "<<down<<endl;
            if (up/down < T)
            {
                //cout << "haha"<<endl;
                up += a[i] * t[i];
                down += a[i];
                ld L=0,R=a[i];
                int cnt = 1000;
                while (cnt--)
                {
                    ld mid = (L+R)/2;
                    ld newup = up - mid * t[i];
                    ld newdown = down - mid;
                    check(newup,newdown,T);
                    if (newup/newdown > T) L = mid;
                    else R = mid;
                }
            }
        }
    }
    else if (up/down < T)
    {
        //erase small value
        //cout << "in 1" << endl;
        for (int i:v)
        {
            //first delete all
            up -= a[i] * t[i];
            down -= a[i];
            check(up,down,T);
            if (up/down > T)
            {
                //cout << "innn"<<endl;
                up += a[i] * t[i];
                down += a[i];
                ld L=0,R=a[i];
                int cnt = 1000;
                while (cnt--)
                {
                    ld mid = (L+R)/2;
                    ld newup = up - mid * t[i];
                    ld newdown = down - mid;
                    check(newup,newdown,T);
                    if (newup/newdown < T) L = mid;
                    else R = mid;
                }
            }
        }
    }
}