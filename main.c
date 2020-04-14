#include <stdio.h>
#include <stdlib.h>
#define ZERO 1e-6

struct VECTOR  //��¼����ľ���ٶȵĶ�Ԫ��
{
    long double v1;
    long double v2;
};

struct VECTOR calculate(long double v1, long double v2, int n)//����һ����ײ����ٶ�
{
    struct VECTOR newVector;

    newVector.v1 = (long double)((n-1)*v1 + 2*v2)/(n+1);
    newVector.v2 = (long double)((1-n)*v2 + 2*n*v1)/(n+1);

    return newVector;
}

void handleCrash(struct VECTOR verb, int n)
{
    int count = 0;

    while(1)
    {
        /**��һ�νӴ������*/
        if(verb.v1 > 0 && verb.v2 == 0)
        {
            verb = calculate(verb.v1, verb.v2, n);
            count++;
        }

        /**ͬʱ��ǽ�ڷ�������*/
        if(verb.v1 < 0 && verb.v2 < 0)
        {
            /**��Ҳ׷������*/
            if(verb.v1 - verb.v2 <= ZERO)
            {
                printf("When n = %ld, the times they will crash is %d\n", n, count);
                return;
            }

            /**����׷��׷��ʱ*/
            else
            {
                verb = calculate(verb.v1, verb.v2, n);
                count++;
            }
        }
        /**ͬʱ��ǽ�ڷ�����*/
        if(verb.v1 > 0 && verb.v2 > 0)
        {
            verb.v2 = -verb.v2;
            count++;                 //���������ֻ�п�����Сľ��ײǽ���������ٺʹ�ľ������
        }

        /**�Գ�����*/
        if(verb.v1 > 0 && verb.v2 < 0)
        {
            verb = calculate(verb.v1, verb.v2, n);
            count++;
        }

        /**��������*/
        if(verb.v1 < 0 && verb.v2 > 0)
        {
            verb.v2 = -verb.v2;
            count++;                 //v2����
        }

    }

}



int main()
{
    long long n = 100;
    struct VECTOR verb;

    for(; n <= 100e7; n*=100)
    {
        verb.v1 = 1;
        verb.v2 = 0;
        handleCrash(verb, n);
    }

    return 0;
}
