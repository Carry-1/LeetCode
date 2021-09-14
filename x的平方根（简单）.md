**算法：二分查找，见注释**    
## <font color=green>AC</font>
```
class Solution {
public:
    int mySqrt(int x) {
        long low = 0, high = x, mid;
        while(low<=high) //二分查找
        {
            mid = (low+high)/2;
            if(mid*mid==x) return mid;  //注意这里mid的平方不能写成x^2,后者表示x异或2
            else if(mid*mid>x) high = mid -1;
            else low = mid + 1;
        }
        return high; //注意这里为什么返回的是high而不是low，可用x=10模拟一下输出


    }
};
```