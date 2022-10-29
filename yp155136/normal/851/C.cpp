#include <bits/stdc++.h>
using namespace std;

const int N = 1006;
const int K = 106;

struct _
{
    int a,b,c,d,e;
    _(){}
    _(int _a,int _b,int _c,int _d,int _e):a(_a),b(_b),c(_c),d(_d),e(_e){}
};

_ operator-(const _ &_1,const _ &_2)
{
    return _(_1.a-_2.a,_1.b-_2.b,_1.c-_2.c,_1.d-_2.d,_1.e-_2.e);
}

int dott(_ _1,_ _2)
{
    return _1.a*_2.a + _1.b*_2.b+_1.c*_2.c+_1.d*_2.d+_1.e*_2.e;
}

_ p[N];

int main ()
{
    int n;
    scanf("%d",&n);
    if (n > K)
    {
        puts("0");
        return 0;
    }
    for (int i=1;n>=i;i++)
    {
        int a,b,c,d,e;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        p[i] = _(a,b,c,d,e);
    }
    vector<int> ans;
    for (int i=1;n>=i;i++)
    {
        bool can=true;
        for (int j=1;n>=j;j++)
        {
            for (int k=1;n>=k;k++)
            {
                if (i==j||j==k||i==k) continue;
                _ __ = p[i]-p[j],___ = p[i]-p[k];
                if (dott(__,___) > 0) can=false;
            }
        }
        if (can) ans.push_back(i);
    }
    printf("%d\n",(int)ans.size());
    for (int i=0;ans.size()>i;i++)
    {
        printf("%d%c",ans[i]," \n"[i==(int)ans.size()-1]);
    }
}