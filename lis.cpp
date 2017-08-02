#include <bits/stdc++.h>
using namespace std;
//Longest Increasing Subsequence
class LIS {
    vector<int> lis, info;  //info contains length of lis ending at i

   public:
    LIS(vector<int> v) {
        lis = v;
    }

    int len() {
        int max = 0;
        for (int i = 0; i < lis.size(); i++) info.push_back(1);

        for (int i = 1; i < lis.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (lis[i] > lis[j] && info[j] + 1 > info[i]) {
                    info[i] = info[j] + 1;
                    if (info[i] > info[max]) max = i;
                }
            }
        }
        return info[max];
    }

    void p() {
        for (int i = 0; i < info.size(); i++) {
            cout << info[i] << " ";
        }
    }
};

int main() {
    vector<int> v = {10, 22, 9, 33, 21, 50, 41};
    LIS *lisObj = new LIS(v);
    cout << lisObj->len() << endl;
    lisObj->p();
}
