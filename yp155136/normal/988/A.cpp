#include <bits/stdc++.h>
using namespace std;

int a[106];

int main ()
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v;
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        a[x] = i;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    if (v.size() < k) puts("NO");
    else
    {
        puts("YES");
        for (int i:v)
        {
            cout << a[i] << ' ';
            --k;
            if (!k) break;
        }
    }
}