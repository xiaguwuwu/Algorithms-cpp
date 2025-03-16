//本题为2024年8月28日得物机考原题

//题目描述：
//小红和小堡正在玩一个游戏，每一关都有一个分数。如果某人某一关分数比上一关高，但另一个人这一关分数比上一关低，那么他就可以嘲笑对方。如果两个人这一关游戏的分数都比上一关多，则增量更多的可以嘲笑对方;如果两个人这一关游戏的分数都比上一关少，则减量更少的可以嘲笑对方。只有当他们的增量相同或者减量相同时，才不会互相嘲笑。
//例如，假设小红第一关的分数为2，第二关的分数为8;小堡第一关的分数为5，第二关的分数为10，显然小堡增加的比小红多，那么小堡就可以嘲笑小红。
//现在给定了小红和小堡每一关的分数，你可以选择一段连续的关卡，使得一段关卡中两个人都不会互相嘲笑，问最多可以选择多少个关卡。特别的一段连续关卡中的第一关两人不会互相嘲笑。

//我没用差分数组
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    int temp = 1, max = 1;
    for(int i = 1; i < n; i++){
        int a_temp = a[i] - a[i-1];
        int b_temp = b[i] - b[i-1];

        if(a_temp == b_temp){
            temp += 1;
            max = (temp > max) ? temp : max;
        }else{
            temp = 1;
        }
    }
    cout << max << endl;

    return 0;
}
