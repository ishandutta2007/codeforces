#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double n,l,v1,v2,k,m;
int main(){
    cin>>n>>l>>v1>>v2>>k;
    m=ceil(n/k)-1;
    double x=2*m*l*v1/(2*m*v1+v2+v1);
    printf("%.10lf\n",x/v1+(l-x)/v2);
    return 0;
}