#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    scanf("%d",&n);
    vector<int> nz;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a!=0)nz.push_back(i);
    }
    if(nz.empty())
        return 0*printf("0\n");
    if(nz.size()==(size_t)(nz.back()-nz.front()+1))
        return 0*printf("1\n");
    return 0*printf("2\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}