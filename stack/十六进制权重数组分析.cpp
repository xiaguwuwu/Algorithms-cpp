//本题为2024年9月19日华为-秋招机考原题

//题目内容：设计一个程序来处理特定的数组分析问题。
//给定一个非负整数数组arr，其中每个整数用其十六进制表示中的数字之和来表示其“权重”(权重计算是基于十六进制表示中每位数字的和，0 ~ 9代表权重0~ 9，权重A:10、B:11、C:12、D:13、E:14、F:15)。
//您的任务是找出数组中每个元素右侧第一个具有更大“权重”的元素，并返回一个新的数组，该数组包含这些元素的索引。
//如果一个元素的右侧没有更大“权重”的元素，则对应位置返回-1。


//每个元素右侧第一个具有更大“权重”的元素：单调栈问题（一群牛比身高，每个能看见几头牛）
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int compute_weight(int n){
    if(n == 0) return 0;
    int s= 0;
    while(n > 0){
        int digit = n & 0xF;
        s += digit;
        n >>= 4;
    }
    return s;
}

int main(){
    int num;
    cin >> num;

    vector<int> arr(num);
    for(int i = 0;i<num;i++){
        cin >> arr[i];
    }

    vector<int> weight(num);
    for(int i = 0;i<num;i++){
        weight[i] = compute_weight(arr[i]);
    }

    vector<int> answer(num);
    stack<int> stk;
    for(int i = num-1;i >= 0;i--){
        while(!stk.empty() && weight[stk.top()] <= weight[i]){
            stk.pop();
        } 
        if(!stk.empty()){
            answer[i] = stk.top();
        }else{
            answer[i] = -1;
        }
        stk.push(i);
    }
    
    for(int i = 0;i < num; i++){
        cout << answer[i];
        if (i < num - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}

