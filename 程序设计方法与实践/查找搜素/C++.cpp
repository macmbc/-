#include <iostream>
#include <vector>
using namespace std;
#define ELementType char
struct Tree
{
    ELementType data;
    vector<Tree *> childNode;
    Tree *parentNode;
};

Tree *treePush(ELementType x, Tree *node)
{
    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp->data = x;
    temp->parentNode = node;
    node->childNode.push_back(temp);
    return temp;
}
int main(int argc, char const *argv[])
{    Tree *rootHead = (Tree *)malloc(sizeof(Tree));
    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp->data = 'c';
    Tree *temp2 = (Tree *)malloc(sizeof(Tree));
    temp2->data = 'd';
    Tree *temp3 = (Tree *)malloc(sizeof(Tree));
    temp3->data = 'e';
    rootHead->childNode.push_back(temp);
    rootHead->childNode.push_back(temp2);
    rootHead->childNode.push_back(temp3);
    for (auto i : rootHead->childNode)
    {
        cout << i->data << endl;
    }
    // Tree *rootHead = (Tree *)malloc(sizeof(Tree));
    // Tree *root = (Tree *)malloc(sizeof(Tree));
    // ELementType c;
    // Tree *cur = rootHead;
    // bool flag = false; //判断是否进入当前节点的子节点
    // while (true)
    // {
    //     c = getchar();
    //     if (isalpha(c))
    //     {
    //         if (flag)
    //             cur = treePush(c, cur);
    //     }
    //     else if (c == '(')
    //     {
    //         flag = true;
    //     }
    //     else if (c == ')')
    //     {
    //         cur = cur->parentNode;
    //         flag = false;
    //     }
    // }

    system("pause");
    return 0;
}
