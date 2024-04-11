#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main (){
    int n, x = 1, cnt = 0;
    cin >> n;
    int a[] = {1,n};
    for(int i = 0; i < n; i++){
        x = x ^ 1;
        if(!x)cout << a[x]++ << ' ';
        else cout << a[x]-- << ' ';
    }
}