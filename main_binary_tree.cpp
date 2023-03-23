#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;

template<typename T>
struct BinaryTreeNode {
    T value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T value, BinaryTreeNode* left = nullptr, BinaryTreeNode* right = nullptr)
        : value(value), left(left), right(right) {};
};

template<typename T>
using BTreeNode = BinaryTreeNode<T>;

/**
 * 深度优先遍历分为 中序遍历，前序遍历， 后序遍历
 * 中序遍历：左中右
 * 前序遍历：中左右
 * 后序遍历：左右中
 *
 */

//前序遍历的递归写法
void printByFrontOrder(const BTreeNode<int>* rootNode)
{
    cout << rootNode->value << " ";
    if (rootNode->left) {
        printByFrontOrder(rootNode->left);
    }
    if (rootNode->right) {
        printByFrontOrder(rootNode->right);
    }
}

//中序遍历的递归写法
void printByMiddleOrder(BTreeNode<int>* rootNode)
{
    if (rootNode->left) {
        printByMiddleOrder(rootNode->left);
    }
    cout << rootNode->value << " ";
    if (rootNode->right) {
        printByMiddleOrder(rootNode->right);
    }
}

//后序遍历的递归写法
void printByBehindOrder(BTreeNode<int>* rootNode)
{
    if (rootNode->left) {
        printByBehindOrder(rootNode->left);
    }
    if (rootNode->right) {
        printByBehindOrder(rootNode->right);
    }
    cout << rootNode->value << " ";
}

//当递归层数太多，会导致栈溢出错误，下面使用迭代法实现前序遍历
void printByFrontInStack(const BTreeNode<int>* rootNode)
{
    stack<const BTreeNode<int>*> nodeStack;
    nodeStack.push(rootNode);
    while (!nodeStack.empty()) {
        auto topNode = nodeStack.top();
        cout << topNode->value << " ";
        nodeStack.pop();
        if (topNode->right) {
            nodeStack.push(topNode->right);
        };
        if (topNode->left) {
            nodeStack.push(topNode->left);
        }
    }
    cout << endl;
}

/**
 * 后序遍历 由前序遍历 中左右 -->  中右左 颠倒一下 -->左右中 得到
 */
void printByBehindInStack(const BTreeNode<int>* rootNode)
{
    vector<const BTreeNode<int>*> nodeVector;
    stack<const BTreeNode<int>*> nodeStack;
    nodeStack.push(rootNode);
    while (!nodeStack.empty()) {
        auto topNode = nodeStack.top();
        // cout << topNode->value << " ";
        nodeVector.push_back(topNode);
        nodeStack.pop();
        if (topNode->left) {
            nodeStack.push(topNode->left);
        }
        if (topNode->right) {
            nodeStack.push(topNode->right);
        };
    }
    reverse(nodeVector.begin(), nodeVector.end());
    for (auto node : nodeVector) {
        cout << node->value << " ";
    }
    cout << endl;
}

//层序遍历二叉树
void printByLevelOrder(const BTreeNode<int>* rootNode)
{
    queue<const BTreeNode<int>*> nodeQueue;

    nodeQueue.push(rootNode);
    while (!nodeQueue.empty()) {
        int size = nodeQueue.size();
        for (int i = 0; i < size; i++) {
            auto headNode = nodeQueue.front();
            cout << headNode->value << " ";
            nodeQueue.pop();
            if (headNode->left) {
                nodeQueue.push(headNode->left);
            }
            if (headNode->right) {
                nodeQueue.push(headNode->right);
            }
        }
    }
    cout << endl;
}

/**
 * 使用栈来迭代实现二叉树的中序遍历思路：
 * 用栈来记录遍历的路径
 * 用一个指针来标记当前正在处理的节点
 * 如果当前不为空，将当前节点入栈，当前指向左子节点，开始下一轮while
 * 如果当前为空，则弹出栈顶节点，处理该节点(这里只是输出)，当前指向刚弹出的节点的右子节点， 开始下一轮while
 */
void printByMiddleInStack(const BTreeNode<int>* rootNode)
{
    stack<const BTreeNode<int>*> nodeStack;
    const BTreeNode<int>* curNode = rootNode;
    while (curNode != nullptr || !nodeStack.empty()) {
        if (curNode != nullptr) {
            nodeStack.push(curNode);
            curNode = curNode->left;
        } else {
            curNode = nodeStack.top();
            nodeStack.pop();
            cout << curNode->value << " ";
            curNode = curNode->right;
        }
    }
    cout << endl;
}

//通用的迭代遍历二叉树写法

vector<const BTreeNode<int>*> middleOrder(const BTreeNode<int>* rootNode)
{
    vector<const BTreeNode<int>*> result;
    stack<const BTreeNode<int>*> nodeStack;
    if (rootNode != nullptr) {
        nodeStack.push(rootNode);
    }
    while (!nodeStack.empty()) {
        const BTreeNode<int>* topNode = nodeStack.top();
        if (topNode != nullptr) {
            nodeStack.pop();
            if (topNode->right) {
                nodeStack.push(topNode->right);
            }
            nodeStack.push(topNode);
            nodeStack.push(nullptr);
            if (topNode->left) {
                nodeStack.push(topNode->left);
            }
        } else {
            nodeStack.pop();
            topNode = nodeStack.top();
            nodeStack.pop();
            result.push_back(topNode);
        }
    }
    return result;
}

/**
 * 假设一颗二叉树结构如下
 *              6
 *      3               8
 *  2       5       7       9
 *
 */
int main()
{
    cout << "main start" << endl;
    array<int, 7> nodeArray = { 6, 3, 8, 2, 5, 7, 9 };
    //将数组类型的二叉树转换成链表类型的二叉树
    BTreeNode<int>* rootNode = new BTreeNode<int>(nodeArray[0]);
    vector<BTreeNode<int>*> cacheNodeVector;
    cacheNodeVector.push_back(rootNode);
    int nodeArraySize = nodeArray.size();
    for (int i = 1; i < nodeArraySize; i++) {
        auto node = new BTreeNode<int>(nodeArray[i]);
        if (i % 2 == 0) {
            auto parent = cacheNodeVector[(i / 2) - 1];
            parent->right = node;
        } else {
            auto parent = cacheNodeVector[i / 2];
            parent->left = node;
        }
        cacheNodeVector.push_back(node);
    }
    cout << "init tree end" << endl;
    for (auto node : cacheNodeVector) {
        cout << node->value << " ";
        if (node->left) {
            cout << "left: " << node->left->value << " ";
        }
        if (node->right) {
            cout << "right: " << node->right->value;
        }
        cout << endl;
    }
    cacheNodeVector.clear();
    // printByLevelOrder(rootNode);

    // printByFrontOrder(rootNode);
    // cout << endl;

    // printByMiddleOrder(rootNode);
    // cout << endl;

    // printByBehindOrder(rootNode);
    // cout << endl;

    // printByFrontInStack(rootNode);

    // printByBehindInStack(rootNode);

    printByMiddleInStack(rootNode);

    auto result = middleOrder(rootNode);
    for (auto node : result) {
        cout << node->value << " ";
    }
    cout << endl;
    cout << "main end" << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")