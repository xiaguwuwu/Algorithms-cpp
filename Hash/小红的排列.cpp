//本题为2024年9月1日字节跳动-秋招机考原题

//题目内容：小红有一个长度为n的排列p，他想知道p中有多少个i,j对满足:i<j且pi+pj=i+j。

//分析：从左往右枚举每一个数时，维护一个前缀哈希表H

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int num;
    cin >> num;


    unordered_map<int, int> hash_map;

    int count = 0;

    for(int i = 0;i< num;i++){
        int temp;
        cin >> temp;
        int m = temp - i - 1;
        int n = -m;
        if(hash_map.find(n) != hash_map.end()){
            count += hash_map[n];
        }
        hash_map[m]++;
    }
    cout << count << endl;
    
    return 0;
}

