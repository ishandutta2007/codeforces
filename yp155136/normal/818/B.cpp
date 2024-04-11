#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int a[123];
int l[123];
int used[123];

int main (){
    int n,m;
    cin >> n >>m;
    for (int i=0;m>i;i++) {
        cin >> l[i];
    }
    for (int i=1;m>i;i++) {
        int val=(l[i]-l[i-1]);
        while (val > n) val-=n;
        while (val <=0) val+=n;
        if(a[l[i-1] ] == 0) {
            a[l[i-1] ] = val;
            used[val]++;
        }
        else if (a[l[i-1] ] == val) {
            ;
        }
        else {
            puts("-1");
            return 0;
        }
    }
    for (int i=1;n>=i;i++) {
        if (a[i] == 0) {
            for (int j=1;n>=j;j++) {
                if (!used[j]) {
                    a[i]=j;
                    used[j]++;
                    break;
                }
            }
        }
    }
    for (int i=1;n>=i;i++) {
        if (used[i]>=2) {
            puts("-1");
            return 0;
        }
    }
    for (int i=1;n>=i;i++) {
        if (i!=1) cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
}