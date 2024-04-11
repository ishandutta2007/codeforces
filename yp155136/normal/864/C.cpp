#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int a,b,f,k;
    cin >> a >> b >> f >> k;
    int cnt=0;
    int now=0;
    bool can_last = false;
    int nowf=b;
    if (b<f)
    {
        puts("-1");
        return 0;
    }
    for (int i=1;k>=i;i++)
    {
        if (i%2==1)
        {
            if (nowf < f)
            {
                puts("-1");
                return 0;
            }
            nowf -= abs(f-0);
            if (i==k)
            {
                if (nowf < abs(a-f))
                {
                    nowf = f;
                    ++cnt;
                    if (nowf < abs(a-f))
                    {
                        puts("-1");
                        return 0;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                int need = 2*abs(a-f);
                if (need > nowf)
                {
                    cnt++;
                    nowf = b;
                }
                nowf -= abs(a-f);
            }
        }
        else
        {
            if (nowf < abs(a-f))
            {
                puts("-1");
                return 0;
            }
            nowf -= abs(a-f);
            if (i==k)
            {
                if (nowf < f)
                {
                    nowf = f;
                    cnt++;
                    if (nowf < f)
                    {
                        puts("-1");
                        return 0;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                int need = 2*f;
                if (nowf < need)
                {
                    nowf = b;
                    cnt++;
                }
                nowf -= f;
            }
        }
    }
    cout << cnt << endl;
}