#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=100010;
typedef pair<int,int> pii;
typedef long long ll;
int n,maxn;
pii a[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;maxn=max(maxn,a[i].first);
    }
    for(int i=1;i<=100000000/n;i++){
        random_shuffle(a+1,a+n+1);
        ll sum1=0,sum2=0;
        for(int j=1;j<=n/2;j++) sum1+=a[j].first;
        for(int j=n/2+1;j<=n;j++) sum2+=a[j].first;
        if(abs(sum1-sum2)<=maxn){
            printf("%d\n",n/2);
            for(int j=1;j<=n/2;j++) printf("%d ",a[j].second);
            printf("\n%d\n",n-n/2);
            for(int j=n/2+1;j<=n;j++) printf("%d ",a[j].second);
            return 0;
        }
    }
    return 0;
}