#include <iostream>
using namespace std;
int n, m, k;
int main(){
    cin>>n>>m>>k;
    int sum=2*m*n;
    int line=(k-1)/(2*m)+1;
    k%=2*m;
    if(k==0) k=2*m;
    int desk=(k-1)/2+1;
    k%=2;
    if(k==1)
        cout<<line<<' '<<desk<<' '<<'L';
    else
        cout<<line<<' '<<desk<<' '<<'R';
}