#include <vector>

/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j, i1, j1;
        int len;
        vector<int> idxs;

        len = nums.size();
        for (i = 0; i < len; i++){
            for (j = i+1; j < len; j++){
                if (nums[j] == target - nums[i]){
                    i1 = i;
                    j1 = j;
                    i = len;
                    break;
                }
            }
        }

        idxs.push_back(i1);
        idxs.push_back(j1);

        return idxs;
    }
};*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int len;
        int res;
        std::map<int, int> mymap;
        std::map<int, int>::iterator it;
        vector<int> idxs;

        len = nums.size();
        mymap[nums[0]] = 0; 
        
        for (i = 1; i < len; i++){
            res = target - nums[i];
            it = mymap.find(res);
            
            if (it != mymap.end()){
                idxs.push_back(mymap[it->first]);
                idxs.push_back(i);
                mymap.clear();
                return idxs;
            }
            else
                mymap[nums[i]] = i;
        }

        return idxs;
    }
};