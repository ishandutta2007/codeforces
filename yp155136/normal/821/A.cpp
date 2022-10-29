#include <iostream>
#include <stdio.h>
using namespace std;

int main (){
    int n;
    cin >> n;
    int a[n][n];
    for (int i=0;n>i;i++) {
        for (int j=0;n>j;j++) {
            cin >>a[i][j];
        }
    }
    string ans="Yes";
    for (int i=0;n>i;i++) {
        for (int j=0;n>j;j++) {
            if (a[i][j] != 1) {
                bool found=false;
                for (int s=0;n>s;s++) {
                    for (int t=0;n>t;t++) {
                        if (a[i][j] == a[i][s] + a[t][j]) found=true;
                    }
                }
                if (found==false) ans="No";
            }
        }
    }
    cout<<ans<<endl;
}