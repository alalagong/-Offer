#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
    vector<TreeNode*> next;
    string word = "";
    TreeNode():next(26, NULL) {}
};

int cols, rows;
vector<string> res;

bool dfs(vector<vector<char>> &board, int i, int j, TreeNode*& root)
{
    if (root == NULL)
        return false;

    if (root->word != "")
    {
        res.push_back(root->word);
        delete root;
        root = NULL;
        return true;
    }

    char cur = board[i][j];
    char top = i > 0 ? board[i - 1][j] : 0;
    char down = i + 1 < rows ? board[i + 1][j] : 0;
    char left = j > 0 ? board[i][j - 1] : 0;
    char right = j + 1 < cols ? board[i][j + 1] : 0;

    bool flag = false;

    board[i][j] = '*';
    if (!flag && top != 0 && top != '*' && root->next[top - 'a'] != NULL)
        flag = dfs(board, i - 1, j, root->next[top - 'a']);
    if (!flag && down != 0 && down != '*' && root->next[down - 'a'] != NULL)
        flag = dfs(board, i + 1, j, root->next[down - 'a']);
    if (!flag && left != 0 && left != '*' && root->next[left - 'a'] != NULL)
        flag = dfs(board, i, j - 1, root->next[left - 'a']);
    if (!flag && right != 0 && right != '*' && root->next[right - 'a'] != NULL)
        flag = dfs(board, i, j + 1, root->next[right - 'a']);
    board[i][j] = cur;

    if (flag)
    {
        delete root;
        root = NULL;
    }

    return flag;
}



vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    rows = board.size();
    if (rows == 0)
        return res;
    cols = board[0].size();
    if (cols == 0)
        return res;

    // construct tree
    TreeNode *root = new TreeNode();
    for (auto word : words)
    {
        TreeNode *cur = root;
        for (char s : word)
        {
            if (cur->next[s - 'a'] == NULL)
                cur->next[s - 'a'] = new TreeNode();
            cur = cur->next[s - 'a'];
        }
        cur->word = word;
    }

    // search
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            char s = board[i][j];
            if (root != NULL && root->next[s - 'a'] != NULL)
                dfs(board, i, j, root->next[s - 'a']);
        }
    return res;
}

void f(TreeNode* a)
{
    delete a;
    a = NULL;
}

// class A
// {
//     int x; 
// protected:
//     static int count;
// public:
//     A(int i = 0):x(i) { count++; x += 15;}
//     virtual void f() const {cout << x << "_" << count << endl;}
//     virtual ~A() {count--;}
// };

// class D : public A
// {
//     int y;
// public :
//     D(int i, int j) : A(i) , y(j) {count++; y += 150;}
//     virtual void f() const {cout << y << "_" << count  <<endl;}
//     static void g() { cout << count << endl;}
//     ~D() {count--; g();}
// };

// int A::count = 0;

int main()
{
    // A *p = new D(1,2);
    // p->f();
    // delete p;
    // system("pause");
    // TreeNode* bb = new TreeNode();
    // bb->word = "bb";
    // f(bb);
    // // delete bb;
    // // bb = NULL;
    // if(bb != NULL)
    //     cout << sizeof(*bb) <<endl;

    // vector<vector<char>> board;
    // vector<char> a;
    
    // a.push_back('o');
    // a.push_back('a');
    // a.push_back('a');
    // a.push_back('n');
    // board.push_back(a);

    // a.clear();
    // a.push_back('e');
    // a.push_back('t');
    // a.push_back('a');
    // a.push_back('e');
    // board.push_back(a);

    // a.clear();
    // a.push_back('i');
    // a.push_back('h');
    // a.push_back('k');
    // a.push_back('r');
    // board.push_back(a);

    // a.clear();
    // a.push_back('i');
    // a.push_back('f');
    // a.push_back('l');
    // a.push_back('v');
    // board.push_back(a);

    // string b;
    // vector<string> word;
    // b = "a";
    // word.push_back(b);
    // b = "eat";
    // word.push_back(b);
    // b = "rain";
    // word.push_back(b);


    // findWords(board, word);

    return 0;
}