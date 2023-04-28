#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<iostream>
#include <iomanip>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;
int sp[50];
int sp2[50];

//int quickSelect(int k, int left, int right) {
//	int p = left;
//	for (int q = left; q <= right; q++) {
//		if (s[q] > s[p]) {
//			swap(s[q], s[p]);
//			++p;
//		}
//	}
//	if (p == k)
//		return p;
//	else if (p < k)
//		return quickSelect(k, p + 1, right);
//	else
//		return quickSelect(k, left, p - 1);
//}

int partition(int arr[], int low, int high) {//用于找到主元并将数组拆分成两部分
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quick_select(int arr[], int low, int high, int k) {//递归查找第k小的元素
    if (low == high) {
        return arr[low];
    }
    int pivot_index = partition(arr, low, high);
    int num_smaller = pivot_index - low + 1;
    if (k == num_smaller) {
        return arr[pivot_index];
    }
    else if (k < num_smaller) {
        return quick_select(arr, low, pivot_index - 1, k);
    }
    else {
        return quick_select(arr, pivot_index + 1, high, k - num_smaller);
    }
}

int LomutoPartition(int* sp, int l, int r, int k)
{
    int p = sp[l];
    int s = l;
    for (int i = l + 1; i < r; i++)
    {
        if (sp[i] < p)
        {
            s = s + 1;
            swap(sp[s], sp[i]);
        }
    }
    swap(sp[l], sp[s]); 

    /*for (int i = 0; i < r; i++)
    {
        cout << sp[i] << " ";
    }
    cout << endl;*/

    //cout << s << endl;

    if (s == k - 1)
    {
        return s;
    }
    if (s < k - 1)
    {
        LomutoPartition(sp, s+1, r, k);
    }
    if (s > k)
    {
        LomutoPartition(sp, 1-1, r, k);
    }
}


int main()
{
	int n, k;//n个元素集合,找第k大
	scanf("%d,%d", &n, &k);
	
	if (n < 1 || n > 50)
	{
		cout << "元素数量超标" << endl;
	}
	if (k < 1 || k > n)
	{
		cout << "k值不合法" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> sp[i];
        sp2[i] = sp[i];
	}
 
    /*for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
	cout << endl;*/

    quick_select(sp2, 0, n-1 , k);
    cout << "第" << k << "小的元素是" << sp2[k-1] << endl;


    LomutoPartition(sp, 0, n, k);
	for (int i = 0; i < k; i++)
	{
		cout << sp[i] << " ";
	}
    cout << endl;

    cout << "前" << k << "小的元素排序结果" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << sp2[i] << " ";
    }
    cout << endl;

	return 0;
}

