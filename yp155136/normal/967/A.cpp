#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int cal(int l,int r)
{
    return upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),l);
}

int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    for (int i=1;n>=i;i++)
    {
        int h,m;
        scanf("%d %d",&h,&m);
        v.push_back(h*60 + m);
    }
    for (int i=0;;i++)
    {
        if (cal(i-s,i+s) == 0)
        {
            cout << i/60 << ' ' << i%60 <<endl;
            return 0;
        }
    }
}