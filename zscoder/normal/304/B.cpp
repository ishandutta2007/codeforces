#include <iostream>
using namespace std;

int get(int y,int m,int d){
    if(m<3){
        --y;
        m+=12;
    }
    return 365*y+y/4 - y/100+y/400+(153*m - 457)/5+d - 306;
}

int Abs(int x){
    return x<0?-x:x;
}

int main(){
    char t;
    int y,m,d,Y,M,D;
    cin >> y >> t >> m >> t >> d;
    cin >> Y >> t >> M >> t >> D;
    cout << Abs(get(Y,M,D)-get(y,m,d)) << endl;
    return 0;
}