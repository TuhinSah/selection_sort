#include<stdio.h>
#include<stdlib.h>

int Comparisons = 0, Exchanges = 0;

int sorted(int *A, int n) {
    while(--n > 0) if(A[n] < A[n-1]) return 0;
    return -1;
}

int min_index(int *A, int l, int r) {
    if(l < r - 1) {
        int m1 = min_index(A, l, l+(r-l)/2);
        int m2 = min_index(A, l+1+(r-l)/2, r);

        Comparisons++;
        if(A[m1] <= A[m2])
            return m1;
        else
            return m2;
    } else if(l == r - 1) {
        Comparisons++;

        if(A[l] <= A[r])
            return l;
        else
            return r;
    } else if(l > r) {
        printf("Index error in min_index: l %d r %d",l,r);

        return -1;
    } else
        return l;

}

void selection_sort(int *A, int l, int r) {
    int i, j;

    for(i = l; i < r; i++) {
        int temp = A[i];
        j = min_index(A, i, r);
        A[i] = A[j];
        A[j] = temp;
        Exchanges++;
    }
}

int main(void) {
    int n, i;
    
    scanf("%d",&n);
    if(n < 1)
        printf("Wrong size!");

    int A[n];

    for(i = 0; i < n; i++)
        scanf("%d", A+i);

    Comparisons = 0;
    Exchanges = 0;
        
    selection_sort(A, 0, n-1);
        
    if(sorted(A, n)) {
        for(i = 0; i < n; i++)
            printf("%d ", A[i]);
        printf("\n");
    } else
        printf("Logical error: not sorted!");
    
    return 0;    
}
