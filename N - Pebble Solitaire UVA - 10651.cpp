#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int setBit0(int num, int idx) { return  num & ~(1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int dp[1 << 12];
int sol(int mask)
{
	int& ret = dp[mask];
	if (~ret)
		return ret;
	ret = 0;
	for (int i = 0; i < 12; i++)
		ret += getBit(mask, i);
	for (int i = 0; i < 11; i++)
	{
		if (getBit(mask, i) == 1 && getBit(mask, i + 1) == 1)
		{
			if (i - 1 >= 0 && getBit(mask, i - 1) == 0)
			{
				int mask2 = mask;
				mask2 = setBit1(mask2, i - 1);
				mask2 = setBit0(mask2, i);
				mask2 = setBit0(mask2, i + 1);
				ret = min(ret, sol(mask2));
			}
			if (i + 2 < 12 && getBit(mask, i + 2) == 0)
			{
				int mask2 = mask;
				mask2 = setBit1(mask2, i + 2);
				mask2 = setBit0(mask2, i);
				mask2 = setBit0(mask2, i + 1);
				ret = min(ret, sol(mask2));
			}
		}
	}
	return ret;
}
void solve()
{
	string S; cin >> S;
	clr(dp, -1);
	int mask = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == 'o')
			mask = setBit1(mask, i);
	}
	cout << sol(mask) << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
