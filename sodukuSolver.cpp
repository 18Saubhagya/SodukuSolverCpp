#include <iostream>
 #define n 9
using namespace std;
bool check(int mat[n][n], int row, int col, int no)
{
    for (int x = 0; x <= 8; x++)
        if (mat[row][x] == no)
            return false;
    for (int x = 0; x <= 8; x++)
        if (mat[x][col] == no)
            return false;
    int a = row - row % 3, 
            b = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[i + a][j + b] == no)
                return false;
    return true;
}
bool solveSoduko(int mat[n][n], int row, int col)
{
    if (row == n - 1 && col == n)
        return true;
    if (col == n) {
        row++;
        col = 0;
    }
    if (mat[row][col] > 0)
        return solveSoduko(mat, row, col + 1);
    for (int i = 1; i <= n; i++) 
    {
        if (check(mat, row, col, i)) 
        {
            mat[row][col] = i;
            if (solveSoduko(mat, row, col + 1))
                return true;
        }
        mat[row][col] = 0;
    }
    return false;
}
int main()
{
    int i,j;
    cout<<"Enter the unsolved soduku (9x9) blank spaces to be represented by 0"<<endl;
    int mat[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>mat[i][j];
    }
    if (solveSoduko(mat, 0, 0)){
        for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    }
    else
        cout << "No solution can be done for this re enter the soduku" << endl;
    return 0;
}