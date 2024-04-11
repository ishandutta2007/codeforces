#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    for (int i=0;n>i;i++) cin >> a[i];
    for (int i=0;m>i;i++) cin >> b[i];
    for (int ii=1;99>=ii;ii++) {
        if (ii<10) {
            int d = ii;
            bool in_a=0,in_b=0;
            for (int i=0;n>i;i++) in_a |= (a[i]==d);
            for (int i=0;m>i;i++) in_b |= (b[i]==d);
            if (in_a && in_b) {
                cout<<ii<<endl;
                return 0;
            }
        }
        else {
            int d=ii/10;
            bool in_a=0,in_b=0;
            for (int i=0;n>i;i++) in_a |= (a[i]==d);
            for (int i=0;m>i;i++) in_b |= (b[i]==d);
            d=ii%10;
            for (int i=0;n>i;i++) in_a |= (a[i]==d);
            for (int i=0;m>i;i++) in_b |= (b[i]==d);
            if (in_a && in_b) {
                cout<<ii<<endl;
                return 0;
            }
        }
    }
}