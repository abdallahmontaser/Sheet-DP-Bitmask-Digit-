#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int const Mod = 1e9 + 7;
int M, D, dp[2000][2000][2][2];
vi a, b;
int sol(int idx, int rem, int flag1, int flag2)
{
	if (idx == b.size())
		return (rem == 0);
	int& ret = dp[idx][rem][flag1][flag2];
	if (~ret)
		return ret;
	ret = 0;
	if (idx % 2)
	{
		if ((!flag1 && D > b[idx]) || (!flag2 && D < a[idx]))
			return ret;
		ret = sol(idx + 1, ((rem * 10) + D) % M, flag1 | (D < b[idx]), flag2 | (D > a[idx])) % Mod;
	}
	else
	{
		for (int i = ((flag2 == 0) ? a[idx] : 0); i <= ((flag1 == 0) ? b[idx] : 9); i++)
		{
			if (i != D)
				ret += sol(idx + 1, ((rem * 10) + i) % M, flag1 | (i < b[idx]), flag2 | (i > a[idx])) % Mod;
			ret %= Mod;
		}
	}
	return ret % Mod;
}
void solve()
{
	cin >> M >> D;
	string A, B; cin >> A >> B;
	clr(dp, -1);
	for (auto& it : A)a.push_back(it - '0');
	for (auto& it : B)b.push_back(it - '0');
	cout << sol(0, 0, 0, 0) % Mod;
}
int main()
{
	solve();
}
