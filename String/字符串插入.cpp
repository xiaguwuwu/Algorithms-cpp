//题目描述：  
//给定两个字符串A和B，请判断是否可以在字符串A的某个位置插入一个字符串B，使得插入后的新字符串成为一个回文串。回文串是指正读和反读都相同的字符串。

#include <iostream>
#include <string>

using namespace std;

int main(){
    string a,b;
    cin >> a >> b;

    int a_length = a.length();
    for(int i =0;i<a.length();i++){
        string temp;
        temp = a.substr(0,i)+ b + a.substr(i);

        //双指针的引用，辅助一个从头，一个从尾遍历字符串
        int n = 0,m = temp.length()-1;
        while(n <= m){
            if(temp[n] != temp[m]){
                break;
            }
            n++;
            m--;
        }
        if(n >= m){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
