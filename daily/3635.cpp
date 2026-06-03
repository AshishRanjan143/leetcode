//optimal
class Solution {
public:
int findFinishtime(vector<int> &starttime1,vector<int>& startduration1,vector<int>& starttime2,vector<int> &startduration2){
    int finish1=INT_MAX;
    for(int i=0;i<starttime1.size();i++){
        finish1=min(finish1,(starttime1[i]+startduration1[i]));
    }
    int finish2=INT_MAX;
    for(int i=0;i<starttime2.size();i++){
        finish2=min(finish2,max(finish1,starttime2[i])+startduration2[i]);

    }
    return finish2;
}
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_then_water=findFinishtime(landStartTime,landDuration,waterStartTime,waterDuration);
        int water_then_land=findFinishtime(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(land_then_water,water_then_land);
        
    }
};
//brute force
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //land-> water
                int landf=landStartTime[i]+landDuration[i];
                int waterStart=max(landf,waterStartTime[j]);
                ans=min(ans,waterStart+waterDuration[j]);
                //water->land
                int waterf=waterStartTime[j]+waterDuration[j];
                int landStart=max(waterf,landStartTime[i]);
                ans=min(ans,landStart+landDuration[i]);
            }
        }
        return ans;
        
    }
};