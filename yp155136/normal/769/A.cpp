#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
        int a[n];
        for (int i=0;n>i;i++) {
            cin >>a[i];
        }
        sort(a,a+n);
        cout<<a[n/2]<<endl;
    }
}