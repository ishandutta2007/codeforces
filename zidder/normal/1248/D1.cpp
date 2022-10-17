//The World Is Just a Programming Task (Easy Version)
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	int n;
	cin >> n >> s;
	int max_beauty=0;
	pair<int, int> max_swap;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char tmp = s[j];
			s[j] = s[i];
			s[i] = tmp;
			int beauty=0, min_elem=0, c=0;
			for(int ind = 0;ind<n;ind++){
				if (s[ind] == '(')
					c++;
				else
					c--;
				if (c < min_elem){
					min_elem = c;
					beauty = 0;
				}
				if (c == min_elem){
					beauty++;	
				}
			}
			if (c != 0)
				break;
			s[i] = s[j];
			s[j] = tmp;
			if (beauty > max_beauty || max_beauty == -1){
				max_beauty = beauty;
				max_swap = {i, j};
			}
		}
	}
	cout << max_beauty << endl;
	cout << max_swap.first + 1 << " " << max_swap.second + 1 << endl;
	return 0;
}