#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    A+=1,C-=1;

    int ans=min(min(A,B),C);
    printf("%d\n",ans*3);
    return 0;
}