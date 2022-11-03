//
//  main.cpp
//  A
//
//  Created by  on 15/11/16.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

int main(int argc, const char * argv[]) {
    int n;
    int x1,x2,y1,y2,x3,x4,y3,y4;
    int area;
    scanf("%d",&n);
    if(n==1){
        scanf("%d%d",&x1,&y1);
        printf("-1\n");
    }
    if(n==2){
        scanf("%d%d",&x1,&y1);
        scanf("%d%d",&x2,&y2);
        if(x1==x2||y1==y2) printf("-1\n");
        else { area=abs(x1-x2)*abs(y1-y2); printf("%d\n",area);}
    }
    if(n==3){
        scanf("%d%d",&x1,&y1);
        scanf("%d%d",&x2,&y2);
        scanf("%d%d",&x3,&y3);
        if(x1==x2){
            if(y2==y3) area=abs(y1-y2)*abs(x2-x3);
            else if(y1==y3) area=abs(y1-y2)*abs(x3-x1);
        }
        if(x1==x3){
            if(y2==y3) area=abs(y1-y3)*abs(x2-x3);
            else if(y1==y2) area=abs(y3-y2)*abs(x2-x1);
        }
        if(x2==x3){
            if(y2==y1) area=abs(y2-y3)*abs(x2-x1);
            else if(y1==y3) area=abs(y3-y2)*abs(x3-x1);
        }
        printf("%d\n",area);
    }
    if(n==4){
        scanf("%d%d",&x1,&y1);
        scanf("%d%d",&x2,&y2);
        scanf("%d%d",&x3,&y3);
        scanf("%d%d",&x4,&y4);
        double x0=(x1+x2+x3+x4)/4.0,y0=(y1+y2+y3+y4)/4.0;
        area=(int)(4*fabs(x0-x1)*fabs(y0-y1));
        printf("%d\n",area);
    }
    return 0;
}