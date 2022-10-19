#include <iostream>
using namespace std;
int l=0,r=0;
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if (x>0)
            r++;
        else
            l++;
    }
    if (l<2 || r<2){
        cout<<"Yes\n";
        return 0;
    }
    cout<<"No\n";
    return 0;
}