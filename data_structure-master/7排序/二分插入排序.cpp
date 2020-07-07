#include <stdio.h>

// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�

int main()
{
    int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// ��С������ֲ�������
    int n = sizeof(A) / sizeof(int);
    int i, j, get, left, right, middle;
    
    for (i = 1; i < n; i++)                 // ����ץ�˿�������
    {
        get = A[i];                         // ����ץ��һ���˿���
        left = 0;                           // ���������ϵ�����������õ�,���Կ����ö��ַ�
        right = i - 1;                      // �������ұ߽���г�ʼ��
        while (left <= right)               // ���ö��ַ���λ���Ƶ�λ��
        {
            middle = (left + right) / 2;
            if (A[middle] > get)
                right = middle - 1;
            else
                left = middle + 1;
        }
        for (j = i - 1; j >= left; j--)    // ������������λ���ұߵ������������ƶ�һ����λ
        {
            A[j + 1] = A[j];            
        }
        A[left] = get;                    // ��ץ�����Ʋ�������
    }
    printf("���ֲ�����������");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
