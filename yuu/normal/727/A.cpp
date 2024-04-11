#include <stdio.h>
#include <vector>
using namespace std;
int a, b;
vector <int> t;
int make(int x){
    if(x%2){
        if(x%10==1) return x/10;
        else return -1;
    }
    return x/2;
}
int main(){
    scanf("%i%i", &a, &b);
    t.push_back(b);
    while((b=make(b))>a)
        t.push_back(b);
    if(b==a){
        printf("YES\n%d\n%d", t.size()+1, a);
        for(int x= t.size()-1; x>=0; x--)
            printf(" %d", t[x]);
    }
    else printf("NO");
}