#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX_N = 106;

int a[MAX_N][MAX_N];

int main () {
    int n,k;
    cin >> n >> k;
    if (k > n*n) {
        puts("-1");
        return 0;
    }
    for (int i=1;n>=i;i++) {
        for (int j=i;n>=j;j++) {
            if (i==j && k>0) {
                a[i][j] = 1;
                k--;
            }
            else if (i!=j && k>=2) {
                k-=2;
                a[i][j] = a[j][i] = 1;
            }
        }
    }
    for (int i=1;n>=i;i++) {
        for (int j=1;n>=j;j++) {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}