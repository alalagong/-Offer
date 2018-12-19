#include <iostream>

void replaceSpace(char *str, int length)
{
    if (str == NULL || length == 0)
        return;

    int orig_length = 0;
    int new_legth = 0;
    int num_of_blank = 0;
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        orig_length++;
        if (*(str + i) == ' ')
            num_of_blank++; //数空格数目
    }
    //超出去的话报错
    if (orig_length + num_of_blank * 2 + 1 > length)
        return;

    char *p_end = str + orig_length + num_of_blank * 2; //指向空闲位置指针
    char *p_move = str + orig_length;                   //移动指针
    while (p_move != p_end)
    {
        if (*p_move == ' ')
        {
            *p_end = '0';
            p_end--;
            *p_end = '2';
            p_end--;
            *p_end = '%';
        }
        else
        {
            *p_end = *p_move;
        }
        p_end--;
        p_move--;
    }
}

int main()
{
    char str[10] = "we ha";
    std::cout << "before: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << str[i];
    }
    replaceSpace(str, 10);

    std::cout << "\nafter: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << str[i];
    }
    std::cout<<"\n";
}