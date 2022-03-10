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
int N, M, dp[1 << 14][7][7];
vi Left, Right;
int sol(int mask, int L, int R)
{
	if (countBits1(mask) == N)
		return (L == R);
	int& ret = dp[mask][L][R];
	if (~ret)
		return ret;
	ret = 0;
	for (int i = 0; i < M; i++)
	{
		if (getBit(mask, i) == 0)
		{
			int mask2 = mask;
			mask2 = setBit1(mask2, i);
			if (Left[i] == L)
				ret |= sol(mask2, Right[i], R);
			else if (Right[i] == L)
				ret |= sol(mask2, Left[i], R);
			if (Right[i] == R)
				ret |= sol(mask2, L, Left[i]);
			else if (Left[i] == R)
				ret |= sol(mask2, L, Right[i]);
		}
	}
	return ret;
}
void solve()
{
	while (cin >> N && N)
	{
		cin >> M;
		Left = Right = vi(M);
		clr(dp, -1);
		int L1, R1, L2, R2;
		cin >> L1 >> R1 >> L2 >> R2;
		for (int i = 0; i < M; i++)
			cin >> Left[i] >> Right[i];
		if (sol(0, R1, L2))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
int main()
{
	solve();
}
