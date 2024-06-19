
class Solution 
{
public:
    void Rearrange(int arr[], int n) {
        auto mergeArrays = [&](int left, int mid, int right) {
            vector<int> tempArray(arr + left, arr + right + 1);
            
            int i = left, j = mid + 1, k = 0;
            while (i <= mid && j <= right) {
                if (arr[i] >= 0 && arr[j] < 0)
                    tempArray[k++] = arr[j++];
                else
                    tempArray[k++] = arr[i++];
            }
            
            while (i <= mid)
                tempArray[k++] = arr[i++];
            while (j <= right)
                tempArray[k++] = arr[j++];
            
            copy(tempArray.begin(), tempArray.end(), arr + left);
        };

        function<void(int, int)> mergeSort = [&](int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;
                mergeSort(left, mid);
                mergeSort(mid + 1, right);
                mergeArrays(left, mid, right);
            }
        };

        mergeSort(0, n - 1);
    }
};
