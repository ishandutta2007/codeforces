#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[3];

int main(){
    int t;
    cin >> t;
    while(t--){
    for(int i = 0;i < 3;i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + 3);
    if(a[2] <= a[1] + a[0] + 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    }
    return 0;
}