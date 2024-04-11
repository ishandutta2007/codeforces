//
//  main.cpp
//  A
//
//  Created by  on 16/1/21.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int x1,x2,y1,y2;

int main(int argc, const char * argv[]) {
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("%d\n",max(abs(x1-x2),abs(y1-y2)));
    return 0;
}