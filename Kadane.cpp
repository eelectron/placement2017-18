#include <bits/stdc++.h>
using namespace std;

class Kadane{
public:
	vector<int> v;
	int s=0,e=0;
	int maxSubArraySum(vector<int> a){
		v = a;
		int curMax = a[0], maxSoFar = a[0];
		for(int i=1; i<a.size(); i++){
			if(a[i] > curMax + a[i]){
				s = i;
				e = i;
				curMax = a[i];
			}
			else{
				e = i;
				curMax = curMax + a[i];
			}

			if (curMax > maxSoFar)
			{
				maxSoFar = curMax;
			}
		}
		return maxSoFar;
	}

	void print(){
		for (int i = s; i <= e; ++i)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	vector<int> a = {-2,-3,4,-1,-2,1,5,-3};
	Kadane *k = new Kadane();
	cout<<k->maxSubArraySum(a)<<endl;
	k->print();
	return 0;
}