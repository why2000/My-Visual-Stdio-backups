//#define NOW
#ifdef NOW
#include<stdio.h>
#define M 10
#define N 3
int main(void)
{
    int a[M], b[M];	/* ����a���Ȧ���˵ı�ţ�����b��ų�Ȧ�˵ı�� */
    int i, j, k;
    for (i = 0; i < M; i++)	/* ��Ȧ���˰�˳����1��M */
        a[i] = i;
    stru[0] = 10;
    for (i = M, j = 0; i > 0; i--) {
        /* i��ʾȦ���˸�������ʼΪM����ʣ1����ʱ����ѭ����
        j��ʾ��ǰ�����˵�λ��    */
        for (k = 1; k <= N; k++) {	/* 1��N���� */
            if ((stru[++j]) == 0) {
                --k;
                continue;
            }
            if (j > 9) {
                j = 0;

            }
        }
             /* ���һ���˱������һ�����ű����γ�һ��Ȧ */
        b[M - i] = stru[j];	/* ������ΪN���˵ı�Ŵ�������b */
        if (i != 1)
            stru[j] = 0;
    }
    for (i = 0; i < M; i++)		/* �����������Ȧ�˵ı�� */
        printf(" % 6d", b[i]);
    return 0;
}

#endif
