#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <locale.h>
#define SIZE 4

int main()
{
    setlocale(LC_ALL, "Rus");
    int izm[SIZE] = { 0 }; //������������� ����� � ���� ����
    int resh[SIZE - 1] = { 0 }; //����� � 10��
    int atwo[9] = { 0 };
    int btwo[9] = { 0 };
    int ctwo[9] = { 0 };
    int dtwo[9] = { 0 };
    int etwo[9] = { 0 };
    int ytwo[9] = { 0 };
    int q = 2;
    int fl = 0, al = 0, bl = 0, cl = 0, dl = 0, el = 0, yl;
    int f10 = 0, a10 = 0, b10 = 0, c10 = 0, d10 = 0, e10 = 0, y10;
    char A[SIZE] = "+84", B[SIZE] = "-21", C[SIZE] = "-12", D[SIZE] = "+22", E[SIZE] = "+10";
    int f = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int y;
    int f10 = 0;
    int a10 = 0;
    int b10 = 0;
    int c10 = 0;
    int d10 = 0;
    int e10 = 0;
    int y10;
    //���������� �����
    char A[SIZE] = "+84"; 
    char B[SIZE] = "-21";
    char C[SIZE] = "-12";
    char D[SIZE] = "+22";
    char E[SIZE] = "+10";
    printf("�������: y=a/b*c-d+e");

    _asm
    {
        jmp START

        FUNC :



            pop eax
            //mov eax, [ebp + 8 + 4 * 4]
            pop ebx
            //mov ebx, [ebp + 8 + 4 * 3]
            cdq
            idiv ebx
            pop ebx
            //mov ebx, [ebp + 8 + 4 * 2]
            imul ebx
            pop ebx
            //mov ebx, [ebp + 8 + 4 * 1]
            sub eax, ebx
            pop ebx
            //mov ebx, [ebp + 8 + 4 * 0]
            add eax, ebx

            ret

            //�� ������ ���� � ����������
            TO_AS�II :
        push ebx
            mov f, 0
            //� ����
            mov ecx, SIZE-1
            xor edx, edx
            V_AS�II :
        movzx eax, [ebx + edx]
            mov[izm + 4 * edx], eax
            add edx, 1
            LOOP V_AS�II
            //� ����� 10��
            mov ecx, SIZE-1
            sub ecx, 1
            xor edx, edx
            VMASSIV :
        mov eax, [izm + 4 * edx + 4]
            sub eax, 48
            mov[resh + 4 * edx], eax
            add edx, 1
            LOOP VMASSIV
            //� ����������
            mov ecx, SIZE-1
            sub ecx, 1
            xor edx, edx
            PEREM :
        mov eax, 1
            mov ebx, ecx
            sub ecx, 1
            cmp ecx, 0
            je NOL
            DESET :
        imul eax, 10
            LOOP DESET
            NOL :
        push eax  //�� ������� ��������
            mov ecx, ebx
            mov eax, [resh + 4 * edx]
            pop ebx
            imul eax, ebx
            add f, eax
            add edx, 1
            LOOP PEREM
            mov eax, f
            //����������� �����
            cmp[izm], 45
            jne NE_MINUSOM
            neg eax
            NE_MINUSOM :
        pop ebx
            ret

            AS�BIN :
        //������� �� 2��
        push ebx
            mov eax, f
            xor edx, edx
            add ebx, 32
            VO_TWO2 :
            cdq
            idiv q
            mov[ebx], dl
            sub ebx, 4
            xor edx, edx
            cmp eax, 0
            jne VO_TWO2
            pop ebx
            cmp[izm], 45
            jne NE_MINUS
            mov[ebx], '-'
            jmp EXT
            NE_MINUS :
        mov[ebx], '+'
            EXT :
            ret

            BINAS� :
        //������� � 10��
        mov f10, 0
            mov ecx, 8
            V_DEC :
            mov edx, [ebx + 4]
            mov eax, ecx
            sub ecx, 1
            cmp ecx, 0
            je VOZR
            STEPEN :
        imul edx, 2
            LOOP STEPEN
            VOZR :
        mov ecx, eax
            add f10, edx
            add ebx, 4
            LOOP V_DEC
            mov eax, f10
            ret


            START :

        lea ebx, A
            call TO_AS�II
            mov a, eax
            lea ebx, atwo
            call AS�BIN
            call BINAS�
            mov a10, eax

            lea ebx, B
            call TO_AS�II
            mov b, eax
            lea ebx, btwo
            call AS�BIN
            call BINAS�
            mov b10, eax

            lea ebx, C
            call TO_AS�II
            mov c, eax
            lea ebx, ctwo
            call AS�BIN
            call BINAS�
            mov c10, eax

            lea ebx, D
            call TO_AS�II
            mov d, eax
            lea ebx, dtwo
            call AS�BIN
            call BINAS�
            mov d10, eax

            lea ebx, E
            call TO_AS�II
            mov e, eax
            lea ebx, etwo
            call AS�BIN
            call BINAS�
            mov e10, eax

            //���������� �������
            push e
            push d
            push c
            push b
            push a

            call FUNC
            mov f, eax
            mov y, eax
            lea ebx, ytwo
            call AS�BIN
            call BINAS�
            mov y10, eax

      
    }

    printf("\na = %d", a);
    if (atwo[0] == 45)
    {
        printf("\na10 = -%d", a10);
    }
    else
    {
        printf("\na10 = %d", a10);
    }
    printf("\n����� �� 2��(nast): ");
    if (atwo[0] == 45)
    {
        printf("-");
    }
    else
    {
        printf("+");
    }
    for (int i = 1; i < 9; i++)
    {
        printf("%d ", atwo[i]);
    }

    printf("\nb = %d", b);
    if (btwo[0] == 45)
    {
        printf("\nb10 = -%d", b10);
    }
    else
    {
        printf("\nb10 = %d", b10);
    }
    printf("\n����� �� 2��(nast): ");
    if (btwo[0] == 45)
    {
        printf("-");
    }
    else
    {
        printf("+");
    }
    for (int i = 1; i < 9; i++)
    {
        printf("%d ", btwo[i]);
    }

    printf("\nc = %d", c);
    if (ctwo[0] == 45)
    {
        printf("\nc10 = -%d", c10);
    }
    else
    {
        printf("\nc10 = %d", c10);
    }
    printf("\n����� �� 2��(nast): ");
    if (ctwo[0] == 45)
    {
        printf("-");
    }
    else
    {
        printf("+");
    }
    for (int i = 1; i < 9; i++)
    {
        printf("%d ", ctwo[i]);
    }

    printf("\nd = %d", d);
    if (dtwo[0] == 45)
    {
        printf("\nd10 = -%d", d10);
    }
    else
    {
        printf("\nd10 = %d", d10);
    }
    printf("\n����� �� 2��(nast): ");
    if (dtwo[0] == 45)
    {
        printf("-");
    }
    else
    {
        printf("+");
    }
    for (int i = 1; i < 9; i++)
    {
        printf("%d ", dtwo[i]);
    }

    printf("\ne = %d", e);
    if (etwo[0] == 45)
    {
        printf("\ne10 = -%d", e10);
    }
    else
    {
        printf("\ne10 = %d", e10);
    }
    printf("\n����� �� 2��(nast): ");
    if (etwo[0] == 45)
    {
        printf("-");
    }
    else
    {
        printf("+");
    }
    for (int i = 1; i < 9; i++)
    {
        printf("%d ", etwo[i]);
    }

    printf("\ny = %d", y);
    if (ytwo[0] == 45)
    {
        printf("\ny10 = -%d", y10);
    }
    else
    {
        printf("\ny10 = %d", y10);
    }
    printf("\n����� �� 2��(nast): ");
    if (ytwo[0] == 45)
    {
        printf("-");
    }
    else
    {
        printf("+");
    }
    for (int i = 1; i < 9; i++)
    {
        printf("%d ", ytwo[i]);

    }

    getchar();
    return 0;
}
