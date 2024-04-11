#include <iostream>
#include <cstdio>
using namespace std;

int main () {
    long long int n,k;
    while (cin >>n >> k) {
        int t=1;
        while (k%2==0) {
            t++;
            k/=2;
        }
        printf("%d\n",t);
    }
}