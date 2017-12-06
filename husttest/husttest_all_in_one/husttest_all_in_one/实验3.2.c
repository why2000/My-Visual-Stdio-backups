//#define NOW
#ifdef NOW
#include<stdio.h>
#include<math.h>

int checkprime(int num);
void search(int begin, int end, int* prime);
void calprime(int* prime, int max);

int main(void) {

    int begin, end;
    while ((scanf("%d %d", &begin, &end), begin) != 0) {
        int len = end - 1;
        int *prime = (int*)calloc(len, sizeof(int));
        printf("GOLDBACH'S CONJECTURE:\n"
                "Every even number n >= 4 is the sum of two primes.\n");
        calprime(prime, len);
        if (begin % 2) {
            search(begin + 1, end, prime);
            printf("\n");
        }
        else {
            search(begin, end, prime);
            printf("\n");
        }
        free(prime);
        prime = NULL;
    }

    return 0;
}

int checkprime(int num) {
    int i = 2;
    for (i = 2; i <= (int)sqrt(num); i++) {
        if (!(num%i)) {
            return 0;
        }
    }
    return 1;
}

void calprime(int* prime, int max) {
    prime[0] = 2;
    int i = 0;
    int j = 1;
    for (i = 3; i < max + 1; i++) {
        if (checkprime(i)) {
            prime[j] = i;
            j++;
        }
    }
}

void search(int begin, int end, int* prime) {
    int now = begin;
    int flag = 0;
    for (now = begin; now <= end; now += 2) {
        int i = 0, j = 0;
        flag = 0;
        int len = end / 2 + 1;
        for (i = 0; i < len; i++) {
            if (prime[i] == 0) {
                printf("Error!!!!!!!\n");
                break;
            }
            int dec = now - prime[i];
            for (j = 0; j < end; j++) {
                if ((dec == prime[j]) && (prime[j] != 0)) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                printf("%d=%d+%d\n", now, prime[i], dec);
                break;
            }
        }
    }
}

#endif
