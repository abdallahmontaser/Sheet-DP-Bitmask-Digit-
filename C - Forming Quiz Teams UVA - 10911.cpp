#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int setBit1(int num, int idx) { return  num | (1 << idx); }
int getBit(int num, int idx) { return (num >> idx) & 1; }
int countBits1(int num) { int cnt = 0; while (num) { cnt++, num &= (num - 1); }return cnt; }
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
int N, vis[1 << 16], test = 1;
double dp[1 << 16];
vi X, Y;
double dis(int x1, int y1, int x2, int y2)
{
	return sqrt(pow((x1 - x2), 2) + pow(y1 - y2, 2));
}
double sol(int mask)
{
	if (countBits1(mask) == N)
		return 0;
	double& ret = dp[mask];
	if (vis[mask] == test)
		return ret;
	vis[mask] = test;
	ret = 1e18;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j && getBit(mask, i) == 0 && getBit(mask, j) == 0)
			{
				int mask2 = mask;
				mask2 = setBit1(mask2, i);
				mask2 = setBit1(mask2, j);
				ret = min(ret, dis(X[i], Y[i], X[j], Y[j]) + sol(mask2));
			}
		}
	}
	return ret;
}
void solve()
{
	string S;
	while (cin >> N && N)
	{
		N *= 2;
		X = Y = vi(N);
		for (int i = 0; i < N; i++)
			cin >> S >> X[i] >> Y[i];
		cout << "Case " << test++ << ": " << fixed << setprecision(2) << sol(0) << "\n";
	}
}
int main()
{
	solve();
}
