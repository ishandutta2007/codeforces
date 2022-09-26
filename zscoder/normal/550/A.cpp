#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define first fi
#define second se
#define pb push_back

const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int loc,ant;
    loc=s.find("AB",0);
    ant=s.find("BA",loc+2);
    //cout <<loc<<" "<<ant<<endl;
    if(loc!=-1&&ant!=-1)
    {
        cout <<"YES\n";
        return 0;
    }
    loc=s.find("BA",0);
    ant=s.find("AB",loc+2);
    if(loc!=-1&&ant!=-1)
    {
        cout <<"YES\n";
        return 0;
    }
    cout <<"NO\n";
	return 0;
}

/*B
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

/*C
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/


/*D
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

/*E
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/