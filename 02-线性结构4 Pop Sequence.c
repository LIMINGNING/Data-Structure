#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 1000

typedef struct SNode *Stack;
struct SNode
{
    int Top;
    int Data[MaxSize];
    int Capacity;
};

int IsPopPossible(int array[],int M,int N);

int main()
{
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);

    int array[N];
	for(int i=0;i<K-1;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            scanf("%d",&array[j]);
        }
        if(IsPopPossible(array,M,N))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

	return 0;
}

int IsPopPossible(int array[],int M,int N)
{
    int count=0;

    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Capacity=M;
    S->Top=-1;

    for(int i=1;i<=N;i++)
    {
        if(S->Capacity==S->Top+1)
        {
            return 0;
        }
        else
        {
            S->Data[++S->Top]=i;
        }
        while(S->Data[S->Top]==array[count])
        {
            S->Top--;
            count++;
        }
    }

    if(count == N)
    {
		return 1;
    } 
	else
    {
		return 0;
    }
}