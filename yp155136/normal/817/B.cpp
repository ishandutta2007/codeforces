#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 6;

int a[MAX_N];

int main () {
    int n;
    cin >> n;
    for (int i=0;n>i;i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    a[n] = 1234567890;
    long long haha=2;
    for (int i=3;n>i;i++) {
        if (a[i] == a[2]) haha=i;
        else break;
    }
    if (haha == 2) puts("1");
    else {
        if (a[0] ==a[1] && a[1] == a[2]) cout<<(haha+1)*(haha)*(haha-1)/6<<endl;
        else if (a[1] == a[2]) cout<<(haha)*(haha-1)/2;
        else cout<<haha-1<<endl;
    }
}