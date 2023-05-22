#include <algorithm>
#include <iostream>

using namespace std;

class SinglyList;

class Node 
{
public:
    Node(int d = 0, Node* n = nullptr) : data(d), next(n){}
    ~Node() { }
    int data;   // 数据
    Node* next; 
};

void mergeList(SinglyList&, SinglyList&);


class SinglyList 
{
    // 合并两个有序链表
    friend void mergeList(SinglyList&, SinglyList&);
    // 判断两个链表是否相交,相交则返回true,并返回相交的节点,否则返回false
    friend bool isIntersected(SinglyList& list1, SinglyList& list2, int& data);
    // 生成相交两个链表
    friend void generateIntList(SinglyList& list1, SinglyList& list2);
public:
    SinglyList ()
    {
        head = new Node;
    }
    ~SinglyList()
    {
        // while (head)
        // {
        //     Node* tmp = head->next;
        //     delete head;
        //     head = tmp;
        // }
    }

    // 生成一个带环的链表
    void generateCricle()
    {
        insertTail(1);
        insertTail(2);
        insertTail(3);
        insertTail(4);
        insertTail(5);

        tail->next = head->next->next;
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
    bool hasCircle(int& entry);

    // 求倒数第k个节点
    bool lastKNode(int& data, int k);

    // 删除倒数第k个节点
    bool delLastKNode(int k);

    // 旋转链表
    bool rotate(int k);

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


/* 逆序链表 */
void SinglyList::reverse()
{
    // 空链表退出
    if (head->next == nullptr)
        return;
    // 只有一个节点退出
    if (head->next->next == nullptr)
        return;

    Node* prev = head->next;
    Node* curr = prev->next;

    prev->next = nullptr;

    while (curr)
    {
        prev = curr->next;
        curr->next = head->next;
        head->next = curr;
        curr = prev;
    }
}


/* 判断是否存在环,返回入口点*/
bool SinglyList::hasCircle(int& entry)
{
    if (head->next == nullptr) return false;    // 空链表
    Node* p = head->next;
    Node* q = p;

    while (q)
    {
        if (q->next == nullptr)
            return false;
        
        p = p->next;
        q = q->next->next;

        if (q == p)
        {
            entry = q->data;
            return true;
        }
    }

    return false;
}



/* 获取倒数第k个节点 */
bool SinglyList::lastKNode(int& data, int k)
{
    Node* p = head->next;
    Node* q = head;
    int count = 0;
    int i;

    while (p)
    {
        count++;
        p = p->next;
    }

    if (count < k || k == 0)  // 没有倒数第k个节点. 或者求倒数第0个节点
        return false;

    p = head;
    for (i = 0; i < k; i++)
        p = p->next;

    while (p)
    {
        p = p->next;
        q = q->next;
    }

    data = q->data;
    return true;
}


/* 删除倒数第k个节点 */
bool SinglyList::delLastKNode(int k)
{
    Node* p = head->next;
    Node* q = head;

    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }

    if (k == 0 || count < k)
        return false;

    p = head;
    for (int i = 0; i < k; i++)
        p = p->next;
    
    while (p->next)
    {
        p = p->next;
        q = q->next;
    }


    p = q->next;
    q->next = p->next;

    delete p;
    return true;
}


/* 旋转链表 */
bool SinglyList::rotate(int k)
{
    if (k == 0) return false;
    Node* p = head->next;
    Node* q = head;
    int count = 0;

    while (p)
    {
        count++;
        p = p->next;
    }

    k = k % count;
    p = head;
    for (int i = 0; i < k; i++)
        p = p->next;

    // 找倒数第k个节点
    while (p->next)
    {
        p = p->next;
        q = q->next;
    }

    p->next = head->next;
    head->next = q->next;
    q->next = nullptr;
    return true;
}

/* 合并两个有序链表 */
void mergeList(SinglyList& list1, SinglyList& list2)
{
    Node* p = list1.head->next;
    Node* q = list2.head->next;
    Node* last = list1.head;

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            p = p->next;
        }
        else
        {
            last->next = q;
            q = q->next;
        }
        last = last->next;
    }

    while (p)
    {
        last->next = p;
        p = p->next;
        last = last->next;
    }

    while (q)
    {
        last->next = q;
        q = q->next;
        last = last->next;
    }
}


/* 生成相交的两个链表 */
void generateIntList(SinglyList& list1, SinglyList& list2)
{
    list1.insertTail(1);
    list1.insertTail(2);
    list1.insertTail(3);
    list1.insertTail(4);
    list1.insertTail(5);
    list1.insertTail(6);
    list1.insertTail(7);

    list2.insertTail(4);
    list2.insertTail(5);
    list2.insertTail(6);
    list2.insertTail(7);
    list2.tail->next = list1.head->next->next;
}

/* 判断两个链表是否相交,相交则返回true,并返回相交的节点,否则返回false */
bool isIntersected(SinglyList& list1, SinglyList& list2, int& data)
{
    int list1_cnt = 0, list2_cnt = 0;   // 存储两个链表的长度

    Node* p = list1.head->next;
    Node* q = list2.head->next;

    while (p)
    {
        list1_cnt++;
        p = p->next;
    }

    while (q)
    {
        list2_cnt++;
        q = q->next;
    }

    p = list1.head->next;
    q = list2.head->next;

    int i;
    int step = std::max(list1_cnt, list2_cnt) - std::min(list1_cnt, list2_cnt);
    if (list1_cnt > list2_cnt)
        for (i = 0; i < step; i++)
            p = p->next;
    else
        for (i = 0; i < step; i++)
            q = q->next;

    while (p)
    {
        if (p == q)
        {
            data = p->data;
            return true;
        }

        p = p->next;
        q = q->next;
    }
    return false;
}



int main()
{
    SinglyList list1, list2;
    generateIntList(list1, list2);
    int data;

    if (isIntersected(list1, list2, data))
        printf("两个链表相交,相交的节点是[%d]\n", data);
    else
        printf("两个链表没有相交\n");


    list2.showAll();

    return 0;
}