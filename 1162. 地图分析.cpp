class Solution {
public:
   typedef pair<int, int>PII;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int maxDistance(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	int count = -1;
	vector<vector<bool>>vb(m, vector<bool>(n));
	queue<PII>q;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1)
			{
				vb[i][j] = true;
				q.emplace(PII(i, j));
				grid[i][j] = 0;
			}
		}
	}
	while (!q.empty())
	{
		int sz = q.size();
		for (int k = 0; k < sz; k++)
		{
			PII t = q.front();
			q.pop();
			int tv = grid[t.first][t.second];
			for (int i = 0; i < 4; i++)
			{
				int x = dx[i] + t.first;
				int y = dy[i] + t.second;
				if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && vb[x][y] == false)
				{
					grid[x][y] = tv + 1;
					q.emplace(PII(x, y));
				}
			}
		}
		count++;
	}
	if (count == -1 || count==0)
	{
		return -1;
	}
	return count;
}
};
