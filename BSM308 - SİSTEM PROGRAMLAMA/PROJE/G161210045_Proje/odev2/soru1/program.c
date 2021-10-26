#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "program.h"
#include <time.h>

int main(int narg, char *argv[])
{
        srand(time(NULL));
        char type;
        type = argv[3][0];

        int bir, iki = 0;
        char row[10];
        char col[10];

        char maxs[10];
        char mins[10];
        int rows = 0;
        int cols = 0;

        int max;
        int min;
        FILE *matristxt = fopen("soru1.txt", "w");
        FILE *transpoztxt = fopen("soru1-transpoze.txt", "w");

        int i, j;
        int **matrix;
        float **matrixl;
        double **matrixd;
        if (narg >= 4 && narg <= 5)
        {

                //----------------------
                for (bir = 0; bir < strlen(argv[1]); bir++)
                {
                        row[bir] = argv[1][bir];
                        if ((argv[1][bir] == 'x'))
                                break;
                }
                row[bir] = '\0';
                rows = atoi(row);
                for (bir += 1; bir < strlen(argv[1]); bir++)
                {
                        col[iki++] = argv[1][bir];
                }
                col[iki] = '\0';
                cols = atoi(col);
                //------------------------------------------
                for (bir = 0; bir < strlen(argv[2]); bir++)
                {
                        mins[bir] = argv[2][bir];
                        if ((argv[2][bir] == '-'))
                                break;
                }
                mins[bir] = '\0';
                min = atoi(mins);
                iki = 0;
                for (bir += 1; bir < strlen(argv[2]); bir++)
                {
                        maxs[iki++] = argv[2][bir];
                }
                maxs[iki] = '\0';
                max = atoi(maxs);
                if ((rows != 0 && cols != 0) && max > min)
                {
                        switch (type)
                        {
                        case 'i':
                                matrix = (int **)malloc(rows * cols * sizeof(int));
                                for (i = 0; i < rows; i++)
                                {
                                        matrix[i] = (int *)malloc(cols * sizeof(int));
                                }
                                for (j = 0; j < rows; j++)
                                {
                                        for (i = 0; i < cols; i++)
                                        {
                                                matrix[j][i] = (rand() % (max - min + 1)) + min;
                                        }
                                }

                                printf("............Matris............ \n");
                                for (j = 0; j < rows; j++)
                                {
                                        for (i = 0; i < cols; i++)
                                        {
                                                printf("%d ", matrix[j][i]);
                                                fprintf(matristxt, "%d ", matrix[j][i]);
                                        }
                                        printf("\n");
                                        fprintf(matristxt, "\n");
                                }
                                //-----------------------Transpoz
                                if (narg == 5 && !strcmp(argv[4], "-t"))
                                {
                                        printf(".............Transpoz........... \n");
                                        for (j = 0; j < cols; j++)
                                        {
                                                for (i = 0; i < rows; i++)
                                                {
                                                        printf("%d ", matrix[i][j]);
                                                        fprintf(transpoztxt, "%d ", matrix[i][j]);
                                                }
                                                printf("\n");
                                                fprintf(transpoztxt, "\n");
                                        }
                                }
                                break;
                        case 'f':
                                matrixl = (float **)malloc(rows * cols * sizeof(float));
                                for (i = 0; i < rows; i++)
                                {
                                        matrixl[i] = (float *)malloc(cols * sizeof(float));
                                }
                                for (j = 0; j < rows; j++)
                                {
                                        for (i = 0; i < cols; i++)
                                        {
                                                matrixl[j][i] = ((float)rand() / RAND_MAX) * (max - min) + min;
                                        }
                                }

                                printf("............Matris............ \n");
                                for (j = 0; j < rows; j++)
                                {
                                        for (i = 0; i < cols; i++)
                                        {
                                                printf("%f ", matrixl[j][i]);
                                                fprintf(matristxt, "%f ", matrixl[j][i]);
                                        }
                                        printf("\n");
                                        fprintf(matristxt, "\n");
                                }
                                if (narg == 5 && !strcmp(argv[4], "-t"))
                                {
                                        printf(".............Transpoz........... \n");
                                        for (j = 0; j < cols; j++)
                                        {
                                                for (i = 0; i < rows; i++)
                                                {
                                                        printf("%f ", matrixl[i][j]);
                                                        fprintf(transpoztxt, "%f ", matrixl[i][j]);
                                                }
                                                printf("\n");
                                                fprintf(transpoztxt, "\n");
                                        }
                                }
                                break;
                        case 'd':
                                matrixd = (double **)malloc(rows * cols * sizeof(double));
                                for (i = 0; i < rows; i++)
                                {
                                        matrixd[i] = (double *)malloc(cols * sizeof(double));
                                }
                                for (j = 0; j < rows; j++)
                                {
                                        for (i = 0; i < cols; i++)
                                        {
                                                matrixd[j][i] = ((double)rand() / RAND_MAX) * (max - min) + min;
                                        }
                                }

                                printf("............Matris............ \n");
                                for (j = 0; j < rows; j++)
                                {
                                        for (i = 0; i < cols; i++)
                                        {
                                                printf("%lf ", matrixd[j][i]);
                                                fprintf(matristxt, "%lf ", matrixd[j][i]);
                                        }
                                        printf("\n");
                                        fprintf(matristxt, "\n");
                                }
                                if (narg == 5 && !strcmp(argv[4], "-t"))
                                {
                                        printf(".............Transpoz........... \n");
                                        for (j = 0; j < cols; j++)
                                        {
                                                for (i = 0; i < rows; i++)
                                                {
                                                        printf("%lf ", matrixd[i][j]);
                                                        fprintf(transpoztxt, "%lf ", matrixd[i][j]);
                                                }
                                                printf("\n");
                                                fprintf(transpoztxt, "\n");
                                        }
                                }
                                break;

                        default:
                                printf("Type i,f,d degerleri olabilir. Lutfen kontrol ediniz.");
                                break;
                        }
                }
                else
                {
                        printf("Argumanlari kontrol ediniz");
                }
        }
}
