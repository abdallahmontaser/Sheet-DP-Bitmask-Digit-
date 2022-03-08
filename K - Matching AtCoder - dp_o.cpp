#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
int const Mod = 1e9 + 7;
int setBit0(int num, int idx) { return  num & ~(1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int N, dp[21][1 << 21];
vector<vi>ve;
int sol(int i, int mask)
{
	if (i == N)
		return 1;
	int& ret = dp[i][mask];
	if (~ret)
		return ret;
	ret = 0;
	for (int j = 0; j < N; j++)
	{
		if (ve[i][j] && getBit(mask, j))
		{
			int mask2 = mask;
			mask2 = setBit0(mask2, j);
			ret += sol(i + 1, mask2) % Mod;
			ret %= Mod;
		}
	}
	return ret % Mod;
}
void solve()
{
	cin >> N;
	ve = vector<vi>(N, vi(N));
	clr(dp, -1);
	for (auto& it : ve)
		for (auto& it2 : it)
			cin >> it2;
	cout << sol(0, (1 << N) - 1);
}
int main()
{
	solve();
}
