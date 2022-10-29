#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

typedef long long LL;

int main () {
    priority_queue<LL> que;
    int n,f;
    scanf("%d %d",&n,&f);
    LL sum=0;
    for (int i=1;n>=i;i++) {
        LL a,b;
        scanf("%lld %lld",&a,&b);
        sum += min(a,b);
        if (b>a) que.push( (2*a>=b?b-a:a) );
        else que.push(0);
    }
    while (f--) {
        sum += que.top();
        que.pop();
    }
    cout<<sum<<endl;
}