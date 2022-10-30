#include<bits/stdc++.h>
using namespace std;
int main()  {
    int n;
    scanf("%d",&n);
    int t=n;
    for (int i=2;i<t;++i)   {
        while (n%i==0)
            printf("%d",i),n/=i;
        // cout<<i<<":"<<n<<endl;
    }
    return 0;
}