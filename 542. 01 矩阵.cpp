class Solution {
public:
    typedef pair<int, int> PII;
int mx[4] = { -1,1,0,0 };
int my[4] = { 0,0,1,-1 };
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();
	vector<vector<int>>dis(m, vector<int>(n,-1));
	queue<PII>q;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0)
			{
				dis[i][j] = 0;
				q.emplace(PII( i,j ));
			}
		}
	}
	while (!q.empty())
	{
		PII t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + mx[i];
			int y = t.second + my[i];
			if (x >= 0 && x < m && y >= 0 && y < n && dis[x][y] == -1)
			{
				dis[x][y] = dis[t.first][t.second] + 1;
				q.emplace(PII(x, y));
			}
		}
	}
	return dis;
}
};
