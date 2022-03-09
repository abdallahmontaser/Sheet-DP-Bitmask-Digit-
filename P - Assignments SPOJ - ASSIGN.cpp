#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int N;
ll dp[20][1 << 20];
vector<vi>ve;
ll sol(int i, int mask)
{
	if (i == N)
		return 1;
	ll& ret = dp[i][mask];
	if (~ret)
		return ret;
	ret = 0;
	for (int j = 0; j < N; j++)
	{
		if (ve[i][j] && getBit(mask, j) == 0)
		{
			int mask2 = mask;
			mask2 = setBit1(mask2, j);
			ret += sol(i + 1, mask2);
		}
	}
	return ret;
}
void solve()
{
	cin >> N;
	ve = vector<vi>(N, vi(N));
	clr(dp, -1);
	for (auto& it : ve)
		for (auto& it2 : it)
			cin >> it2;
	cout << sol(0, 0) << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
