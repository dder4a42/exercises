//完全二叉树的中序遍历
#include<iostream>

// int tree[100005];
int tree[105];

void travel_complete_bin();
void travel_mid(int size);

int main() {
    int level, size, i;
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    std::cin >> level;
    size = (1 << level) -1;
    for(i=0;i < size; ++i) {
        std::cin >> tree[i];
    }
    travel_mid(size);
    return 0;
}

void travel_complete_bin()
{
    int level, size, i;
    //std::ios::sync_with_stdio(0);
    //std::cin.tie(0);
    //std::cout.tie(0);
    std::cin >> level;
    if(level == 0) return;
    if(level == 1) {
        int temp;
        std::cin >> temp;
        std::cout << temp;
        return;
    }

    size = (1 << level) -1;
    for(i=0;i < size; ++i) {
        std::cin >> tree[i];
    }

    i=0;
    while (true)
    {
        //优先进左子树
        if(2*i+1 < size && tree[2*i+1] > 0) {
            i = 2*i+1; 
        }
        else {
            if(tree[i] > 0) {
                std::cout << tree[i] << ' ';
                tree[i] = -1;
            }
            if(2*i+2 < size && tree[2*i+2] > 0) {
                i = 2*i+2;
            }
            else if(i < 0 || i > size) {
                break;
            }
            else if(i % 2 == 1) {
                i = (i-1) / 2;
            }
            else if(i % 2 == 0) {
                i = (i-2) / 2;
            }
            else {
                break;
            }
        }
    }
}

void travel_mid(int size)
{
    int i=0;
    while (true) {
        //先走完左子通路
        while(2*i+1 < size && tree[2*i+1] > 0) {
            i = 2*i+1; 
        }
        std::cout << tree[i] << ' ';
        //有右子树就访问右子树
        if (2 * i + 2 < size && tree[2 * i + 2] > 0) {
            i = 2 * i + 2;
        }
        else {
            //右子树为空，分两种回溯，一种是从左子回溯到根，一种是从右子回溯到父节点的父节点
            while(true) {
                //沿左子回路回溯，直到存在右子树
                while(tree[2 * i + 2] < 0 && i % 2 == 1) {
                    i = (i-1) / 2;
                    std::cout << tree[i] << ' ';
                }
                if(tree[2 * i + 2] > 0) {
                    //进入右子树，进行下一轮中序遍历
                    i = 2 * i + 2;
                    break;
                }
                else {
                    //沿右子回路回溯，直到某个左子，即回到左子路径
                    while (i % 2 == 0) {
                        i = (i-2) / 2;
                    }
                    //在访问右子前，对应左子根节点已访问，再回溯其父节点
                    i = (i-1) / 2;
                    //回溯至根节点，遍历完毕
                    if(i <= 0) {
                        return;
                    }
                    else {
                        std::cout << tree[i] << ' ';
                    }
                }
            }
        }
    }
}
