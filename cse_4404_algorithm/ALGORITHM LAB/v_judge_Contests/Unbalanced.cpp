// bismillahir rahmanir rahim
#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
#define sort(s) sort(s.begin(), s.end())
#define sortarr(s) sort(s, s + n)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frone(i, n) for (int i = 1; i <= n; i++)
#define reverse(s) reverse(s.begin(), s.end())
#define N 100000 + 10
#define MAX LONG_MAX
#define tc     \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define the_flash                  \
    ios_base ::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
int main()
{
    the_flash;
	string s;
	cin >> s;
	
	int n = s.length();
	bool flag=false;
	for(int i = 0; i < n - 1; i++){
		if(s[i] == s[i + 1]){
			cout << i + 1 << " " << i + 2 << endl;flag=true;
			break;
		}
		if(i + 2 < n && s[i] == s[i + 2]){
			cout << i + 1 << " " << i + 3 <<endl;flag=true;
			break;
		}
	}
	if(!flag)
	cout << "-1 -1"<<endl;
    return 0;
}