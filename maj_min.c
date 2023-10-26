// #include <bits/pthreadtypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread1_f()
{ // la fonction du premier thread

    for (char i = 'A'; i <= 'Z'; i++)
    {
        printf("%c\t", i);
    }
    sleep(2);
    pthread_exit(NULL);
}
void *thread2_f()
{ // la fonction du deuxieme thread
    printf("\n\n\n\n");
    for (char i = 'a'; i <= 'z'; i++)
    {
        printf("%c\t", i);
    }
    printf("\n");
    sleep(4);
    pthread_exit(NULL);
}

int main()
{

    pthread_t thr1, thr2; // pour cree des nouveaux thread

    pthread_create(&thr1, NULL, thread1_f, NULL);
    pthread_create(&thr2, NULL, thread2_f, NULL);

    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);

    return 0;
}