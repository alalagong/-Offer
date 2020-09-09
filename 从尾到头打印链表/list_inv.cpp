#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
/*******************
 * 询问面试官是否可以改变输入的数据？
 * 改变指针的方向
 * 递归
 * 栈
 * *************/

struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
  public:
    ListNode *list_ = NULL;
    ~Solution()
    {
        clearListNode();
    }

  public:
    //前插法
    void createListNode(std::vector<int> &elem)
    {
        if (elem.size() == 0)
        {
            std::cout << "There isn't any element in vector" << std::endl;
            return;
        }
        // 判断是否为空
        if (list_ != NULL)
            clearListNode();
        list_ = new ListNode;
        list_->next = NULL;
        ListNode *node_new;
        for (auto &date : elem)
        {
            node_new = new ListNode;
            node_new->val = date;
            node_new->next = list_->next;
            list_->next = node_new;
        }
    }

    void clearListNode()
    {
        if (list_ != NULL)
        {
            ListNode *p_temp;
            while (list_ != NULL)
            {
                p_temp = list_->next;
                delete[] list_;
                list_ = p_temp;
            }
        }
    }

    void showListNode()
    {
        ListNode *p_temp;
        p_temp = list_->next;
        while (p_temp != NULL)
        {
            std::cout << p_temp->val << "  ";
            p_temp = p_temp->next;
        }
        std::cout << std::endl;
    }

    void inverseList()
    {
        ListNode *new_Node, *new_head;
        new_head = new ListNode;
        new_head->next = NULL;
        while (list_->next != NULL)
        {
            new_Node = list_->next;
            list_->next = new_Node->next;
            new_Node->next = new_head->next;
            new_head->next = new_Node;
        }
        list_ = new_head;
    }

    //使用栈来实现
    void printListFromTailToHead1(std::vector<int> &val_tail_to_head)
    {
        if (list_->next == NULL)
        {
            std::cout << "there isn't any elem in list" << std::endl;
            return;
        }
        std::stack<int> value;

        ListNode *p_node = list_;
        while (p_node->next != NULL)
        {
            p_node = p_node->next;
            value.push(p_node->val);
        }

        while (!value.empty())
        {
            val_tail_to_head.push_back(value.top());
            value.pop();
        }
    }
};

//外部使用递归来实现
void printListFromTailToHead2(ListNode *list, std::vector<int> &elem_inv)
{
    if (list == NULL)
    {
        std::cout << "there isn't any elem in list" << std::endl;
        return;
    }
    if (list->next != NULL)
    {
        printListFromTailToHead2(list->next, elem_inv);
    }
    elem_inv.push_back(list->val);
}

int main()
{
    Solution s;
    std::vector<int> element;
    for (int i = 0; i < 20; i++)
    {
        element.push_back(i + i * i);
    }
    s.createListNode(element);
    s.showListNode();

    s.inverseList(); //将链表掉换方向
    s.showListNode();

    std::vector<int> element_inv;

    s.printListFromTailToHead1(element_inv); //使用栈的形式

    printListFromTailToHead2(s.list_, element_inv); //使用递归的方法

    if (!element_inv.empty())
    {
        std::cout << "printListFromTailToHead: " << std::endl;
        for_each(element_inv.cbegin(), element_inv.cend(), [](const int &val) -> void { std::cout << val << "  "; });
    }
}