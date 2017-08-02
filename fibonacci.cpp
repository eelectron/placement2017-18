#include <bits/stdc++.h>
using namespace std;

class Fibonacci
{	
	vector< vector<int> > F = {{1,1},{1,0}};
	vector< vector<int> > M = {{1,1},{1,0}};
	
	public:
		void multiply(vector< vector<int> > &F, vector< vector<int> > &M)
		{
		  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
		  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
		  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
		  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
		 
		  F[0][0] = x;
		  F[0][1] = y;
		  F[1][0] = z;
		  F[1][1] = w;
		}

		int fib(int n){
			if (n == 0)
				return 0;

			int x = n-1;
			int c = log2(x);
			int i=0;
			while(i<c){
				multiply(F, F);
				i++;	
			}

			for(i=0; i<n-(pow(2,c)+1); i++){
				multiply(F, M);
			}
			cout<<i<<endl;
			return F[0][0];
		}
	
};

int main()
{
	int n;
	cin>>n;
	Fibonacci *f = new Fibonacci();
	cout<<f->fib(n)<<endl;
	return 0;
}