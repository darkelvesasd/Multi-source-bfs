class Solution {
public:
    typedef pair<int, int>PII;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int numEnclaves(vector<vector<int>>& grid) {
	queue<PII>q;
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>>vb(m,vector<bool>(n));
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		if (grid[i][n - 1] == 1 && vb[i][n - 1] == false)
		{
			q.emplace(PII(i,n-1));
			vb[i][n - 1] = true;
		}
		if (grid[i][0] == 1 && vb[i][0] == false)
		{
			q.emplace(PII(i, 0));
			vb[i][0] = true;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (grid[m - 1][i] == 1 && vb[m - 1][i] == false)
		{
			q.emplace(PII(m-1,i));
			vb[m - 1][i] = true;
		}
		if (grid[0][i] == 1 && vb[0][i] == false)
		{
			q.emplace(PII(0, i));
			vb[0][i] = true;
		}
	}
	while (!q.empty())
	{
		PII t = q.front();
		q.pop();
		for (int i=0;i<4;i++)
		{
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && vb[x][y] == false)
			{
				vb[x][y] = true;
				q.emplace(PII(x,y));
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j=0;j<n;j++)
		{
			if (grid[i][j] == 1 && vb[i][j] == false)
			{
				count++;
			}
		}
	}
	return count;
}
};
