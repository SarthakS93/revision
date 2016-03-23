#include<bits/stdc++.h>
using namespace std;

void spiralPrint() {
    int n, m, x;
    cout<<"Enter the size of the 2D array: "<<endl;
    cin>>n>>m;
    vector<vector<int> > a(n, vector<int>(m, 1));
    cout<<"Enter the elements of the array: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>x;
            a[i][j] = x;
        }
    }

    cout<<"The 2D array input is: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int top = 0, bottom = n - 1, left = 0, right = n - 1, dir = 0, i, j;
    cout<<"The spiral print is as follows: "<<endl;

    while(top <= bottom) {
        if(dir == 0) {
            j = left;
            while(j <= right) {
                cout<<a[top][j]<<"-->";
                j++;
            }
            top++;
        }
        else if(dir == 1) {
            i = top;
            while(i <= bottom) {
                cout<<a[i][right]<<"-->";
                i++;
            }
            right--;
        }
        else if(dir == 2) {
            j = right;
            while(j >= left) {
                cout<<a[bottom][j]<<"-->";
                j--;
            }
            bottom--;
        }
        else if(dir == 3) {
            i = bottom;
            while(i >= top) {
                cout<<a[i][left]<<"-->";
                i--;
            }
            left++;
        }
        dir++;
        dir = dir % 4;
    }

}

int minCostPathHelper(int a[][5], int n, int m) {
    if(n < 0 || m < 0)
        return INT_MAX;
    if(n == 0 && m == 0)
        return a[n][m];
    int ans = (a[n][m] + min(minCostPathHelper(a[n - 1][m - 1]), 
     min(minCostPathHelper(a[n - 1][m]), minCostPathHelper(a[n][m - 1]))));
    cout<<"Step Ans - "<<ans<<endl;
    return ans;
}
void minCostPath() {
    int n, m;
    cout<<"Enter the 2D matrix dimensions: "<<endl;
    cin>>n>>m;
    cout<<"Enter the elements of the matrix: "<<endl;
    int a[5][5];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
        }
    }

    int x, y;
    cout<<"Enter the coordinates of block you want to reach: "<<endl;
    cin>>x>>y;
    cout<<"Output: "<<minCostPathHelper(a, x, y)<<endl;
}

int main() {

//spiralPrint();
minCostPath();

return 0;
}
