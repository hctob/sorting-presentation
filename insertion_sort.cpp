namespace IS {

    void insertion_sort(int * arr, int size) {
        int key = 0;

        for(int i = 1; i < size; i++) {
            key = arr[i];
            int j = i;

            while(j >= 0 && arr[j-1] > key) {
                arr[j] = arr[j-1];
                j--;
            }

            arr[j] = key;
        }
    }
}
