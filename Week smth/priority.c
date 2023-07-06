
// Priority CPU Scheduling
#include <stdio.h>
struct priority
{
    int burst, wait, no, priority;
} p[20];
int main()
{
    int n, i, j, totalwait = 0, totalturn = 0;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Burst Time For Process #%2d : ", i + 1);
        scanf("%d", &p[i].burst);
        printf("Enter The Priority For Process #%2d : ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].no = i + 1;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (p[j].priority > p[j + 1].priority)
            {
                p[j].burst ^= p[j + 1].burst ^= p[j].burst ^= p[j + 1].burst;
                p[j].no ^= p[j + 1].no ^= p[j].no ^= p[j + 1].no;
                p[j].priority ^= p[j + 1].priority ^= p[j].priority ^= p[j + 1].priority;
            }
    printf("\nProcess \t Starting\tEnding\tWaiting\tTurnAround ");
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("\nProcess # %-11d%-10d%-10d%-10d%10d", p[i].no, p[i].wait, p[i].wait + p[i].burst, p[i].wait, p[i].wait + p[i].burst);
        p[i + 1].wait = p[i].wait + p[i].burst;
        totalwait = totalwait + p[i].wait;
        totalturn = totalturn + p[i].wait + p[i].burst;
    }
    printf("\n\nAverage\n---------");
    printf("\nWaiting Time : %f ms", totalwait / (float)n);
    printf("\nTurnAround Time : %f ms\n\n", totalturn / (float)n);
    return 0;
}
