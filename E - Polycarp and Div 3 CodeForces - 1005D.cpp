#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
int dp[(int)2e5 + 50][5];
vi ve;
int sol(int i, int rem)
{
	if (i == ve.size())
		return 0;
	int& ret = dp[i][rem];
	if (~ret)
		return ret;
	int tem;
	if (rem == 4)
		tem = ve[i] % 3;
	else
		tem = ((rem * 10) + ve[i]) % 3;
	ret = sol(i + 1, tem);
	if (tem == 0)
		ret = max(ret, 1 + sol(i + 1, 4));
	else
		ret = max(ret, sol(i + 1, 4));
	return ret;
}
void solve()
{
	string S; cin >> S;
	clr(dp, -1);
	for (auto& it : S) ve.push_back(it - '0');
	cout << sol(0, 4);
}
int main()
{
	solve();
}
