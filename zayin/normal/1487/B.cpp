#include<bits/stdc++.h>
using namespace std;
int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m),--m;
        // cout<<"???:"<<m%n<<" "<<m/(n/2)<<endl;
        if (~n&1)
            printf("%d\n",m%n+1);
        else
            printf("%d\n",(m%n+m/(n/2))%n+1);
    }
    return 0;
}