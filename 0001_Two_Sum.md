### 0001 两数之和

> **题目：**
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
<br>**示例：**
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

#### （1）首先尝试暴力解法

两遍循环，时间复杂度O(n^2)。

```cpp
class Solution {
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
};
```

提交，耗时过长。

| 提交结果 | 执行用时 (pctl%) | 内存消耗 (pctl%) | 语言 |
|:---------|:-----------------|:-----------------|:-----|
| 通过     | 180 ms (42.56%)  | 11.5MB (5.02%)   | cpp  |

#### （2）查看题解，用 Hash Map 做

```cpp
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
```

提交，时间降到12 ms （83.35%）。

| 提交结果 | 执行用时 (pctl%) | 内存消耗 (pctl%) | 语言 |
|:---------|:-----------------|:-----------------|:-----|
| 通过     | 12 ms (83.35%)   | 12.3MB (5.02%)   | cpp  |

#### （3）收获

Map 的概念、定义、赋值和访问方法，及其迭代器的使用。
