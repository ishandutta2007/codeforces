#include <iostream>
#include <vector>
using namespace std;
vector <pair<int, int> > p;
int x[3];
int y[3];
int main(){
    for(int i=0; i<3; i++)
        cin>>x[i]>>y[i];
    cout<<3<<'\n';
    for(int i=0; i<3; i++)
        cout<<x[(i+1)%3]+x[(i+2)%3]-x[i]<<' '<<y[(i+1)%3]+y[(i+2)%3]-y[i]<<'\n';

}