#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int countBits1(int num) { int cnt = 0; while (num) { cnt++, num &= (num - 1); }return cnt; }
int N, M, X, dp[100][1 << 15];
vi ve;
int sol(int i, int mask)
{
	if (i == M)
		return (countBits1(mask) != 0) * 1e5;
	int& ret = dp[i][mask];
	if (~ret)
		return ret;
	ret = sol(i + 1, mask);
	ret = min(ret, 1 + sol(i + 1, mask ^ ve[i]));
	return ret;
}
void solve()
{
	int T; cin >> T;
	for (int test = 1; test <= T; test++)
	{
		cin >> N >> M;
		ve = vi(M);
		clr(dp, -1);
		for (int i = 0; i < M; i++)
		{
			int mask = 0;
			for (int j = 0; j < N; j++)
			{
				cin >> X;
				if (X)
					mask = setBit1(mask, j);
			}
			ve[i] = mask;
		}
		int ans = sol(0, (1 << N) - 1);
		if (ans >= 1e5)
			cout << "Case " << test << ": " << "IMPOSSIBLE\n";
		else
			cout << "Case " << test << ": " << ans << "\n";
	}
}
int main()
{
	solve();
}
