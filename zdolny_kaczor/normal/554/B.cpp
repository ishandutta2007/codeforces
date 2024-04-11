# include <iostream>
# include <string>
# include <map>
using namespace std;
map <string, int> cou;
int main()
{
    int n;
    
    cin >> n;
    
    string temp;
    for (int i=0; i<n; ++i)
    
    {
        cin >> temp;
        
        cou[temp]++;
        
    }
    int res=0;
    for (auto x : cou)
        if (x.second>res)
            res=x.second;
            
cout << res << endl;
    

}