#include <iostream>
#include <cstdio>
using namespace std;

int main () {
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >>x;
        if (x%4 == 0) {
            cout<<x/4<<endl;
        }
        else if (x%4 == 1) {
            if (x < 9) cout<<-1<<endl;
            else cout<<1+(x-9)/4<<endl;
        }
        else if (x%4 == 2) {
            if (x<6) cout<<-1<<endl;
            else cout<<1+(x-6)/4<<endl;
        }
        else if (x%4 == 3) {
            if (x<15) cout<<-1<<endl;
            else cout<<2+(x-15)/4<<endl;
        }
    }
}