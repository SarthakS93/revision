#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int b[], int c[], int n, int m) {
    int i = 0, j = 0, k = 0;
    cout<<"inside merge"<<endl;
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            c[k] = a[i];
            i++;
        }
        else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    if(i < n && j == m) {
        while(i < n) {
            c[k] = a[i];
            k++;
            i++;
        }
    }
    else if(j < m && i == n) {
        while(j < m) {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    return;
}

void mergesort(int c[], int n) {
    cout<<"inside mergesort func"<<endl;
    if(n <= 1)
        return;
    int a[n], b[n], i, j = 0;
    cout<<"inside mergesort level 2"<<endl;

    for(i = 0; i < n/2; i++) {
        a[i] = c[i];
    }
    cout<<"1st array done"<<endl;

    for(; i < n; i++) {
        b[j++] = c[i];
    }
    cout<<"2nd array done"<<endl;

    mergesort(a, n/2);
    mergesort(b, j);
    cout<<"calling merge"<<endl;
    merge(a, b, c, n/2, j);
cout<<"return from mergesort"<<endl;
}

int main() {

    int a[10], n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    cout<<"Enter the elements of the array: "<<endl;
    for(int i = 0; i < n; i++) 
        cin>>a[i];
    mergesort(a, n);
    cout<<"After calling mergesort"<<endl;
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;

return 0;
}
