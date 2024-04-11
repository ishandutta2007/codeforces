#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
long long x;
char c[100005];
int t[30];
int ren(const void *a, const void *b)
{
    return (*(int*)b)-(*(int*)a);
}
int main()
{
    cin>>n>>k;
    for(int i=0; i<26; i++)
    {
        t[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
        t[(c[i]-'A')]++;
    }
    qsort(t, 26, sizeof(int), ren);
    x=0;
    int i=0;
    while(k>0)
    {
        if(k>=t[i])
        {
            long long z=t[i];
            x+=z*z;
            k-=t[i];
        }
        else
        {
            long long zz=k;
            x+=zz*zz;
            k=0;
        }
        i++;
    }
    cout<<x;


    return 0;
}