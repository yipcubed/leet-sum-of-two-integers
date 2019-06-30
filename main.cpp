#include <cstring>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>


using namespace std;

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

// with help from https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
class Solution {
public:
    // 0010 = 2
    // 1010 = 10
    // x = 1010, y = 0010
    // carry = x & y = 0010
    // x = x ^ y = 1000
    // y = carry << 1 = 0100
    // carry = x & y = 1100
    // x = x ^ y = 0000
    int getSum(int a, int b) {
      unsigned int x = a;
      unsigned int y = b;
      while (y != 0)  {

        // if bit-i is set in x and y then carry != 0
        unsigned int carry = x & y;  

        // if bit-i is 0 and 1, get 1
        // if bit-i is 0 and 0, get 0
        // if bit-i is 1 and 1, get 0 -- this bit generated the carry
        x = x ^ y;  

        // move carry left from bit-i
        // if carry was generated from i=2, now bit at i=4 is set
        y = carry << 1;  
      }
      return x;
    }
};

void test1() {
  Solution S;
  cout << "3? " << S.getSum(1, 2) << endl;
  cout << "12? " << S.getSum(10, 2) << endl;
  cout << "-8? " << S.getSum(-10, 2) << endl;
  cout << "8? " << S.getSum(10, -2) << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}

