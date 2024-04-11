#include <iostream>
using namespace std;
int main()
{
    bool b[10]={0};
    int n;
    cin>>n;
    for (int i = 0; i < n; i ++){
        char x;
        cin>>x;
        if (x=='L'){
            for (int j=0;j<10;j++){
                if(!b[j]) {b[j]=true;break;}
        }}
        else {if (x=='R'){
            for (int j=9;j>=0;j--){
                if(!b[j]) {b[j]=true;break;}
            }
        }
        else
            b[x-48] = 0;}
    }
    for (int i = 0; i < 10 ; i++)
        cout<<(b[i]?1:0);
    return 0;
}