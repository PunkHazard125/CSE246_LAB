#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define ln "\n"
#define RESULT cout << "Result: "
#define FIXED(x) cout << fixed << setprecision(x)

const int64_t LIMIT = 1e6;

int merge_list(vector<int>& list, int start, int mid, int end) {

    vector<int> left(list.begin() + start, list.begin() + mid + 1);
    vector<int> right(list.begin() + mid + 1, list.begin() + end + 1);

    left.push_back(INT_MAX);
    right.push_back(INT_MAX);

    int i = 0, j = 0, k = start, count = 0;

    while (k <= end)
    {
        if (left[i] <= right[j])
        {
            list[k++] = left[i++];
        }
        else
        {
            list[k++] = right[j++];
            count += (left.size() - i - 1);
        }
    }

    return count;

}

int merge_sort(vector<int>& list, int start, int end) {

    if (start >= end)
    {
        return 0;
    }
    
    int mid = start + (end - start) / 2, count = 0;

    count += merge_sort(list, start, mid);
    count += merge_sort(list, mid + 1, end);
    count += merge_list(list, start, mid, end);

    return count;

}

int main(void) {
    
    vi list = {17, 8, 42, 29, 3};
    int count = merge_sort(list, 0, list.size() - 1);

    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    
    cout << "\nCount: " << count << ln;
    
    return 0;

}
