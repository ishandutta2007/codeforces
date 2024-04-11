#include <cstdio>

using namespace std;

int s,v1,t1,v2,t2;

int main(){
    while(scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2) != EOF){
        int x1 = 2 * t1 + s * v1;
        int x2 = 2 * t2 + s * v2;
        if(x1 < x2) printf("First\n");
        else if(x1 > x2) printf("Second\n");
        else printf("Friendship\n");
    }

    return 0;
}