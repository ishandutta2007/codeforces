#include <iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;

int dis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int main(){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if (x1==x2 || y1==y2){
        cout<<2*(dis(x1,y1,x2,y2)+3)<<endl;
    }
    else cout<<2*(dis(x1,y1,x2,y2)+2)<<endl;
    
}