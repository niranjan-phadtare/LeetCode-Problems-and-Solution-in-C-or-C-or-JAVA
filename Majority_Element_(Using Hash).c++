class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_set <int> Unique;
        unordered_map <int,int> Freq;
        for(int num : nums){
            Unique.insert(num);
            Freq[num]++;
        }
        int MaxFreq = 0;
        int mostRepeating = -1;

        for(auto num : nums){
            if(Freq[num] > MaxFreq ){
                MaxFreq = Freq[num];
                mostRepeating = num;
            }
        }
        return mostRepeating;
    }
};
