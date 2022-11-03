//
//  main.cpp
//  B
//
//  Created by  on 15/10/28.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

char a[27];
char old_name[200000+16];
char new_name[200000+16];

int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",old_name);
    getchar();
    for(int i=1;i<=26;i++){
        a[i]=96+i;
    }
    char c1,c2;
    int x1,x2;
    for(int i=1;i<=m;i++){
        scanf("%c",&c1);
        getchar();
        scanf("%c",&c2);
        getchar();
        for(int i=1;i<=26;i++){
            if(a[i]==c1) x1=i;
            if(a[i]==c2) x2=i;
        }
        char temp;
        temp=a[x1];
        a[x1]=a[x2];
        a[x2]=temp;
    }
    for(int i=0;i<n;i++){
        new_name[i]=a[old_name[i]-96];
        printf("%c",new_name[i]);
    }
    printf("\n");
    return 0;
}