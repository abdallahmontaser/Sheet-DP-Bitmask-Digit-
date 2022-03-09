#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define clr(x,val)           memset((x),(val),sizeof(x))
int getBit(int num, int idx) { return (num >> idx) & 1; }
int N;
ll dp[1 << 16], ans[1 << 16];
vector<vl>ve;
void Build()
{
	for (int it = 1; it < (1 << N); it++)
	{
		ll sum = 0;
		for (int bit1 = 0; bit1 < N; bit1++)
		{
			if (getBit(it, bit1) == 1)
			{
				for (int bit2 = bit1 + 1; bit2 < N; bit2++)
				{
					if (getBit(it, bit2) == 1)
						sum += ve[bit1][bit2];
				}
			}
		}
		ans[it] = sum;
	}
}
ll sol(int mask)
{
	ll& ret = dp[mask];
	if (~ret)
		return ret;
	ret = 0;
	for (int mask2 = mask; mask2 != 0; mask2 = (mask2 - 1) & mask)
		ret = max(ret, ans[mask2] + sol(mask2 ^ mask));
	return ret;
}
void solve()
{
	cin >> N;
	ve = vector<vl>(N, vl(N));
	clr(dp, -1);
	for (auto& it : ve)
		for (auto& it2 : it)
			cin >> it2;
	Build();
	cout << sol((1 << N) - 1);
}
int main()
{
	solve();
}
