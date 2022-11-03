//
//  main.cpp
//  B
//
//  Created by  on 16/4/17.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

char s[1000];
int a[1000];
int cnt;

int main(int argc, const char * argv[]) {
    scanf("%s",s);
    char c;
    int pos = 1,neg = 0;
    cnt = 0;
    a[cnt++] = 1;
    while(cin >> c && c != '='){
        if(c == '+') {pos++;a[cnt++] = 1;}
        if(c=='-'){neg++;a[cnt++] = -1;}
    }
    cin >> n;
    if(n * pos - neg >= n && pos - n * neg <=n){
        //cout << pos << neg << endl;
        printf("Possible\n");
        int i;
        for(i = 1;i * pos - n * neg <= n;i++){
            if(i * pos - n >= neg && i * pos - n <= n * neg) break;
        }
        int sum = i * pos - n;
        for(int j = 0;j <cnt;j++){
            if(j == 0){
                cout << i << ' ';
            }else{
                if(a[j] == 1){
                    cout << '+'<<' ' << i<< ' ';
                }else{
                    int x = min(n,sum - (neg - 1));
                    cout << '-'  <<' '<< x << ' ';
                    sum -= x;
                    neg--;
                }
            }
        }
        cout <<'='<<' '<<n<<endl;
    }else{
        printf("Impossible\n");
    }
    return 0;
}