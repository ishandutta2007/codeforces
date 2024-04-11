#include <iostream>
using namespace std;
int n, bo, ro, be, re;
int main(){
    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<n; i++){
        if(s[i]=='b'){
            if(i%2) bo++;
            else be++;
        }
        else{
            if(i%2) ro++;
            else re++;
        }
    }
    //if((ro==0&&be==0)||(re==0&&bo==0))
     //   cout<<0;
   // else{//all red even
        cout<< min(max(ro, be), max(re, bo));

//        if(ro>=re){
//            if(be>=bo){
//                if(ro>=bo)
//            }
//        }
//        if(ro-re>be-bo&&be>=bo){
//            if()
//        }
  //  }
}