//本题为2024年10月26日中国电信机考原题

//题目内容：
//给定一个整数序列a，以及2个整数x, k。
//求出有多少区间[L, R]，使得该区间中恰好有k个ai满足aii能被x整除

//逆天困难题
//滑动窗口求解最大/最多子序列的数量

//最多有 k 个 1的子数组包含了最多有 k-1 个 1的子数组和恰好有 k 个 1的子数组。
//所以，当我们从最多 k 个 1的子数组数量中减去最多 k-1 个 1的子数组数量时，剩下的就是恰好有 k 个 1的子数组数量。

#include <bits/stdc++.h>
using namespace std;

// 统计二进制数组中至多有 k 个 1 的子数组数量
long long countAtMostK(const vector<int>& b, int k) {
    int left = 0;
    long long result = 0;
    int count = 0;
    for(int right = 0; right < b.size(); ++right){
        if(b[right] == 1){
            count++;
        }
        while(count > k){
            if(b[left] == 1){
                count--;
            }
            left++;
        }
        result += (right - left + 1);
    }
    return result;
}

int main(){
    // 读取第一行，整数序列 a
    string line;
    getline(cin, line);
    vector<int> a;
    int num;
    stringstream ss(line);
    while(ss >> num){
        a.push_back(num);
    }
    
    // 读取第二行，x 和 k
    int x, k;
    cin >> x >> k;
    
    // 将 a 映射为二进制数组 b，1 表示能被 x 整除，0 否则
    vector<int> b(a.size(), 0);
    for(int i = 0; i < a.size(); ++i){
        if(a[i] % x == 0){
            b[i] = 1;
        }
    }
    
    // 计算答案
    long long total = countAtMostK(b, k);
    if(k > 0){
        total -= countAtMostK(b, k-1);
    }
    cout << total;
    return 0;
}
