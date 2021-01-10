#include <iostream>
#include <vector>
using namespace std;

int min_path(vector<vector<int>> &array)
{
    int n = array.size();
    if (n==1) return array[0][0];
    for (int i=n-2; i>=0; --i)
    {
        for (int j=0; j<=i;++j)
        {
            if (array[i+1][j]< array[i+1][j+1])
                array[i][j] += array[i+1][j];
            else
                array[i][j] += array[i+1][j+1];
        }
    }
    return array[0][0];
}

int main() {
    //int a;
    //cin >> a;
    vector<vector<int>> array{{2},{1,3},{5,4,6}};
    int m = min_path(array);
    cout << m<<endl;
}
