#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int i,j,k,l,n,m;
char a[105],temp[105];
int main(){
    scanf("%d%*c",&n);
    while(n--){
        int cnt = 0;
        bool flag = false;
        bool first = false;
        gets(a);
        int len = strlen(a);
        for(int i=len-5;i<=len;i++)
        temp[cnt++] = a[i];
        if(strncmp(a,"miao.",5)==0) first =true;
        if(strcmp(temp,"lala.")==0) flag = true;
        if(first && !flag) printf("Rainbow's\n");
        else if(!first && flag) printf("Freda's\n");
        else printf("OMG>.< I don't know!\n");
        }
}