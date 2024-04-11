#include<stdio.h>
#include<string.h>
int num[261];
int main(){
    char str[11111];
    while(scanf("%s",&str)!=EOF){
        memset(num,0,sizeof(num));
        for(int i=0;str[i];i++){
            num[str[i]-'a']++;
        }
        int sum=0;
        for(int i=0;i<=26;i++){
            sum+=num[i]%2;
        }
        if(sum&1||sum==0)printf("First\n");
        else printf("Second\n");
    }
    return 0;
}