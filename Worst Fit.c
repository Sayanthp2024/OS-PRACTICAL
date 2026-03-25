#include<stdio.h>
void main()
{
int bsize[20], psize[20], all[20], m, n, i, j;

printf("Enter the number of Blocks: ");  
scanf("%d", &m);  
printf("Enter the size of each block: ");  
for(i = 0; i < m; i++)  
    scanf("%d", &bsize[i]);  
      
printf("Enter the number of process: ");  
scanf("%d", &n);  
printf("Enter the size of each process: ");  
for(i = 0; i < n; i++) {  
    scanf("%d", &psize[i]);  
    all[i] = -1;  
}  

for(i = 0; i < n; i++) {  
    int worstplace = -1;  
    for(j = 0; j < m; j++) {  
        if(bsize[j] >= psize[i]) {  
            if(worstplace == -1)  
                worstplace = j;  
            else if (bsize[worstplace] < bsize[j])  
                worstplace = j;  
        }  
    }  
    if(worstplace != -1) {  
        all[i] = worstplace;  
        bsize[worstplace] -= psize[i];  
    }  
}  

printf("\nProcess No.\tProcess Size\tBlock no.\n");  
for (int i = 0; i < n; i++) {  
    printf(" %d\t\t%d\t\t", i + 1, psize[i]);  
    if (all[i] != -1)  
        printf("%d\n", all[i] + 1);  
    else  
        printf("Not Allocated\n");  
}

}