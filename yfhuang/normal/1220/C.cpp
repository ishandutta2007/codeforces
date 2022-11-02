#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 5e5 + 5;
char s[maxn];
int a[30];

int main(){
    while(scanf("%s", s + 1) != EOF){
        for(int i = 0;i < 30;i++){
            a[i] = 1;
        }   
        int len = strlen(s + 1);
        for(int i = 1;i <= len;i++){
            bool flag = false;
            for(int j = 0;j < s[i] - 'a';j++){
                if(a[j] == 0){
                    flag = true;
                }
            }
            if(!flag){
                a[s[i] - 'a'] = 0;
                printf("Mike\n");
            }else{
                printf("Ann\n");
            }
        }
    }
    return 0;
}