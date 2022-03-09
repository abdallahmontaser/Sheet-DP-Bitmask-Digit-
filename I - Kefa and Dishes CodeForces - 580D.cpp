#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int countBits1(int num) { int cnt = 0; while (num) { cnt++, num &= (num - 1); }return cnt; }
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
int N, M, K, u, v, c;
ll dp[1 << 18][20];
vl ve;
vector<vl>best;
ll sol(int mask, int prev)
{
	if (countBits1(mask) == M)
		return 0;
	ll& ret = dp[mask][prev];
	if (~ret)
		return ret;
	ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (getBit(mask, i) == 0)
		{
			int mask2 = mask;
			mask2 = setBit1(mask2, i);
			ret = max(ret, (ve[i] + best[prev][i + 1]) + sol(mask2, i + 1));
		}
	}
	return ret;
}
void solve()
{
	cin >> N >> M >> K;
	ve = vl(N);
	best = vector<vl>(N + 1, vl(N + 1, 0));
	clr(dp, -1);
	for (auto& it : ve)
		cin >> it;
	for (int i = 0; i < K; i++)
		cin >> u >> v >> c, best[u][v] = c;
	cout << sol(0, 0);
}
int main()
{
	solve();
}
