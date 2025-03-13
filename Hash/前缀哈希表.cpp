//题目描述：给定n个数组a1，……，an，找出所有所有的严格递增三元组（1<=i<j<k<=n)，使得ai=ak=aj+1，输出其数量。

//#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;

    unordered_map<int, int> count_left;
    unordered_map<int, int> count_right;

    vector<int> nums(n);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }

    for(int i = 0;i < n;i++){
        count_right[nums[i]]++;
    }

    int count=0;
    for(int i = 0;i < n;i++){
        count += count_left[nums[i]+1] * count_right[nums[i]+1];
        count_left[nums[i]]++;
        count_right[nums[i]]--;
    }
    cout << count << endl;

    return 0;

}
