#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int countBits1(int num) { int cnt = 0; while (num) { cnt++, num &= (num - 1); }return cnt; }
int N, dp[1 << 16], save[1 << 16], adj[16], test = 1, K, X;
int sol(int mask)
{
	int& ret = dp[mask];
	if (~ret)
		return ret;
	ret = 0;
	for (int mask2 = mask; mask2 != 0; mask2 = (mask2 - 1) & mask)
	{
		if (save[mask2])
			ret = max(ret, 1 + sol(mask ^ mask2));
	}
	return ret;
}
void pre()
{
	for (int mask = 1; mask < (1 << N); mask++)
	{
		int tem_mask = 0;
		for (int bit = 0; bit < N; bit++)
		{
			if (getBit(mask, bit) == 1)
					tem_mask |= adj[bit];
		}
		if (countBits1(tem_mask) == N)
			save[mask] = 1;
	}
}
void solve()
{
	while (cin >> N && N)
	{
		clr(dp, -1);
		clr(save, 0);
		clr(adj, 0);
		for (int i = 0; i < N; i++)
		{
			cin >> K;
			adj[i] = setBit1(adj[i], i);
			while (K--)
			{
				cin >> X;
				adj[i] = setBit1(adj[i], X);
			}
		}
		pre();
		cout << "Case " << test++ << ": " << sol((1 << N) - 1) << "\n";
	}
}
int main()
{
	solve();
}
