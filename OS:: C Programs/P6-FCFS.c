#include<stdio.h>
int main(){
    int n, i, j, k;
    float tat_Sum=0, wt_Sum=0;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    int mt[n][10];
    printf("---Enter the number of each process---\n");
    for(i=0; i<n; i++)
        scanf("%d", &mt[i][0]);

    printf("\n---Enter Arrival Time of each process---\n");
    for(i=0; i<n; i++)
        scanf("%d", &mt[i][1]);

    printf("\n---Enter Burst Time of each process---\n");
    for(i=0; i<n; i++)
        scanf("%d", &mt[i][2]);

    //sorting
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(mt[i][1]>mt[j][1]){
                for(k=0; k<=6; k++){
                    int tmp = mt[j][k];
                    mt[j][k] = mt[i][k];
                    mt[i][k] = tmp;
                }
            }
        }
    }

    mt[0][3] = mt[0][1];
    mt[0][4] = mt[0][3] + mt[0][2];
    for(i=0; i<n; i++){
        if(i != 0){
            if(mt[i][1] > mt[i-1][4])
                mt[i][3] = mt[i][1];
            else
                mt[i][3] = mt[i-1][4];

        mt[i][4] = mt[i][3] + mt[i][2];
        }
        mt[i][5] = mt[i][4] - mt[i][1];
        tat_Sum += mt[i][5];

        mt[i][6] = mt[i][5] - mt[i][2];
        wt_Sum += mt[i][6];
    }

    printf("\nPID\tAT\tBT\ts_Time\te_Time\tTAT\tWT\n");
    printf("--------------------------------------------------\n");
    for(i=0; i<n; i++){
        for(j=0; j<=6; j++)
            printf("%d\t", mt[i][j]);
        printf("\n");
    }
    printf("--------------------------------------------------\n");

    printf("\nAverage Turn Around Time = %f", tat_Sum/n);
    printf("\nAverage Waiting Time = %f\n", wt_Sum/n);
}
