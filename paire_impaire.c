
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

int nombre;

pthread_mutex_t mutex;

void *f_thread1()
{

    if (nombre % 2 == 0)
    {
        printf("\nle nombre est paire \n");
    }
    else
    {
        printf("\nle nombre est impaire \n");
    }
    sleep(2);

    pthread_exit(NULL);
}
void *f_thread2()
{

    printf("\n La racine Caree du votre nombre est : %f", sqrt(nombre));
    sleep(2);
    pthread_exit(NULL);
}
void *f_thread3()
{
    printf("\n les diviseur du nombre %d est : \n", nombre);
    for (int i = 1; i <= sqrt(nombre); i++)
    {

        if (nombre % i == 0)
        {
            printf("%d,", i);
        }
    }

    sleep(2);
    pthread_exit(NULL);
}
int main()
{
    printf("\nDonner moi un nombre pour le tester ? :");
    scanf("%d", &nombre);
    pthread_t thr1, thr2, thr3;

    pthread_create(&thr1, NULL, f_thread1, NULL);
    pthread_create(&thr2, NULL, f_thread2, NULL);
    pthread_create(&thr3, NULL, f_thread3, NULL);

    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);
    pthread_join(thr3, NULL);

    return 0;
}