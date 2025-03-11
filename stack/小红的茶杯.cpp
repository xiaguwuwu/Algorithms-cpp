//本题为2023年5月10日华为暑期实习机考原题

//题目内容：有一个叫做小红的人，他非常喜欢喝茶。他有x个奇怪的杯子，每个杯子都可以装入一个正整数。小红决定将这些杯子中的个数字压入一个栈中，但他有些规矩：每次他要向栈中压入一个数字，如果栈顶数字与前一个数字相同，他就会将这两个数字取出来相加，并且将它们的和压入栈中。
//另外，如果栈顶数字等于前面连续的y个数字的和（1≤ y ≤x），他也会将这 y+1个数字取出来相加，并且将它们的和压入栈中。当然，如果以上两个规则都不满足，他就不会进行任何操作。现在，小红将一组正整数依次压入栈中，请你告诉他最终栈中剩下的数字是什么。

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;  // 最大栈大小

int main(){
    vector<long long> stk(maxn,0);// 用数组模拟栈
    int top = -1;// 栈顶指针

    int num;
    while(cin >> num){
        // cout <<"1num=" << num << endl;

        while(true){
            bool flag = false;
            long long temp = 0;
            for(int i = top;i >=0;i--){
                temp += stk[i];
                // cout <<"i=" << i << endl;
                // cout <<"1temp=" << temp << endl;
                // cout <<"2num=" << num << endl;
                if(temp == num){
                    // cout <<"2temp=" <<temp << endl;
                    num = num * 2;
                    top = i-1;
                    flag = true;
                    temp = 0;
                }else if (temp > num) {
                    break;
                }
            }
            if(!flag) break;
        }
        top++;
        stk[top] = num;
    }
    

    while(top >= 0){
        cout << stk[top] << " ";
        top--;
    }
    cout << endl;
}
