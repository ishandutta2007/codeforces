#include <bits/stdc++.h>
using namespace std;

int a[1234];

int main ()
{
    int n;
    scanf("%d",&n);
    vector<int> v;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=1;n>=i;i++)
    {
        if (a[i] >= a[i+1]) v.push_back(a[i]);
    }
    printf("%d\n",(int)v.size());
    for (int i=0;(int)v.size()>i;i++)
    {
        printf("%d%c",v[i]," \n"[i == (int)v.size()-1]);
    }
}