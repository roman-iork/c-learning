#include <stdlib.h>
#include <stdio.h>

void read_array(int *arr, int size) {
    printf("Введите %d целых чисел через пробел:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void print_array(int *arr, int size) {
    printf("Вот ваши отсортированные числа: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void arr_copy(int *from, int *into, int size){
    for(int i = 0; i < size; i++) {
        into[i] = from[i];
    }
}
int* sort_bubble(int *array, int size) {
    int *bubbled = malloc(size * sizeof(int));
    arr_copy(array, bubbled, size);
    int mutable_size = size - 1;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < mutable_size; j++) {
            if (bubbled[j] > bubbled[j + 1]) {
                int max = bubbled[j];
                bubbled[j] = bubbled[j + 1];
                bubbled[j + 1] = max;
            }
        }
        mutable_size--;
    }
    return bubbled;
}

void sort_choosy(int *arr_mutable, int size) {
    for (int i = 0; i < size; i++) {
        int min_val = arr_mutable[i];
        int min_index = i;
        for (int j = i; j < size; j++) {
            if (arr_mutable[j] < min_val) {
                min_val = arr_mutable[j];
                min_index = j;
            }
        }
        arr_mutable[min_index] = arr_mutable[i];
        arr_mutable[i] = min_val;
    }
}

int main() {
    // first ask to enter quantity of numbers
    int n;
    printf("Введите количество чисел в массиве: ");
    scanf("%d", &n);
    
    // then aks to enter numbers and read them
    int *in_arr = malloc(n * sizeof(int));
    read_array(in_arr, n);

    // create bubble sorted array
    int *bubbly_sorted = sort_bubble(in_arr, n);
    print_array(bubbly_sorted, n);

    // create choosy sorted array
    int *choosy_sorted = malloc(n * sizeof(int));
    arr_copy(in_arr, choosy_sorted, n);
    sort_choosy(choosy_sorted, n);
    print_array(choosy_sorted, n);


    // free memory and null pointers
    free(in_arr);
    free(bubbly_sorted);
    free(choosy_sorted);
    in_arr = NULL;
    bubbly_sorted = NULL;
    choosy_sorted = NULL;
    return 0;
}