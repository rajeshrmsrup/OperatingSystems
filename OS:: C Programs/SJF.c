//Program to implement SJF scheduling algorithm for same or random Arrival Time.
#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int mt[n][7], tmt[n][7], i, j, k, at_cnt=0, cnt=1, cnt_size=0, x, y, z;
    float tat_Sum=0, wt_Sum=0;

    printf("---Enter the ID or number of each process---\n");
    for(i=0; i<n; i++)
        scanf("%d", &mt[i][0]);

    printf("\n---Enter the Arrival Time of each process---\n");
    for(i=0; i<n; i++)
        scanf("%d", &mt[i][1]);

    printf("\n---Enter the Burst Time of each process---\n");
    for(i=0; i<n; i++)
        scanf("%d", &mt[i][2]);

    //AT counter(if values of AT are 0)
    for(i=0; i<n; i++){
        if(mt[i][1]==0)
            at_cnt++;
    }

    //Sorting based on AT(if values of AT are not 0) & BT(if values of AT are 0)
    if(at_cnt==0 || at_cnt<n){
        //Sorting based on AT
        for(i=0; i<n-1; i++){
            for(j=0; j<n-i-1; j++){
                if(mt[j][1]>mt[j+1][1]){
                    for(k=0; k<=6; k++){
                        int tmp = mt[j][k];
                        mt[j][k] = mt[j+1][k];
                        mt[j+1][k] = tmp;
                    }
                }
            }
        }
    }
    else{
        //Sorting based on BT
        for(i=0; i<n-1; i++){
            for(j=0; j<n-i-1; j++){
                if(mt[j][2]>mt[j+1][2]){
                    for(k=0; k<=6; k++){
                        int tmp = mt[j][k];
                        mt[j][k] = mt[j+1][k];
                        mt[j+1][k] = tmp;
                    }
                }
            }
        }
    }

    //Computation for 1st row.
    mt[0][3] = mt[0][1];
    mt[0][4] = mt[0][3] + mt[0][2];
    mt[0][5] = mt[0][4] - mt[0][1];
    mt[0][6] = mt[0][5] - mt[0][2];

    //Main Logic
    for(i=1; i<n; i++){
        for(j=i; j<n; j++){
            if(mt[j][1] <= mt[i-1][4]){
                cnt_size++;
                for(k=0; k<7; k++){
                    tmt[j][k] = mt[j][k];
                }
            }
        }
        cnt_size = cnt_size-cnt;
        if(i<n-1 && cnt_size<=n-1){
            for(x=i; x<=cnt_size; x++){
                for(y=i; y<=cnt_size; y++){
                    if(tmt[y][2] > tmt[y+1][2]){
                        for(z=0; z<7; z++){
                            int tmp1 = tmt[y][z];
                            tmt[y][z] = tmt[y+1][z];
                            mt[y][z] = tmt[y][z];

                            tmt[y+1][z] = tmp1;
                            mt[y+1][z] = tmt[y+1][z];
                        }
                    }
                }
            }
        }
        if(mt[i][1] > mt[i-1][4])
            mt[i][3] = mt[i][1];
        else
            mt[i][3] = mt[i-1][4];
        mt[i][4] = mt[i][3] + mt[i][2];
        mt[i][5] = mt[i][4] - mt[i][1];
        mt[i][6] = mt[i][5] - mt[i][2];
        cnt_size--;
        cnt=cnt_size;
    }

    //ATAT & AWT computation
    for(i=0; i<n; i++){
        tat_Sum += mt[i][5];
        wt_Sum += mt[i][6];
    }

    printf("\nPID\tAT\tBT\ts_Time\te_Time\tTAT\tWT\n");
    printf("--------------------------------------------------\n");
    for(i=0; i<n; i++){
        for(j=0; j<7; j++)
            printf("%d\t", mt[i][j]);
        printf("\n");
    }
    printf("--------------------------------------------------\n");

    printf("\nAverage Turn Around Time = %f", tat_Sum/n);
    printf("\nAverage Waiting Time = %f\n", wt_Sum/n);
}
/********************OUTPUT********************
Enter the number of processes: 5
---Enter the ID or number of each process---
1
2
3
4
5

---Enter the Arrival Time of each process---
2
5
1
0
4

---Enter the Burst Time of each process---
6
2
8
3
4

PID	AT	BT	s_Time	e_Time	TAT	WT
----------------------------------
4	0	3	0	    3	    3	0
1	2	6	3	    9	    7	1
2	5	2	9	    11	    6	4
5	4	4	11	    15	    11	7
3	1	8	15	    23	    22	14
----------------------------------

Average Turn Around Time = 9.800000
Average Waiting Time = 5.200000

***********************************************/
