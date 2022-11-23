#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void exibir(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int particao(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    int aux;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i = i + 1;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = aux;
    return i + 1;
}
int RandomPart(int A[], int p, int r)
{
    int deslocamento, i, temp;
    time_t t;

    srand((unsigned)time(&t));
    deslocamento = rand() % (r - p + 1);
    i = p + deslocamento;
    temp = A[r];
    A[r] = A[i];
    A[i] = temp;
    return -1; // particao(A, p, q);
}
void quickSort(int A[], int p, int r)
{
    if (p < r)
    {

        int q = particao(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main()
{
    int n = 5;
    int vetor[5] = {5, 2, 3, 1, 4};
    int p = 0;
    int r = 1;
    quickSort(vetor, p, n - 1);
    exibir(vetor, 5);
}