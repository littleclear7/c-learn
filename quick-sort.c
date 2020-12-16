//
// Created by root on 2020/12/16.
//

void display(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int getsandard(int array[], int low, int high){
    int key = array[low];
    int st = 0;
    while (low < high){
        while (array[high] >= key && high>low)
            high--;
        if(low < high)
            array[low] = array[high];
        while (array[low] <= key && high > low)
            low++;
        if(low < high)
            array[high] = array[low];
    }
    array[low] = key;
    return low;
}
void quickSort(int array[], int low, int high){
    if (low < high) {
        int standard = getsandard(array, low, high);
        quickSort(array, low, standard - 1);
        quickSort(array, standard + 1, high);
    }
}

int main(){
    int a[10] = {1,4,3,2,8,2,4,31,1,2};
    quickSort(a,0,9);
    display(a,10);
    return 0;
}