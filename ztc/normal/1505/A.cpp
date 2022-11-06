#include<stdio.h>
int main(){
    while(1){
        char c=getchar();
        while(c!=EOF&&c!=10)c=getchar();
        if(c==EOF)return 0;
        puts("NO");
        fflush(stdout);
    }
}