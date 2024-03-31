//2160 由前序遍历确定拓展二叉树的深度
#include<iostream>

int Stack[105]; //100005

int main() {
    using namespace std;
    int result = 0;
    int height = 0;
    int node = 0;
    int i = 0;
    while (true)
    {
        if(cin.peek() == '\n' || cin.peek() == '\r') break;
        cin >> node;
        Stack[i++] = node;
        if(node != -1) height++;
        result = (result < height) ? height : result;
        while(i > 2 && Stack[i-1] == -1 && Stack[i-2] == -1) {
            i -= 2;
            Stack[i-1] = -1;
            height--;
        }
        if(height <= 0) break;
    }
    cout << result << endl;
    return 0;
}
