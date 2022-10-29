#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    int n,k;
    cin >> n >> k;
    int sum=0;
    for (int i=0;n>i;i++) {
        int x;
        cin >> x;
        sum += x;
    }
    for (int ans=0;;ans++) {
        if (sum*2 >=n*(2*k-1) ) {
            cout<<ans<<endl;
            return 0;
        }
        sum += k;
        n++;
    }
}