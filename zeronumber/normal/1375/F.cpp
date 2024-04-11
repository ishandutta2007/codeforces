#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e5+3;
const int M=1000000007;
const ll E=10000000000ll;
ll a[3],s,t;
int ask(){
    int ret; scanf("%d",&ret);
    if (!ret) exit(0);
    return ret-1;
}
int main(){
    cin >> a[0] >> a[1] >> a[2];
    puts("First"); fflush(stdout);
    printf("%lld\n",E); fflush(stdout);
    int x=ask();
    a[x]+=E;
    s=a[x]*3-(a[0]+a[1]+a[2]);
    printf("%lld\n",s); fflush(stdout);
    int y=ask();
    a[y]+=s;
    t=abs(a[(y+1)%3]-a[(y+2)%3]);
    printf("%lld\n",t); fflush(stdout);
    int z=ask();
    assert(0);
    return 0;
}