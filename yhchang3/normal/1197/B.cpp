#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> pillars(n);
	for(int i=0;i<n;i++)
		cin>>pillars[i];
	bool possible = true;
	bool increasing = true;
	int prev_pillar = 0;
	for(int pillar:pillars){
		if(increasing){
			if(prev_pillar < pillar)
				prev_pillar = pillar;
			else{
				prev_pillar = pillar;
				increasing = false;
			}
		}
		else{
			if(prev_pillar > pillar)
				prev_pillar = pillar;
			else{
				possible = false;
				break;
			}
		}
	}
	if(possible)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}