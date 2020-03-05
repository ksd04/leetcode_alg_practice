### 0003 无重复字符的最长子串

#### （1）思路

滑动构造子串，使子串内字母唯一，取子串的最大长度。
第一次提交，出现错误，"tmmzuxt"，预期5，输出4。原因是子串左侧没有动态删除元素。
第二次提交，出现错误，"aabaab!bb"，预期3，输出2。原因是子串右侧没有动态增补。
第三次提交，成功。

#### （2）实现

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string s1;
        string::iterator it1, it2;
        int len, len_max;

        len = 0;
        it1 = s.begin();
        it2 = it1;

        if(it2 == s.end())
            return 0;

        it2++;
        len = 1;
        len_max = 1;
        s1 = s.substr(0, 1);

        while(it2 != s.end()){
            if(-1 == s1.find(*it2)){
                s1.push_back(*it2);
                len++;
                len_max = (len > len_max)? len :len_max;
            }
            else{
                s1.push_back(*it2);  //第二次提交忘加：不管有没有发现都要加进来，因为s1要滑动
                while(*it1++ != *it2)
                    s1.erase(0, 1);  //第一次提交忘加

                s1.erase(0, 1);  //第一次提交忘加
                len = it2 - it1 + 1;
            }

            it2++;
        }

        return len_max;
    }
};
```

| 提交结果 | 执行用时 (pctl%) | 内存消耗 (pctl%) | 语言 |
|:---------|:-----------------|:-----------------|:-----|
| 通过     | 24 ms (52.4%)   | 9.4 MB (63.06%)  | cpp  |

#### （3）收获

对动态构造（滑动）的序列，头尾的动态增删细节一定要细心。
