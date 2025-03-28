#include<stdio.h> #include<conio.h>  
#define MAX 10  
void main(){ 
    char ele[MAX][MAX]; 
    int w[MAX][MAX], c[MAX][MAX], r[MAX][MAX], p[MAX], q[MAX]; 
    int temp=0, root, min, min1, n; int i,j,k,b; 
    clrscr(); 
    printf("Enter the number of elements:");scanf("%d",&n);printf("\n"); 
    for(i=1; i <= n; i++){ 
        printf("Enter the Element of %d:",i); scanf("%d",&p[i]); 
    }    printf("\n");  
    for(i=0; i <= n; i++){ 
        printf("Enter the Probability of %d:",i); scanf("%d",&q[i]);  
    } 
    printf("W\t\tC\t\tR\n");  
    for(i=0; i <= n; i++){ 
        for(j=0; j <= n; j++){ 
            if(i == j){ 
                w[i][j] = q[i]; 
                c[i][j] = 0; 
                r[i][j] = 0; 
                printf("W[%d][%d]: %d\tC[%d][%d]: %d\tR[%d][%d]: 
                %d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]);  
            } 
        } 
    }  
    printf("\n"); 
    for(b=0; b < n; b++){ 
        for(i=0,j=b+1; j < n+1 && i < n+1; j++,i++){ 
            if(i!=j && i < j){ 
                w[i][j] = p[j] + q[j] + w[i][j-1];  
                min = 30000; 
                for(k = i+1; k <= j; k++){ 
                    min1 = c[i][k-1] + c[k][j] + w[i][j];  
                    if(min > min1){ 
                        min = min1; 
                        temp = k; 
                    } 
                }  
                c[i][j] = min; 
                r[i][j] = temp; 
            } 
            printf("W[%d][%d]: %d\tC[%d][%d]: %d\tR[%d][%d]:%d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]); 
        } 
        printf("\n");    
    } 
    printf("Minimum cost = %d\n",c[0][n]); root = r[0][n]; 
    printf("Root = %d \n",root); getch(); 
}

/*Enter the number of elements:3

Enter the Element of 1:1
Enter the Element of 2:6
Enter the Element of 3:2

Enter the Probability of 0:1
Enter the Probability of 1:5
Enter the Probability of 2:2
Enter the Probability of 3:4
W		C		R
W[0][0]: 1	C[0][0]: 0	R[0][0]:0
W[1][1]: 5	C[1][1]: 0	R[1][1]:0
W[2][2]: 2	C[2][2]: 0	R[2][2]:0
W[3][3]: 4	C[3][3]: 0	R[3][3]:0

W[0][1]: 7	C[0][1]: 7	R[0][1]:1
W[1][2]: 13	C[1][2]: 13	R[1][2]:2
W[2][3]: 8	C[2][3]: 8	R[2][3]:3

W[0][2]: 15	C[0][2]: 22	R[0][2]:2
W[1][3]: 19	C[1][3]: 27	R[1][3]:2

W[0][3]: 21	C[0][3]: 36	R[0][3]:2

Minimum cost = 36
Root = 2*/
