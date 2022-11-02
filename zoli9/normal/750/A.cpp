#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
    cin>>n>>k;
    int cnt=0;
    while(cnt<n && k+(cnt+1)*5<=240)
    {
        k+=(cnt+1)*5;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}