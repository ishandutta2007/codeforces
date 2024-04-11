#include <iostream>
using namespace std;
int main()
{
    int ten,hun;
    cin >> hun >> ten;
    while(1){
        if (hun >= 2 && ten >= 2){
            hun -= 2;
            ten -= 2;
        }
        else if(hun >= 1 && ten >= 12){
            hun--;
            ten -= 12;
        }
        else if(ten >= 22){
            ten -= 22;
        }
        else{
            cout << "Hanako";
            break;
        }

        if (ten >= 22){
            ten -= 22;
        }
        else if(hun >= 1 && ten >= 12){
            hun--;
            ten -= 12;
        }
        else if(hun >= 2 && ten >= 2){
            ten -= 2;
            hun -= 2;
        }
        else{
            cout << "Ciel";
            break;
        }
    }
}