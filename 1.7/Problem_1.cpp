#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define ln "\n"
#define RESULT cout << "Result: "
#define FIXED(x) cout << fixed << setprecision(x)

const int64_t LIMIT = 1e6;

int merge_list(vi& list, int start, int mid, int end) {

    vi left(list.begin() + start, list.begin() + mid + 1);
    vi right(list.begin() + mid + 1, list.begin() + end + 1);

    int count = 0;

    int i = 0, j = 0, k = start;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            list[k++] = left[i++];
        }
        else
        {
            list[k++] = right[j++];
            count += left.size() - i;
        }
    }

    while (i < left.size())
    {
        list[k++] = left[i++];
    }
    
    while (j < right.size())
    {
        list[k++] = right[j++];
    }
    
    return count;

}

int merge_sort(vi& list, int start, int end) {

    if (start >= end)
    {
        return 0;
    }

    int count = 0;
    int mid = start + (end - start) / 2;

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
