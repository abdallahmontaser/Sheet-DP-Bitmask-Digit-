#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int N, K, dp[12][1 << 12][100];
int sol(int i, int mask, int rem)
{
	if (i == N)
		return (!rem);
	int& ret = dp[i][mask][rem];
	if (~ret)
		return ret;
	ret = 0;
	for (int j = 1; j <= N; j++)
	{
		if (getBit(mask, j - 1) == 0)
		{
			int cnt = 0;
			for (int bit = j; bit < N; bit++)
				cnt += ((getBit(mask, bit) == 1) && (bit + 1 > j));
			if (cnt <= rem)
			{
				int mask2 = mask;
				mask2 = setBit1(mask2, j - 1);
				ret += sol(i + 1, mask2, rem - cnt);
			}
		}
	}
	return ret;
}
void solve()
{
	cin >> N >> K;
	clr(dp, -1);
	cout << sol(0, 0, K) << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
