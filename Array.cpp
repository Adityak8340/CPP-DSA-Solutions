#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum and maximum values in the array
vector<int> minmax(vector<int> arr) {
    vector<int> ans;
    int minim = INT_MAX;
    int maxim = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > maxim) maxim = arr[i];
        if(arr[i] < minim) minim = arr[i];
    }
    ans.push_back(minim);
    ans.push_back(maxim);
    return ans;
}

// Function to find the pair with a given sum
vector<int> pairsum(vector<int> arr, int k) {
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        int flag = 0;
        for(int j = 1; j < arr.size(); j++) {
            if(i == j) continue;
            if(arr[i] + arr[j] == k) {
                flag = 1;
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                break;
            }
        }
        if(flag) break;
    }
    return ans;
}

// Function to remove multiple occurrences of an element
vector<int> multiple_element(vector<int> arr, int x) {
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != x) ans.push_back(arr[i]);
    }
    return ans;
}

// Function to check if a single element is present in the array
string single_element(vector<int> arr, int x) {
    for(auto it : arr) if(it == x) return "True";
    return "False";
}

// Function to check if the array is sorted
string sorted(vector<int> arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i] > arr[i + 1]) return "False";
    }
    if(arr[arr.size() - 1] < arr[arr.size() - 2]) return "False";
    return "True";
}

// Function to rotate the array by k positions
vector<int> rotateArray(vector<int> arr, int k) {
    int j = k;
    vector<int> slicedArr;
    for(j; j < arr.size(); j++)
        slicedArr.push_back(arr[j]);
    for(j -= arr.size(); j - arr.size() < k; j++)
        slicedArr.push_back(arr[j - arr.size()]);
    return slicedArr;
}

// Function to perform right shift on the array
vector<int> rightshift(vector<int> arr) {
    int k = arr[arr.size() - 1];
    for(int i = arr.size() - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = k;
    return arr;
}

// Function to perform left shift on the array
vector<int> leftshift(vector<int> arr) {
    int k = arr[0];
    for(int i = 1; i < arr.size(); i++) arr[i - 1] = arr[i];
    arr[arr.size() - 1] = k;
    return arr;
}

// Function to reverse the array
vector<int> rev(vector<int> arr) {
    for(int i = 0; i < arr.size() / 2; i++) swap(arr[i], arr[arr.size() - i - 1]);
    return arr;
}

// Function to find the minimum value in the array
int mini(vector<int> arr) {
    int c = INT_MAX;
    for(auto it : arr) {
        if(it < c) c = it;
    }
    return c;
}

// Function to find the maximum value in the array
int maxi(vector<int> arr) {
    int c = INT_MIN;
    for(auto it : arr) {
        if(it > c) c = it;
    }
    return c;
}

// Function to get the value at a given index
int getvalue(vector<int> arr, int index) {
    if(index < arr.size()) return arr[index];
    else cout << "Enter a valid index" << endl;
}

// Function to check if an element is present in the array using linear search
string linear(vector<int> arr, int x) {
    for(auto it : arr) if(it == x) return "True";
    return "False";
}

// Function to delete an element from the array
vector<int> del(vector<int> arr, int x) {
    int it = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == x) {
            it = i;
            break;
        }
    }
    if(it != -1) {
        arr.erase(arr.begin() + it);
    }
    else cout << "Element " << x << " not found in the array." << endl;
    return arr;
}

// Function to insert an element at a given index
vector<int> inserting(vector<int> arr, int x, int i) {
    if(i < arr.size()) arr[i] = x;
    return arr;
}

// Function to add an element to the end of the array
vector<int> addi(vector<int> arr, int x) {
    arr.push_back(x);
    return arr;
}

// Function to display the array
void disp(vector<int> arr) {
    cout << "Array: ";
    for(auto it : arr) cout << it << " ";
    cout << endl;
}

int main() {
    int n, k;
    cout << "Input size: ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Input array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    // Example usage of functions
    cout << "Array after adding 9: ";
    disp(addi(arr, 9));

    cout << "Array after inserting 6 at index 1: ";
    disp(inserting(arr, 6, 1));

    cout << "Array after deleting 4: ";
    disp(del(arr, 4));

    cout << "Is there 3 in the array? : " << linear(arr, 3) << endl;

    cout << "The value at index 2 is: " << getvalue(arr, 2) << endl;

    cout << "Maximum value of array: " << maxi(arr) << endl;

    cout << "Minimum value of array: " << mini(arr) << endl;

    cout << "Reversed array: ";
    disp(rev(arr));

    cout << "Left shifted array: ";
    disp(leftshift(arr));

    cout << "Right shifted array: ";
    disp(rightshift(arr));

    cout << "Rotated array by 2 positions from left: ";
    disp(rotateArray(arr, 2));

    cout << "Is array sorted? : " << sorted(arr) << endl;

    cout << "Is single element 2 present in array? : " << single_element(arr, 2) << endl;

    cout << "Multiple elements except 2: ";
    disp(multiple_element(arr, 2));

    cout << "Pair with sum 5: ";
    disp(pairsum(arr, 5));

    cout << "The minimum & maximum values are: ";
    disp(minmax(arr));

    return 0;
}
