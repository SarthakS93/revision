#include<bits/stdc++.h>
using namespace std;

void intersectionOfArrays() {
    int n, m, x;
    cout<<"Enter the size of the arrays: "<<endl;
    cin>>n>>m;
    vector<int> a, b, c;
    cout<<"Enter the elements of the 1st array: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>x;
        a.push_back(x);
    }
    cout<<"Enter the elements of the 2nd array: "<<endl;
    for(int i = 0; i < m; i++){
        cin>>x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            c.push_back(a[i]);
            i++; j++;
        }
        else if(a[i] < b[j])
            i++;
        else
            j++;
    }

    cout<<"The intersection of the arrays: "<<endl;
    for(int i = 0; i < c.size(); i++)
        cout<<c[i]<<" "<<endl;

}


void pairSumToX() {
    int n, x;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int> a;
    cout<<"Enter the elements of the array: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>x;
        a.push_back(x);
    }
    cout<<"Enter the value of target: "<<endl;
    cin>>x;

    cout<<"The pairs are as follows: "<<endl;
    int low = 0, high = n - 1;
    while(low < high) {
        if(a[low] + a[high] == x) {
            cout<<a[low]<<" "<<a[high]<<endl;
            low++; high--;
        }
        else if(a[low] + a[high] < x) {
            low++;
        }
        else {
            high--;
        }
    }
}

void selectionSort() {
    int n, x;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int> a;
    cout<<"Enter the elements of the array: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>x;
        a.push_back(x);
    }
    
    for(int i = 0; i < n - 1; i++) {
        int min = a[i], minPos = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < min) {
                min = a[j];
                minPos = j;
            }            
        }
        swap(a[i], a[minPos]);
    }

    cout<<"The sorted array is as follows: "<<endl;
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;

}


void bubbleSort() {
    int n, x;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int> a;
    cout<<"Enter the elements of the array: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>x;
        a.push_back(x);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    
    cout<<"The sorted array is as follows: "<<endl;
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void insertionSort() {
    int n, x;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int> a;
    cout<<"Enter the elements of the array: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>x;
        a.push_back(x);
    }

    int i = 1;
    while(i < n) {
        int j = i - 1;
        int key = a[j];
        while(j > 0 && key < a[j]) {
            swap(a[j], a[j + 1]);
            j--;
        }
        a[i + 1] = key;
        i++;
    }
    
    cout<<"The sorted array is as follows: "<<endl;
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}


int main() {


//intersectionOfArrays();
//pairSumToX();
//selectionSort();
//bubbleSort();
insertionSort();

return 0;
}
