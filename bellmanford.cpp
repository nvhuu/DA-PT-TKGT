#include <stdio.h>
#include <stdlib.h>
#define INP "input.inp"
#define OUT "output.out"

int main() {
    FILE *fi = fopen(INP, "r");
    FILE *fo = fopen(OUT, "w");
    int n, s, t, i, sum = 0; 
    // nhap du lieu tu file input
    fscanf(fi, "%d%d%d", &n, &s, &t);
    int A[n][n];
    int Truoc[n], d[n];
  
    // nhap ma tran va tinh gia tri vo cung (sum)
    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            fscanf(fi, "%d", &A[i][j]);
           sum += A[i][j];
        }
    // dat vo cung cho tat ca cap canh khong noi voi nhau
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && A[i][j] == 0)
                A[i][j] = sum;}
                				}
    /* Do mang tinh tu A[0][0] nen can giam vi tri
     di 1 don vi de tinh toan cho phu hop*/
    s--; t--;   
    for (int v=0; v<n; v++){
        d[v] = (A[s][v] != 0)? A[s][v] : sum;
        Truoc[v] = s;
        }
    d[s] = 0;
    for (int k=0; k<n; k++)
        for (int v=1; v<n; v++)
            for (int u=1; v!=s && u<n; u++)
                if (d[v] > d[u]+A[u][v] ) {
                    d[v] = d[u] + A[u][v];
					Truoc[v] = u;
								}
	int ds[n], m = 0;
    ds[m]=t;
    while(ds[m]!=s) {
    	m++;
    	ds[m]=Truoc[ds[m-1]];
		}
    fprintf(fo,"%d\n",m+1);
    for ( int i=m; i>=0; i-- )
                fprintf(fo,"%d ",ds[i]+1);
    fclose(fi);
    fclose(fo);
    return 0;
    }
