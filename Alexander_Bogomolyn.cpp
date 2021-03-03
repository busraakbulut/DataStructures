#include <stdio.h>
void print(const int *v, const int size)
{
    int i;
    if (v != 0)
        {
            for ( i = 0; i < size; i++)
                {
                    printf("%4d", v[i] );
                }
            printf("\n");
        }
}
void alexanderbogomolyn(int *Value, int N, int k)
{	int level;
    level = -1;
    int i;
    level = level+1;
    Value[k] = level;
    if (level == N)
        print(Value, N);
    else
        for (i = 0; i < N; i++)
            if (Value[i] == 0)
                alexanderbogomolyn(Value, N, i);
    level = level-1;
    Value[k] = 0;
}
int main()
{
    int N = 4;
    int i;
    int Value[N];
    for (i = 0; i < N; i++)
        {
            Value[i] = 0;
        }
    printf("\nPermutation using Alexander Bogomolyn's algorithm: ");
    alexanderbogomolyn(Value, N, 0);
    return 0;
}
