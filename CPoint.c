#include <stdio.h>
#include <malloc.h>
#define N 200

// c struct
struct Point
{
    int x, y;
};

int main()
{
    //Point *A = new Point[N], sum;
    //malloc array of N Point
    struct Point *A = (struct Point *)calloc(N, sizeof(struct Point)), sum = {0,0};
    for (int i = 0; i < N; i++)
    {
        A[i].x = i; A[i].y = -i;

        //sum.add(A[i]);
        sum.x+=A[i].x;
        sum.y+=A[i].y;
    }
    
    printf("[%d,%d]\n",sum.x, sum.y);
    //sum.print();


    free(A);
    //delete[] A;

    return 0;
}