//
//  main.cpp
//  C
//
//  Created by  on 15/12/26.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxl=1e6+16;

char str[maxl];

int main(int argc, const char * argv[]) {
    scanf("%s",str+1);
    stack<char> s;
    int L=strlen(str+1);
    int ans=0;
    for(int i=1;i<=L;i++){
        if(s.empty()) s.push(str[i]);
        else{
            if(str[i]=='{'||str[i]=='<'||str[i]=='('||str[i]=='[')
                s.push(str[i]);
            else{
                if(s.top()!='{'&&s.top()!='['&&s.top()!='<'&&s.top()!='(')
                    s.push(str[i]);
                else{
                    if(s.top()=='{'){
                        if(str[i]!='}') ans++;
                        s.pop();
                    }
                    else if(s.top()=='['){
                        if(str[i]!=']') ans++;
                        s.pop();
                    }
                    else if(s.top()=='('){
                        if(str[i]!=')') ans++;
                        s.pop();
                    }
                    else if(s.top()=='<'){
                        if(str[i]!='>') ans++;
                        s.pop();
                    }
                }
            }
        }
    }
    if(!s.empty()) printf("Impossible\n");
    else printf("%d\n",ans);
    return 0;
}