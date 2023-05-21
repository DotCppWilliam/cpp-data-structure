#include <iostream>

using namespace std;

class SinglyList;

class Node 
{
    friend class SinglyList;
public:
    Node(int d = 0, Node* n = nullptr) : data(d), next(n){}
    ~Node() { }
private:
    int data;   // 数据
    Node* next; 
};


class SinglyList 
{
    // 合并两个有序链表
    friend void mergeList(SinglyList&, SinglyList&);
public:
    SinglyList ()
    {
        head = new Node;
    }
    ~SinglyList()
    {
        while (head)
        {
            Node* tmp = head->next;
            delete head;
            head = tmp;
        }
    }
    // 打印链表
    void showAll();

    // 头插法
    void insertHead(int data);

    // 尾插法
    void insertTail(int data);

    // 逆序
    void reverse();

    // 判断是否存在环以及入口点

    // 求倒数第k个节点

    // 删除倒数第k个节点

    // 旋转链表

private:
    Node* head; 
    Node* tail = nullptr;
};


/* 打印链表所有的值 */
void SinglyList::showAll()
{
    Node* tmp = head->next;

    while (tmp)
    {
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }
    cout << endl;
}


/* 头插法 */
void SinglyList::insertHead(int data)
{
    Node* node = new Node(data);

    node->next = head->next;
    head->next = node;

    if (tail == nullptr)
        tail = node;
}

/* 尾插法 */
void SinglyList::insertTail(int data)
{
    Node* node = new Node(data);

    if (head->next == nullptr)
        head->next = node;
    
    if (tail == nullptr)
        tail = node;
    else
    {
        tail->next = node;
        tail = node;
    }
}

int main()
{
    SinglyList list;
    list.insertTail(1);
    list.insertTail(2);
    list.insertTail(3);
    list.insertTail(4);
    list.insertTail(5);

    list.showAll();

    return 0;
}