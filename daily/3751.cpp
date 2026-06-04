class Solution {
public:
int isWaive(int num){
    int res=0;
    vector<int> digit;
    while(num>0){
        digit.push_back(num%10);
        num/=10;
    }
    for(int j=1;j<digit.size()-1;j++){
        if(digit[j]>digit[j-1] && digit[j]>digit[j+1]){
            res++;
        }else if(digit[j]<digit[j-1] && digit[j]<digit[j+1]){
            res++;
        }else{
            continue;
        }
    }
    return res;
}
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
           int res=isWaive(i);
           ans+=res;
        }
        return ans;
    }
};