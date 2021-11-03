#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>

using namespace std;

using i64 = long long int;

int main()
{
    int n;
    scanf("%d", &n);

    vector<i64> arr(n);

    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    priority_queue<i64> heap;
    i64 ans = 0;
    i64 loff = 0;

    heap.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        loff++;

        i64 lend = heap.top() + loff;

        if (arr[i] <= lend)
        {
            ans += lend - arr[i];
            heap.pop();
            heap.push(arr[i] - loff);
        }

        heap.push(arr[i] - loff);
    }

    printf("%lld\n", ans);

    return 0;
}