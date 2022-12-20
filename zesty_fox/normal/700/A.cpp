#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,l,v1,k,v2,cs;
double ans,tmp,cur;
int main(){
    cin>>n>>l>>v1>>v2>>k;
    cs=(n%k?n/k+1:n/k);
    double t=1.0*l/(1.0*(cs-1)*2*v1*v2/(v1+v2)+v2);
    printf("%.10lf\n",1.0*(l-t*v2)/v1+t);
    return 0;
}