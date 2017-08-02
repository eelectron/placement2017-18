#include <bits/stdc++.h>
using namespace std;

class MCP{
	vector<vector<int>> cost;
	vector<vector<int>> tc;
public:
	MCP(vector<vector<int>> v){
		cost = v;
		minCost();
	}

	int minCost(){	//m,n are index
		int R = cost.size();
		int C = cost[0].size();

		vector<vector<int>> t(R, vector<int>(C));
		t[0][0] = cost[0][0];

		//update cost of first col
		for(int i=1; i<R; i++)
			t[i][0] = cost[i][0] + t[i-1][0];

		//update cost of first col
		for(int j=1; j<C; j++)
			t[0][j] = cost[0][j] + t[0][j-1];

		for(int i=1; i<R; i++){
			for(int j=1; j<C; j++){
				t[i][j] = cost[i][j] + min(t[i-1][j-1], min(t[i-1][j], t[i][j-1]));	
			}
		}

		tc = t;
	}

	int minCost(int m, int n){
		return tc[m][n];
	}
};

int main(){
	vector<vector<int>> cost = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };

    MCP *mcp = new MCP(cost);
    cout<<mcp->minCost(2,2)<<endl;
}