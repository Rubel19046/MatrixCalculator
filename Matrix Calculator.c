
#include<stdio.h>
int fun()
{
    int choice;
    printf("Press 1 for enter the matrix calculator.\n");
    printf("Press 0 for exit.\n");
    scanf("%d",&choice);
    return choice;
}
int main()
{
    while(1)
    {
        if(!fun())
            break;
        for(int i=0; i<10; i++)
            printf("\n");
        printf("\t\t\t\t<Welcome to matrix calculator>\n\n");
        getchar();
        printf("\tHow many matrices do you want to store for calculation in next = ");
        int num;
        scanf("%d",&num);
        printf("\n\tPlease input row and column number of these matrices = ");
        int row,col;
        scanf("%d%d",&row,&col);
        int matrix[num][row][col];
        for(int i=0; i<num; i++)
        {
            printf("\n\tPlease input %c matrix all elements\n",i+'A');
            for(int j=0; j<row; j++)
            {
                printf("\t");
                for(int k=0; k<col; k++)
                {
                    scanf("%d",&matrix[i][j][k]);
                }
            }
        }
        while(1)
        {
            printf("\n\tPlease input a valid expresion what you want to calculate = ");
            char str[100];
            scanf("%s",str);
            int len=strlen(str);
            int ans[row][col];
            int run_mat[row][col];
            //intialize whole array
            for(int i=0; i<row; i++)
            {
                for(int j=0; j<col; j++)
                {
                    ans[i][j]=0;
                }

            }
            char pr='+';
            str[len]='+';
            int chker=0;
            int first_operation=0;
            for(int i=0; i<=len; i++)
            {
                if(str[i]=='+' || str[i]=='-')
                {
                    first_operation++;
                    if(first_operation==1)
                    {
                        pr=str[i];
                        for(int ii=0; ii<row; ii++)
                        {
                            for(int jj=0; jj<col; jj++)
                            {

                                ans[ii][jj]=run_mat[ii][jj];
                                run_mat[ii][jj]=0;
                                //printf("%d ",ans[ii][jj]);
                            }
                            //  printf("\n");
                        }
                        chker=0;
                        continue;
                    }
                    chker=0;
                    if(pr=='+')
                    {
                        for(int j=0; j<row; j++)
                        {
                            for(int k=0; k<col; k++)
                            {
                                ans[j][k]=ans[j][k]+run_mat[j][k];
                            }
                        }
                    }
                    else
                    {
                        for(int j=0; j<row; j++)
                        {
                            for(int k=0; k<col; k++)
                            {
                                ans[j][k]=ans[j][k]-run_mat[j][k];
                            }
                        }
                    }
                    pr=str[i];
                    //Clear run matrix and initialized with zero
                    for(int j=0; j<row; j++)
                    {
                        for(int k=0; k<col; k++)
                        {
                            run_mat[j][k]=1;
                        }
                    }
                }
                else if(str[i]=='*')
                    continue;
                else if(str[i+1]=='^')
                {
                    int power=str[i+2]-'0';
                    int mat_num=str[i]-'A';
                    int ex_mat[row][col];
                    for(int j=0; j<row; j++)
                    {
                        for(int k=0; k<col; k++)
                        {
                            ex_mat[j][k]=matrix[mat_num][j][k];
                            // printf("%d ",ex_mat[j][k]);
                        }
                        // printf("\n");
                    }
                    power--;
                    while(power--)
                    {
                        int mul[row][col];
                        //initialiazing
                        for(int ii=0; ii<row; ii++)
                        {
                            for(int jj=0; jj<col; jj++)
                            {
                                mul[ii][jj]=0;
                            }
                        }
                        for(int ii=0; ii<row; ii++)
                        {
                            for(int jj=0; jj<col; jj++)
                            {
                                // Multiplying i’th row with j’th column
                                for(int kk=0; kk<col; kk++)
                                {
                                    mul[ii][jj]+=ex_mat[ii][kk] * matrix[mat_num][kk][jj];
                                }
                                //  printf("%d ",mul[ii][jj]);
                            }
                            //printf("\n");
                        }
                        for(int jj=0; jj<row; jj++)
                        {
                            for(int kk=0; kk<col; kk++)
                            {
                                ex_mat[jj][kk] = mul[jj][kk];
                                //printf("%d ", ex_mat[jj][kk] );
                            }
                        }
                    }
                    int mul[row][col];
                    int sum=0;
                    for(int ii=0; ii<row; ii++)
                    {
                        for(int jj=0; jj<col; jj++)
                        {
                            mul[ii][jj]=0;
                        }
                    }
                    if(chker>0)
                    {
                        for(int ii=0; ii<row; ii++)
                        {
                            for(int jj=0; jj<col; jj++)
                            {
                                // Multiplying i’th row with j’th column
                                for(int kk=0; kk<col; kk++)
                                {
                                    mul[ii][jj]+=run_mat[ii][kk]*ex_mat[kk][jj];
                                }
                            }
                        }

                        for(int j=0; j<row; j++)
                        {
                            for(int k=0; k<col; k++)
                            {
                                run_mat[j][k]=mul[j][k];

                            }
                        }
                    }
                    else
                    {
                        for(int ii=0; ii<row; ii++)
                        {
                            for(int jj=0; jj<col; jj++)
                            {
                                run_mat[ii][jj]=ex_mat[ii][jj];
                            }
                        }
                    }
                    i+=2;
                    chker++;
                }
                else
                {
                    int mul[row][col];
                    //initialiazing
                    for(int ii=0; ii<row; ii++)
                    {
                        for(int jj=0; jj<col; jj++)
                        {
                            mul[ii][jj]=0;
                        }

                    }
                    if(chker>0)
                    {
                        for(int ii=0; ii<row; ii++)
                        {
                            for(int jj=0; jj<col; jj++)
                            {
                                mul[ii][jj]=0;
                                // Multiplying i’th row with j’th column
                                for(int kk=0; kk<col; kk++)
                                {
                                    mul[ii][jj]+=matrix[str[i]-'A'][ii][kk]*run_mat[kk][jj];
                                }
                            }
                        }
                        for(int j=0; j<row; j++)
                        {
                            for(int k=0; k<col; k++)
                            {
                                run_mat[j][k]=mul[j][k];
                            }
                        }
                    }
                    else
                    {
                        for(int ii=0; ii<row; ii++)
                        {
                            for(int jj=0; jj<col; jj++)
                                run_mat[ii][jj]=matrix[str[i]-'A'][ii][jj];
                        }

                    }
                    chker++;
                }
            }
            printf("\n\tThe result is\n",str);
            for(int i=0; i<row; i++)
            {
                printf("\t");
                for(int j=0; j<col; j++)
                    printf("%d  ",ans[i][j]);
                printf("\n");
            }
            printf("\n\n");
            int mychoice;
            while(1)
            {
                printf("\t\tPress 1 for calculate another expression.\n");
                printf("\t\tPress 0 for terminate the calculation process.");
                scanf("%d",&mychoice);
                if(mychoice==1 || mychoice==0)
                    break;
                else
                    printf("Invalid choice.\n");
            }
            if(mychoice==0)
                break;
            else
                continue;
        }
        break;
    }
    return 0;
}
