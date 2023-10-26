
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int Tab[10];

void *f_thread1()
{

    printf("\n\n\nje suis dans le thread *1*");
    pthread_exit(NULL);
}

void *f_thread2()
{
    printf("\n");

    for (int j = 0; j < 10; j++)
    {
        printf("T[%d]=%d \n", j+1, Tab[j]);
    }
    sleep(3);
    pthread_exit(NULL);
}

int main()
{
    pthread_t tr1, tr2;

    printf("\n donner moi les elements du tableau \n");

    for (int i = 0; i < 10; i++)
    {
        printf("T[%d]=", i + 1);
        scanf("%d", &Tab[i]);
    }

    pthread_create(&tr1, NULL, f_thread1, NULL);
    pthread_create(&tr2, NULL, f_thread2, NULL);
    pthread_join(tr1, NULL);
    pthread_join(tr2, NULL);

    return 0;
}