//
//  main.cpp
//  D
//
//  Created by  on 15/12/30.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N=105;

char ans[N];

void print(char from,char to,long long len,long long occ){
    int st=1;
    if(from=='A') st=0;
    for(int i=0;i<len;i++) ans[i]='B';
    for(int i=0;i<occ;i++){
        ans[st+2*i]='A';
        ans[st+2*i+1]='C';
    }
    ans[0]=from;
    ans[len-1]=to;
    for(int i=0;i<len;i++) putchar(ans[i]);
    putchar('\n');
}

char start[N],finish[N];

long long occ[N];

int main(int argc, const char * argv[]) {
    long long k,x,n,m;
    cin>>k>>x>>n>>m;
    for(char from_1='A';from_1<='C';from_1++){
        for(char to_1='A';to_1<='C';to_1++){
            if(n==1&&from_1!=to_1) continue;
            else{
                for(char from_2='A';from_2<='C';from_2++){
                    for(char to_2='A';to_2<='C';to_2++){
                        if(m==1&&from_2!=to_2) continue;
                        else{
                            long long in_1=n-(from_1!='A')-(to_1!='C');
                            long long in_2=m-(from_2!='A')-(to_2!='C');
                            in_1/=2;
                            in_2/=2;
                            for(long long occ_1=0;occ_1<=in_1;occ_1++){
                                for(long long occ_2=0;occ_2<=in_2;occ_2++){
                                    if(n==2&&from_1=='A'&&to_1=='C'&&occ_1==0) continue;
                                    if(m==2&&from_2=='A'&&to_2=='C'&&occ_2==0) continue;
                                    start[1]=from_1;
                                    finish[1]=to_1;
                                    occ[1]=occ_1;
                                    start[2]=from_2;
                                    finish[2]=to_2;
                                    occ[2]=occ_2;
                                    for (long long i = 3; i <= k; i++) {
                                        start[i] = start[i - 2];
                                        finish[i] = finish[i - 1];
                                        occ[i] = occ[i - 2] + occ[i - 1] + (finish[i - 2] == 'A' && start[i - 1] == 'C');
                                    }
                                    if(occ[k]==x){
                                        print(from_1,to_1,n,occ_1);
                                        print(from_2, to_2, m, occ_2);
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Happy new year!\n");
    return 0;
}