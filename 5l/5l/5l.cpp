#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <locale.h>
#define SIZE 4

int main()
{
    setlocale(LC_ALL, "Rus");
    int izm[SIZE] = { 0 }; //представление числа в АСКИ коде
    int resh[SIZE - 1] = { 0 }; //число в 10сс
    int atwo[9] = { 0 };
    int btwo[9] = { 0 };
    int ctwo[9] = { 0 };
    int dtwo[9] = { 0 };
    int etwo[9] = { 0 };
    int ytwo[9] = { 0 };
    int q = 2;
    int f = 0, a = 0, b = 0, c = 0, d = 0, e = 0, y;
    int f10 = 0, a10 = 0, b10 = 0, c10 = 0, d10 = 0, e10 = 0, y10;
    char A[SIZE] = "+84", B[SIZE] = "-21", C[SIZE] = "-12", D[SIZE] = "+22", E[SIZE] = "+10";
    printf("Функция: y=a/b*c-d+e");

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

            //из строки АСКИ в переменную
            TO_ASСII :
        push ebx
            mov f, 0
            //В АСКИ
            mov ecx, SIZE-1
            xor edx, edx
            V_ASСII :
        movzx eax, [ebx + edx]
            mov[izm + 4 * edx], eax
            add edx, 1
            LOOP V_ASСII
            //В число 10сс
            mov ecx, SIZE-1
            sub ecx, 1
            xor edx, edx
            VMASSIV :
        mov eax, [izm + 4 * edx + 4]
            sub eax, 48
            mov[resh + 4 * edx], eax
            add edx, 1
            LOOP VMASSIV
            //В переменную
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
        push eax  //на сколько умножить
            mov ecx, ebx
            mov eax, [resh + 4 * edx]
            pop ebx
            imul eax, ebx
            add f, eax
            add edx, 1
            LOOP PEREM
            mov eax, f
            //Определение знака
            cmp[izm], 45
            jne NE_MINUSOM
            neg eax
            NE_MINUSOM :
        pop ebx
            ret

            ASСBIN :
        //Перевод во 2сс
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

            BINASС :
        //Перевод в 10сс
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
            call TO_ASСII
            mov a, eax
            lea ebx, atwo
            call ASСBIN
            call BINASС
            mov a10, eax

            lea ebx, B
            call TO_ASСII
            mov b, eax
            lea ebx, btwo
            call ASСBIN
            call BINASС
            mov b10, eax

            lea ebx, C
            call TO_ASСII
            mov c, eax
            lea ebx, ctwo
            call ASСBIN
            call BINASС
            mov c10, eax

            lea ebx, D
            call TO_ASСII
            mov d, eax
            lea ebx, dtwo
            call ASСBIN
            call BINASС
            mov d10, eax

            lea ebx, E
            call TO_ASСII
            mov e, eax
            lea ebx, etwo
            call ASСBIN
            call BINASС
            mov e10, eax

            //Вычисление функции
            push e
            push d
            push c
            push b
            push a

            call FUNC
            mov f, eax
            mov y, eax
            lea ebx, ytwo
            call ASСBIN
            call BINASС
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
    printf("\nЧисло во 2сс(nast): ");
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
    printf("\nЧисло во 2сс(nast): ");
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
    printf("\nЧисло во 2сс(nast): ");
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
    printf("\nЧисло во 2сс(nast): ");
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
    printf("\nЧисло во 2сс(nast): ");
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
    printf("\nЧисло во 2сс(nast): ");
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
