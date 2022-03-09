#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int countBits1(int num) { int cnt = 0; while (num) { cnt++, num &= (num - 1); }return cnt; }
int N, M, X, Y, K, dp[20][20][1 << 10];
vi x, y;
int sol(int i, int j, int mask)
{
	if (countBits1(mask) == K)
		return abs(i - X) + abs(j - Y);
	int& ret = dp[i][j][mask];
	if (~ret)
		return ret;
	ret = INT_MAX;
	for (int bit = 0; bit < K; bit++)
	{
		if (getBit(mask, bit) == 0)
		{
			int mask2 = mask;
			mask2 = setBit1(mask2, bit);
			ret = min(ret, abs(i - x[bit]) + abs(j - y[bit]) + sol(x[bit], y[bit], mask2));
		}
	}
	return ret;
}
void solve()
{
	cin >> N >> M >> X >> Y >> K;
	X--, Y--;
	x = y = vi(K);
	clr(dp, -1);
	for (int i = 0; i < K; i++)
		cin >> x[i] >> y[i], x[i]--, y[i]--;
	cout << "The shortest path has length " << sol(X, Y, 0) << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
