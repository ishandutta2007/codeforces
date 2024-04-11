//
//  main.cpp
//  A
//
//  Created by  on 10/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

char s[20];
int dig[20];

int num[10];
char ans[1000];


int main(int argc, const char * argv[]) {
    cin >> n;
    scanf("%s",s + 1);
    memset(num,0,sizeof(num));
    for(int j = 1;j <= n;j++){
        dig[j] = s[j] - '0';
        for(int i = 2;i <= dig[j];i++){
            if(i == 2){
                num[2]++;
            }else if(i == 3){
                num[3]++;
            }else if(i == 4){
                num[2] += 2;
            }else if(i == 5){
                num[5]++;
            }else if(i == 6){
                num[2]++;
                num[3]++;
            }else if(i == 7){
                num[7]++;
            }
            else if(i == 8){
                num[2] += 3;
            }else if(i == 9){
                num[3] += 2;
            }
        }
    }
   // cout << num[2] << " " << num[3] <<  " " << num[5] << " " << num[7] << endl;
    int now = 0;
    while(num[7] > 0){
        ans[++now] = 7 + '0';
        num[7]--;
        num[5]--;
        num[3]-= 2;
        num[2]-= 4;
    }
    while(num[5] > 0){
        ans[++now] = 5 + '0';
        num[5]--;
        num[3]--;
        num[2] -= 3;
    }
    while(num[3] > 0){
        ans[++now] = 3 + '0';
        num[3]--;
        num[2]--;
    }
    while(num[2] > 0){
        ans[++now] = 2 + '0';
        num[2]--;
    }
    ans[++now] = 0;
    printf("%s\n",ans + 1);
    return 0;
}