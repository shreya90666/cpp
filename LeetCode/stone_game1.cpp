#include <bits/stdc++.h>
using namespace std;
class Solution
{
 public:
    int solve(vector<int>&piles , int a , int b ,unordered_map<int,int>&memo) 
    {
        if(a==b)
        {
          return piles[a];
        }

        int key = a*1000+b;
        if(memo.find(key) != memo.end())
        {
            return memo[key];
        }
        int take_First = piles[a] - solve(piles,a+1,b,memo);
        int take_Last = piles[b] - solve(piles,a,b-1,memo);
        int result = max(take_First,take_Last);
        memo[key]=result;
        return result;
    } 
    bool stoneGame(vector<int>& piles)
    { 
        int n = piles.size();
        unordered_map<int,int>memo;
        return solve(piles,0,n-1,memo)>0;
    }
};
int main()
{
    Solution s;
    vector<int> piles = {5, 3, 4, 5};
    
    bool result = s.stoneGame(piles);
    
    cout << (result ? "Alex wins" : "Alex does not win") << endl;
    
    return 0;
}