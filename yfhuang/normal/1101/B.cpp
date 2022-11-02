#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

char s[500005];

int main(){
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int i = 1;
    for(;i <= len;i++){
        if(s[i] == '['){
            break;
        }
    }
    for(;i <= len;i++){
        if(s[i] == ':'){
            break;
        }
    }
    int j = len;
    for(;j >= 1;j--){
        if(s[j] == ']'){
            break;
        }
    }
    for(;j >= 1;j--){
        if(s[j] == ':'){
            break;
        }
    }
    if(i >= j){
        puts("-1");
    }else{
        int cnt = 0;
        for(int k = i;k <= j;k++){
            if(s[k] == '|'){
                cnt++;
            }
        }
        cout << cnt + 4 << endl;
    }
    return 0;
}