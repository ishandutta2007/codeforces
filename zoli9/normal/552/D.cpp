#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
long long ere;
long long vege=0;
long long ossz;
bool nemkell[100009];
struct pont
{
    int az, x, y;
};
pont t[100009];
pont kon[100009];
int db;
int minhely;
long long tav(pont a, pont b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int fir(pont o, pont x, pont y)
{
    long long cc=(x.x-o.x)*(y.y-o.y)-(x.y-o.y)*(y.x-o.x);
    if(cc>0)
    {
        return 1;
    }
    else if(cc<0)
    {
        return -1;
    }
    return 0;
}
int rendez(const void *a, const void *b)
{
    pont c=(*(pont*)a);
    pont d=(*(pont*)b);
    if(fir(t[1], c, d)>0)
    {
        return -1;
    }
    else if(fir(t[1], c, d)<0)
    {
        return 1;
    }
    if(tav(t[1], c)<tav(t[1], d))
    {
        return -1;
    }
    else if(tav(t[1], c)>tav(t[1], d))
    {
        return 1;
    }
    return 0;
}
int main()
{
    cin>>n;
    ere=n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i].x>>t[i].y;
        t[i].az=i;
    }


    while(n>=3)
    {
        minhely=1;
    for(int i=2; i<=n; i++)
    {
        if(t[minhely].y>t[i].y)
        {
            minhely=i;
        }
        else if(t[minhely].y==t[i].y)
        {
            if(t[minhely].x>t[i].x)
            {
                minhely=i;
            }
        }
    }
    swap(t[1], t[minhely]);
    qsort(t+2, n-1, sizeof(pont), rendez);
    int i=2;
    while(i<n)
    {
        int cnt=1;
        while(fir(t[1], t[i], t[i+1])==0)
        {
            cnt++;
            i++;
            if(i==n)
            {
                break;
            }
        }
        //cout<<cnt<<" ";
        vege+=(cnt*(cnt-1)/2);
        i++;
    }
    swap(t[1], t[n]);
    n--;
    }
    if(ere<=2)
    {
        ossz=0;
    }
    else
    {
        ossz=ere*(ere-1)*(ere-2);
        ossz/=6;
    }
    cout<<ossz-vege;

    return 0;
}