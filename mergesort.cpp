
namespace MS {

    void merge(int* arr, int left, int mid, int right) {
        int i = 0;
        int j = 0;
        int k = 0;

        int t1 = mid - left + 1;
        int t2 = right - mid;

        int L[t1];
        int R[t2];

        for(i = 0; i < t1; i++) {
            L[i] = arr[left + i];
        }

        for(j = 0; j < t2; j++) {
            R[j] = arr[mid + 1 + j];
        }

        i = 0;
        j = 0;
        k = left;

        while(i < t1 && j < t2) {
            if(L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }

            else {
                arr[k] = R[j];
                j++;
            }

            k++;
        }

        while(i < t1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while(j < t2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergesort(int* arr, int left, int right) {

        if (left < right) {
            int mid = (left + (right - 1))/2;
            mergesort(arr, left, mid);
            mergesort(arr, mid+1, right);

            merge(arr, left, mid, right);
        }
    }
}
