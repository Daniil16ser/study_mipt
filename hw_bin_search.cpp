// Башни и дождь
// #include <vector>
// #include <stack>
// int rain_water(std::vector<int> &height){
//     std::stack<int> st;
//     int ans = 0;
//     for (int i = 0; i < height.size(); ++i){
//         if (st.size() == 0)
//             st.push(i);
        
        
//         else if (height[st.top()] > height[i])
//         st.push(i);
//         else{
//             int prev = 0;
//             while(st.size()>0 && height[st.top()] <= height[i]){
//                 int cur = height[st.top()];
//                 ans += (cur - prev) * (i-st.top() - 1);
//                 prev = cur;
//                 st.pop();
//             }
//             st.push(i);
//         }
//     }
//     return ans;
// }

// [7,9,2,3,4,5,6]
//log(n)


#include <iostream>
#include <vector>

int bin_search(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else { 
            if (arr[mid] < target && target <= arr[right]) {
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    std::vector<int> arr = {7, 8, 9,10, 1, 2, 3, 4, 5, 6};
    int target = 8;
    int result = bin_search(arr, target);

    std::cout << result << std::endl;

    return 0;
}
