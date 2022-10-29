#include <bits/stdc++.h>
using namespace std;

bool hhave[1004];

struct _
{
    int pri;
    int a[6];
    _(){}
    _(int _pri,int *s)
    {
        pri = _pri;
        for (int i=0;6>i;i++) a[i] = s[i];
    }
};

bool operator<(const _ &_1,const _ &_2)
{
    return _1.pri < _2.pri;
}

int s[6];

int main ()
{
    vector<_> v;
    int n;
    cin >> n;
    for (int i=0;n>i;i++)
    {
        for (int j=0;6>j;j++) cin >>s[j];
        v.push_back(_(i,s));
    }
    //cout << "gee"<<endl;
    do {
        for (int x=n/2;n/2+1>x;x++)
        {
            for (int k=0;6>k;k++)
            {
                int now = v[x].a[k];
                hhave[now] = 1;
                int __=now;
                for (int l=0;6>l;l++)
                {
                    if (x - 1 >= 0)
                    {
                        now = v[x-1].a[l]*10 + __;
                    }
                    hhave[now] = 1;
                    int ___ = now;
                    for (int r=0;6>r;r++)
                    {
                        if (x + 1 < n)
                        {
                            now = ___;
                            now *= 10;
                            now += v[x+1].a[r];
                        }
                        hhave[now] = 1;
                    }
                }
            }
        }
        //cout << "gggggg"<<endl;
    }
    while (next_permutation(v.begin(),v.end()));
    //cout << "finish"<<endl;
    int x=1;
    while (hhave[x]) x++;
    cout << x-1<<endl;
}