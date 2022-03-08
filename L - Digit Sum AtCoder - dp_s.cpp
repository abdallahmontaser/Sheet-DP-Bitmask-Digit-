#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int const Mod = 1e9 + 7;
int D, dp[10000][100][2];
vi ve;
int sol(int i, int rem, int flag)
{
	if (i == ve.size())
		return (rem == 0);
	int& ret = dp[i][rem][flag];
	if (~ret)
		return ret;
	ret = 0;
	for (int j = 0; j <= ((flag) ? 9 : ve[i]); j++)
	{
		ret += sol(i + 1, (rem + j) % D, flag | (j < ve[i])) % Mod;
		ret %= Mod;
	}
	return ret % Mod;
}
void solve()
{
	string S;
	cin >> S >> D;
	clr(dp, -1);
	for (auto& it : S) ve.push_back(it - '0');
	cout << ((sol(0, 0, 0) - 1) + Mod) % Mod;
}
int main()
{
	solve();
}
