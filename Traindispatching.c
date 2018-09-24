//This is the 1st version of Train Dispatching Problem.
//Developed by Xu And Xie jointly.

#include <stdio.h>
#include <conio.h>

int a[101], c[101][101];
int BFF, n;

void Print(int now) //打印当前出队车辆ID
{
    printf("%d", now);
}

int Popout(int a_top, int b_end)
{
    a[0] = a_top;
    if (b_end == n + 1) //如果已经全部出站，则退出。
    {
        return 0;
    }
    int minbff = 1000, minnow = -1;
    if (BFF > 0) //判断每一个缓冲车站是否需要出站
    {
        for (int i = 1; i <= BFF; i++)
        {
            if (c[i][0] == 0)
            {
                minbff = 1000;
                minnow = i;
            }
            
            if ((a[a[0]] < c[i][c[i][0]]) && (c[i][c[i][0]] - a[a[0]] < minbff))
            {
                minbff = c[i][c[i][0]] - a[a[0]];
                minnow = i;
            }

            if (c[i][c[i][0]] == b_end)
            {
                Print(c[i][c[i][0]]);
                c[i][0]--;
                Popout(a[0], b_end + 1);
                return b_end;
            }
        }
    }
    if (a[a[0]] == b_end)
    {
        Print(a[a[0]]);
        Popout(a[0] + 1, b_end + 1);
        return b_end;
    }

    if (minnow == -1)
    {
        BFF++;
        c[BFF][0] = 1;
        c[BFF][c[BFF][0]] = a[a[0]];
        Popout(a[0] + 1, b_end);
        return b_end;
    }

    c[minnow][0]++;
    c[minnow][c[minnow][0]] = a[a[0]];
    Popout(a[0] + 1, b_end);
    return b_end;
}

int main(void)
{
    int garbage;
    while (scanf("%d", &n) != -1)
    {

        a[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        BFF = 0;
        garbage = Popout(1, 1);
        printf("\nBFF = %d\n", BFF);
    }
    getch();
    return 0;
}