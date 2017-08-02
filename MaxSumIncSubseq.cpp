#include <iostream>
#include <vector>
using namespace std;

class MaxSumIncSubseq {
    vector<int> v;
    int ms = 0;

   public:
    MaxSumIncSubseq(vector<int> v) {
        this->v = v;
        calc();
    }

    void calc() {
        vector<int> t(v);  // store sum of max sum inc subseq ending at v[i]
        int n = t.size();
        t[0] = v[0];  // max sum will be same
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (v[i] > v[j] && v[i] + t[j] > t[i]) t[i] = v[i] + t[j];
            }
        }

        // find max sum
        ms = t[0];
        for (int i = 0; i < n; i++) {
            if (t[i] > ms) ms = t[i];
        }
 }

 int maxSum() { return ms; }
};


int main() {
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};
    MaxSumIncSubseq *ms = new MaxSumIncSubseq(arr);
    cout << ms->maxSum();
}
