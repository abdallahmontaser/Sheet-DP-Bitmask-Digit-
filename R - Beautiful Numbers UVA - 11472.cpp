#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int countBits1(int num) { int cnt = 0; while (num) { cnt++, num &= (num - 1); }return cnt; }
int const Mod = 1e9 + 7;
int N, M;
int dp[100][1 << 10][11];
int sol(int i, int mask, int prev)
{
	if (i == M)
		return (countBits1(mask) == N);
	int& ret = dp[i][mask][prev];
	if (~ret)
		return ret;
	ret = (countBits1(mask) == N);
	for (int j = ((i == 0) ? 1 : max(0, prev - 1)); j <= ((i == 0) ? N - 1 : min(N - 1, prev + 1)); j++)
	{
		if (j != prev)
		{
			int mask2 = mask;
			mask2 = setBit1(mask2, j);
			ret += sol(i + 1, mask2, j) % Mod;
			ret %= Mod;
		}
	}
	return ret % Mod;
}
void solve()
{
	cin >> N >> M;
	clr(dp, -1);
	cout << sol(0, 0, 0) << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
