## 实现strStr()
**算法1：暴力匹配**&emsp;&emsp;（测试用例的执行结果都是正确的，但是一提交就会显示**执行时间超过**。）    
对主串和模式串进行遍历，遍历算法如下答案所示：   
**我的答案1**
```
class Solution {
public:
    int strStr(string haystack, string needle) { //暴力匹配，结果正确，但提交会显示超过运行时间
            if(needle=="") //若模式串为空，返回0，因为空串与主串从主串位置0处开始就匹配
                return 0;
            for(int i=0; i<haystack.size(); i++) //遍历主串
            {
                int j =0;   //从模式串位置0处开始匹配
                for(j=0; j<needle.size(); j++) //遍历模式串
                    if(haystack[i]==needle[j]) //若主串位置i处的字符与模式串位置j处的字符相匹配
                        { //那么开始主串i+1处字符和模式串j+1处字符的匹配
                            i++;
                            continue;
                        }
                    else //若主串i处的字符与模式串j处的字符不匹配
                    {
                        i-=j;  //主串要回退到位置i-j+1处重新开始与模式串位置j=0处字符做匹配
                        break;
                    }
                if(j==needle.size())  //若模式串遍历结束，说明在主串中可以找到与模式串相等的子串
                    return i-j;
            }
            return -1; //若模式串还未遍历结束时主串就已遍历结束，说明主串中找不到与模式串相等的子串
    }
};
```