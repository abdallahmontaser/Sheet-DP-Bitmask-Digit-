#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int countBits1(int num) { int cnt = 0; while (num) { cnt++, num &= (num - 1); }return cnt; }
int const Mod = 1e9 + 7;
int N, M;
int dp[100][1 << 10][10];
int sol(int i, int mask, int prev)
{
	if (i == M)
		return (countBits1(mask) == N);
	int& ret = dp[i][mask][prev];
	if (~ret)
		return ret;
	ret = (countBits1(mask) == N);
	for (int j = prev - 1; j <= prev + 1; j++)
	{
		if (j != prev && j >= 0 && j < N)
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
	int ans = 0;
	for (int i = 1; i < N && M; i++)
	{
		int mask = 0;
		mask = setBit1(mask, i);
		ans += sol(1, mask, i) % Mod;
		ans %= Mod;
	}
	cout << ans << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
