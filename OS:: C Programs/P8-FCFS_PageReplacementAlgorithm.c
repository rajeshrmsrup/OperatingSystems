//Program to implement FCFS Page replacement Algorithm.
#include<stdio.h>
int main()
{
    int n, i, j, p_Flts=0, frms;
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int r_Str[n];
    printf("---Enter the values of reference string---\n");
    for(i=0; i<n; i++)
        scanf("%d", &r_Str[i]);

    printf("\nEnter the number of frames: ");
    scanf("%d", &frms);

    int temp[frms], mt[n][frms];
    for(i=0; i<frms; i++)
        temp[i] = -1;

    for(i=0; i<n; i++){
        int f = 0;
        for(j=0; j<frms; j++){
            if(r_Str[i] == temp[j]){
                f++;
                p_Flts--;
            }
        }
        p_Flts++;
        if((p_Flts <= frms) && (f == 0))
            temp[i] = r_Str[i];
        else if(f == 0)
            temp[(p_Flts - 1) % frms] = r_Str[i];

        for(j=0; j<frms; j++)
            mt[i][j] = temp[j];
    }

    printf("\n\t---Result---\n");
    for(i=0; i<n; i++)
        printf("  %d\t", r_Str[i]);
    printf("\n");
    for(i=frms-1; i>=0; i--){
        for(j=0; j<n; j++){
            if(mt[j][i] < 0)
                printf("|%d|\t", mt[j][i]);
            else
                printf("| %d|\t", mt[j][i]);
        }
        printf("\n");
    }

    printf("\n\nTotal Page Faults: %d\n", p_Flts);
    printf("Total number of Hit = %d\n", n-p_Flts);
}
/********************OUTPUT********************
Enter the number of pages: 10
---Enter the values of reference string---
4
7
6
1
7
6
1
2
7
2

Enter the number of frames: 3

	---Result---
  4	  7	  6	  1	  7	  6	  1	  2	  7	  2
|-1|	|-1|	| 6|	| 6|	| 6|	| 6|	| 6|	| 6|	| 7|	| 7|
|-1|	| 7|	| 7|	| 7|	| 7|	| 7|	| 7|	| 2|	| 2|	| 2|
| 4|	| 4|	| 4|	| 1|	| 1|	| 1|	| 1|	| 1|	| 1|	| 1|

Total Page Faults: 6
Total number of Hit = 4

***********************************************/
