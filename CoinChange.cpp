#include <bits/stdc++.h>
using namespace std;

class CoinChange {
    vector<int> coins;
    int amount;
public:
 CoinChange(int amount, vector<int> coins) {
     this->amount = amount;
     this->coins = coins;
 }

 int count() {
     vector<int> t(amount + 1, 0);
     t[0] = 1;  //0 amount can be made in 1 way
     for (int i=0; i<coins.size(); i++) {
         for (int j = coins[i]; j < t.size(); j++) {
             t[j] += t[j - coins[i]];
         }
     }
     return t[t.size() - 1];
 }
};

int main() {
    vector<int> coins = {2, 3, 5, 6};
    int amount = 0;
    cin >> amount;
    CoinChange *cc = new CoinChange(amount, coins);
    cout << cc->count() << endl;
}
