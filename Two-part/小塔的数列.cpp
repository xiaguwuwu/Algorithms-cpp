//题目描述：
//给定一个长度为n的整数数组A和一个整数C，需要计算所有满足条件A[i]-A[j]=C的数对(i,j)的个数，其中i和j为数组中不同的位置索引。需要注意的是，如果数组中存在重复的元素，即使数值相同但位置不同，也应视为不同的数对。

//涉及到寻找某个数的前驱和后继时，想到：
//lower_bound 查找的是第一个不小于目标值的位置。
//upper_bound 查找的是第一个大于目标值的位置。
//二分法只能适用于单调的数列。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int num;
    cin >> num;
    long long sum = 0;
    for(int i = 0;i < n;i++){
        int temp =  A[i] + num;
        sum += upper_bound(A.begin(),A.end(),temp) - lower_bound(A.begin(),A.end(),temp);
    }
    cout << sum << endl;
    
    return 0;
}
