#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 3000 + 5;
char str[maxn];
int main(){
    char pre;
    int num;
    int type;
    scanf("%s",str + 1);
    int n = strlen(str + 1);
    for(int i = 1;i <= n;i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            num = 0;
            type = 0;
            putchar(str[i]);
        }else{
            if(num == 0){
                pre = str[i];
                num = 1;
                type = 1;
                putchar(str[i]);
            } else{
                if(type == 1){
                    if(str[i] != pre)
                        type++,num++;
                    else num++;
                    if(type > 1){
                        if(num >= 3){
                            putchar(' ');
                            putchar(str[i]);
                            type = 1;
                            pre = str[i];
                            num = 1;
                        }else putchar(str[i]);
                    }else{
                        putchar(str[i]);
                    }
                }else{
                    num++;
                    if(num >= 3){
                        putchar(' ');
                        putchar(str[i]);
                        type = 1;
                        pre = str[i];
                        num = 1;
                    }else{
                        putchar(str[i]);
                    }
                }
            }
        }
    }
    cout << endl;
    return 0;
}