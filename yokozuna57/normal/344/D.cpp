#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int siz=s.size();
    int a[100000+2],k=0;
    for(int i=0;i<siz;i++){
        if(s[i]=='+')a[k]=0;
        else a[k]=1;
        if(k!=0){
            if(a[k]==a[k-1])k--;
            else k++;
        }
        else k++;
    }
    if(k==0)printf("Yes\n");
    else printf("No\n");
}