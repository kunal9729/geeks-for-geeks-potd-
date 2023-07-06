class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low < high){
            int p = partition(arr, low, high);
            
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int p = low;
       int pivot = arr[high];
       
       for(int i = low; i < high; i++){
           if(arr[i] < pivot){
               swap(arr[i], arr[p]);
               ++p;
           }
       }
       
       swap(arr[p], arr[high]);
       
       return p;
    }
};
