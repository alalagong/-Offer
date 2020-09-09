#include <vector>
#include <iostream>

using namespace std;

bool Find(int target, vector< vector<int> > array)
{
    int row_num = array.size();
    //异常情况
    if (row_num == 0)
        return false;
    int col_num = array[0].size();
    //异常情况
    if (col_num == 0)
        return false;
    //去头去尾
    vector< vector<int> >::iterator iter_end_2 = array.end() - 1;
    vector<int>::iterator iter_end_1 = (*iter_end_2).end() - 1;
    if (array[0][0] > target || *iter_end_1 < target)
        return false;

    int mid_row = row_num / 2;
    int mid_col = col_num / 2;
    //这种情况下会死循环
    if (mid_row == 1 && row_num == 2)
        mid_row = 0;
    if (mid_col == 1 && col_num == 2)
        mid_col = 0;

    if (array[mid_row][mid_col] == target)
        return true;
    if (array[mid_row][mid_col] < target)
    {
        vector< vector<int> > array_temp_leftdown, array_temp_rightup, array_temp_rightdown;
        vector< vector<int> >::iterator iter;
        //左下角的块
        for (iter = array.begin() + mid_row + 1; iter != array.end(); iter++)
        {
            vector<int> array_temp_1((*iter).begin(), (*iter).begin() + mid_col + 1);
            array_temp_leftdown.push_back(array_temp_1);
        }
        //右下角的块
        for (iter = array.begin() + mid_row + 1; iter != array.end(); iter++)
        {
            vector<int> array_temp_1((*iter).begin() + mid_col + 1, (*iter).end());
            array_temp_rightdown.push_back(array_temp_1);
        }
        //右上角的块
        for (iter = array.begin(); iter != array.begin() + mid_row + 1; iter++)
        {
            vector<int> array_temp_1((*iter).begin() + mid_col + 1, (*iter).end());
            array_temp_rightup.push_back(array_temp_1);
        }

        return Find(target, array_temp_leftdown) || Find(target, array_temp_rightup) || Find(target, array_temp_rightdown);
    }
    if (array[mid_row][mid_col] > target)
    {
        vector< vector<int> > array_temp_leftdown, array_temp_rightup, array_temp_leftup;
        vector< vector<int> >::iterator iter;
        //左下角的块
        for (iter = array.begin() + mid_row + 1; iter != array.end(); iter++)
        {
            vector<int> array_temp_1((*iter).begin(), (*iter).begin() + mid_col + 1);
            array_temp_leftdown.push_back(array_temp_1);
        }
        //左上角的块
        for (iter = array.begin(); iter != array.begin() + mid_row + 1; iter++)
        {
            vector<int> array_temp_1((*iter).begin(), (*iter).begin() + mid_col + 1);
            array_temp_leftup.push_back(array_temp_1);
        }
        //右上角的块
        for (iter = array.begin(); iter != array.begin() + mid_row + 1; iter++)
        {
            vector<int> array_temp_1((*iter).begin() + mid_col + 1, (*iter).end());
            array_temp_rightup.push_back(array_temp_1);
        }

        return Find(target, array_temp_leftdown) || Find(target, array_temp_rightup) || Find(target, array_temp_leftup);
    }
    return false;
}
// method two
bool Find2(int target, vector<vector<int> > array)
{
    int m = array.size();
    int n = array[0].size();
    if (m == 0 || n == 0)
        return false;
    int i = 0;
    int j = n - 1;
    while ((i < m) && (j >= 0))
    {
        if (array[i][j] < target)
            ++i;
        else if (array[i][j] > target)
            --j;
        else
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int> > matrix(25, std::vector<int>(25, 9));

    matrix[0][0] = 2;

    if (Find2(2, matrix) == true)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}
