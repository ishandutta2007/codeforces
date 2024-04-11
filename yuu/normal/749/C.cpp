#include <iostream>
using namespace std;
int n;
bool dd[200002];
string s;
void process(){
    int d=0,r=0;
    bool check1,check2;
    while(1){
        check1=0; check2=0;
        for(int i=1;i<=n;i++)
			if(dd[i]==0){
				if(s[i-1]=='D'){
					if(d>0){
						d--;
						dd[i]=1;
					}
					else r++;
				}
				else{
					if(r>0){
						r--;
						dd[i]=1;
					}
					else d++;
				}
			}
        for(int i=1;i<=n;i++)
			if(dd[i]==0){
				if(s[i-1]=='D')
					check1=1;
				else check2=1;
			}
        if(check1==1&&check2==0){
			cout<<'D';
			return;
		}
        else if(check1==0&&check2==1){
			cout<<'R';
			return;
		}
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
	process();
}