class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_cost=*max_element(begin(costs),end(costs));
        vector<int> count(max_cost+1,0);
        for(int cost:costs){
            count[cost]++;
        }
        int ans=0;
        //now start from chepest and go further
        for(int price=0;price<=max_cost;price++){
            if(count[price]==0) continue;
            //how many bars can we buy
            int canBuy=min(count[price],coins/price);
            ans+=canBuy;
            coins-=price*canBuy;
            if(coins<price) break;
        }
        return ans;
    }
};