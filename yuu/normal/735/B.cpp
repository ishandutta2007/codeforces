#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int n, n1, n2;
int a[100001];
long double ans;
int main(){
    scanf("%i%i%i", &n, &n1, &n2);
    if(n1>n2) swap(n1, n2);
    for(int i=1; i<=n; i++)
        scanf("%i", &a[i]);
    sort(a+1, a+n+1);
    int fp=n-n1-n2+1;
    long long w1=0, w2=0;
    for(int j=n; j>=n-n1+1; j--)
        w1+=a[j];
    for(int j=n-n1; j>=fp; j--)
        w2+=a[j];
    cout<<setprecision(8)<<fixed<<(long double)w1/n1+(long double)w2/n2;
}