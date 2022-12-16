#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int N=500010;
int a[N],n,cnt,p1,p2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);p1=(n>>1),p2=n;
    while(p1>=1&&p2>(n>>1)){
        if(a[p2]>=a[p1]*2) p2--,p1--,cnt++;
        else p1--;
    }
    cout<<n-cnt<<endl;
    return 0;
}