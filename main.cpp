#include <iostream>
#include <vector>
#include <stack>


//>> magic(4)
//
//ans =
//
//16     2     3    13
//5    11    10     8
//9     7     6    12
//4    14    15     1
//
//>> flip(ans,1)
//
//ans =
//
//4    14    15     1
//9     7     6    12
//5    11    10     8
//16     2     3    13

using namespace std;

int main() {

    vector<vector<int>> vec{ { 1, 2, 3 },
                             { 4, 5, 6 },
                             { 7, 8, 9 } };


    int row = 3;
    int column =3;

    stack<vector<int>> stack_vec;
    vector<int> temp;
    int size = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
        {
//            cout << vec[i][j] << " ";
            temp.push_back(vec[i][j]);
            if(size == column-1) {
                stack_vec.push(temp);
                size = 0;
                temp.clear();
                continue;
            }
            size++;
        }
//        cout << endl;
    }

    //flatten
    vector<int> flattened;

    while(!stack_vec.empty())
    {
        for(int i = 0; i<row; i++)
        {
            flattened.push_back(stack_vec.top()[i]);
        }
        stack_vec.pop();
    }

    cout << "---------"<< endl;

    for (int i = 0; i < flattened.size(); i++)
    {
        cout << flattened[i]  << " ";
    }

    return 0;
}
