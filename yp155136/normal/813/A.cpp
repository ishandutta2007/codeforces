#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int sum=0;
    for (int i=0;n>i;i++) {
        int x;
        cin >> x;
        sum += x;
    }
    int q;
    cin >> q;
    while (q--) {
        int a,b;
        cin >>a >>b;
        if (a<=sum && sum<=b) {
            cout <<sum<<endl;
            return 0;
        }
        else if (a>sum) {
            cout<<a<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}