#include <iostream>
#include<string.h>
#include<windows.h>
using namespace std;

//Function to join two strings because the function in string.h was not working
char* strcat (char str1[],char str2[]) {
    int i, j;
    i=0;
    while(str1[i] != '\0')
    {
        i++;
    }

    j = 0;
    while(str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';

    return str1;

}


int main()
{   cout<<"Made by Ridheesh Amarthya\n\n";
    here:
    char a[10][10][20], b[10][10][20]; // First two main arrays
    int r1, c1, r2, c2, i, j, k,l,clm11[10],clm22[10],clm111=0,clm222=0;//size of tables
    char clm1[10][20],clm2[10][20]; // column name array

    cout << "Enter the rows and columns for first table: "; // input for table one
    cin >> r1 >> c1;
    cout << "Enter the rows and columns for second table: "; // input for table two
    cin >> r2 >> c2;

    if(r1>10||r1>10||c1>10||c2>10){
        cout<<"\nTable size too large! please enter a table that fits in a 10x10 space.\n\n";
        goto here;
    }


    cout<<"Enter the names of the columns in table A:\n"; // input for column name of table 1
    for(i = 0; i < c1; ++i)
        {
            cout << "Enter name for column" << i << " : ";
            cin >> clm1[i];
            clm11[i]=i;
            clm111++;
        }
    cout<<"Enter the names of the columns in table B:\n"; // input for column name of table 2
    for(i = 0; i < c2; ++i)
        {
            cout << "Enter name for column" << i << " : ";
            cin >> clm2[i];
            clm22[i]=i;
            clm222++;
        }


    cout << endl << "Enter elements of table A:" << endl; // input for table 1
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Enter element A" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];

        }

    cout << endl << "Enter elements of table B:" << endl; // input for table 2
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Enter element B" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    cout << endl << "Table A: \n ";

    for(i=0;i<c1;i++) // displays table 1's column names
        cout<<clm1[i]<<" ";

    cout<<endl;

    for(i = 0; i < r1; ++i) // displays table 1
    for(j = 0; j < c1; ++j)
    {
        cout << " " << a[i][j];
        if(j == c1-1)
            cout << endl;
    }

    cout<<endl<<endl;

    cout << endl << "Table B: \n ";

    for(i=0;i<c2;i++) // displays table 2's column names
        cout<<clm2[i]<<" ";

    cout<<endl;

    for(i = 0; i < r2; ++i) // displays table 2
    for(j = 0; j < c2; ++j)
    {
        cout << " " << b[i][j];
        if(j == c2-1)
            cout << endl;
    }

   // char table1[10][10][20],table2[10][10][20];
    char col1[10][20],col2[10][20]; // for separated columns for table one
    int r11,c11,r22,c22,temp1=0,temp2=0,temp3=0; // rows and stuff

    for (i=0;i<clm111;i++) // separates the columns of table 1 to create col1 D E
        for (j=0;j<clm222;j++){
            if (strcmp(clm1[i],clm2[j])==0) {
                strcpy(col1[temp1],clm1[i]);
                temp1++; //size of col1 D E
            }
          /*  else{
                strcpy(col2[temp2],clm1[i]);
                temp2++;
            }*/
    }


//below is a temp solution, will not work when tableA is out of order, creates col2 A B C
    for(i=0;i<clm111-clm222;i++){
        strcpy(col2[temp2],clm1[i]);
        temp2++; // size of col2 A B C
    }


char col11[50]="",col111[20]="",col22[20]=""; // stores the concated string
int col_1=0,col_2=0,col_3=0; // size of a1,a2,b1

for(i=0;i<temp2;i++){ //stores ABC from table 1
    strcpy(col11,strcat(col11,col2[i]));
}


for(i=0;i<clm222;i++){ //stores DE from table 1
    strcpy(col111,strcat(col111,col1[i]));
}


for(i=0;i<clm222;i++){// stores DE from table 2
    strcpy(col22,strcat(col22,clm2[i]));
}

char a1[10][20],a2[10][20],b1[10][10]; // concated main tables declaration

    for(i=0;i<10;i++){ // setting them equal to null to remove random values, needed for next step
        strcpy(a1[i],"");
        strcpy(b1[i],"");
        strcpy(a2[i],"");
    }

    for(i=0;i<r1;i++){  // join the values of table a DE PROBLEM_POINT
        for(j=clm111-clm222;j<c1;j++){
            strcpy(a2[i],strcat(a2[i],a[i][j]));
     //       col_2++;

    }
    col_2++;
    }


    for(i=0;i<r1;i++){
        for(j=0;j<c1-temp1;j++){
                strcpy(a1[i],strcat(a1[i],a[i][j]));
            //col_1++;
    }
    col_1++;
    }


    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            strcpy(b1[i],strcat(b1[i],b[i][j]));
            //col_3++;
    }
    col_3++;
    }
    char uniq[10][20];

  for(int i =0;i<r1;i++)
        strcpy(uniq[i],a1[i]);

int ur=r1; //number of elements of the unique table
int coo=col_1; // throw away temp for preserving the value of col_1

for(i=0; i<coo; i++)
    {
        for(j=i+1; j<coo; j++)
        {
            /* If any duplicate found */
            if(!strcmp(uniq[i],uniq[j]))
            {
                /* Delete the current duplicate element */
                for(k=j; k<coo; k++)
                {
                    strcpy(uniq[k],uniq[k+1]);
                }
                ur--;
                coo--;
                j--;
            }
        }
    }





    int ur1=r1;
    int coo1=col_1;

    for(i=0; i<coo1; i++) // removes same rows from table 1 as it gives false result when multiple rows are in 1
    {
        for(j=i+1; j<coo1; j++)
        {
            /* If any duplicate found */
            if(!strcmp(a1[i],a1[j])&&!strcmp(a2[i],a2[j]))
            {
                /* Delete the current duplicate element */
                for(k=j; k<coo1; k++)
                {
                    strcpy(a1[k],a1[k+1]);
                    strcpy(a2[k],a2[k+1]);
                }
                ur1--;
                coo1--;
                j--;
            }
        }
    }








    int check[ur];

    for(i=0;i<ur;i++){
        check[i] = 0;
    }

    for(i=0;i<ur;i++){ //without ! it gives 55,35 and stuff and with it it gives 0
        for(j=0;j<r1;j++){

            if(!strcmp(uniq[i],a1[j])){
            for(k=0;k<r2;k++){
                if (!strcmp(a2[j],b1[k])){
                    check[i]++;
                }
            }

            }
        }
    }

cout<<endl<<"Result of division of tables:"<<endl;
cout<<col11<<endl;
for (i=0;i<ur;i++){
    if (check[i]>=r2)
        cout<<uniq[i]<<endl;
}

    cout<<endl<<endl<<endl<<"BackEnd Information"<<endl<<endl<<endl;
    //table A -first row is wrong
    cout<<"Table A"<<endl;
    for(i=0;i<clm111;i++)
        cout<<" "<<clm1[i];
    for(i=0;i<r1;i++){
        cout<<endl;
        for(j=0;j<c1;j++)
            cout<<" "<<a[i][j];
    }

    cout<<endl<<endl;
    cout<<"Table B"<<endl;
    //table B
    for(i=0;i<clm222;i++)
        cout<<" "<<clm2[i];
    for(i=0;i<r2;i++){
        cout<<endl;
        for(j=0;j<c2;j++)
            cout<<" "<<b[i][j];
    }

    cout<<endl<<endl;
    cout<<"Concat table 1.1"<<endl;
    //table ABC
    cout<<col11;
    for(i=0;i<r1;i++)
        cout<<endl<<a1[i];

    cout<<endl<<endl;
    cout<<"Concat table 1.2"<<endl;
    //table DE
    cout<<col111;
    for(i=0;i<r1;i++)
        cout<<endl<<a2[i];

    cout<<endl<<endl;
    cout<<"Concat table 2"<<endl;
    //table DE B
    cout<<col22;
    for(i=0;i<r2;i++)
        cout<<endl<<b1[i];

    cout<<endl<<endl;
    //unique table
    cout<<"Unique table"<<endl;
    cout<<col11;
    for(i=0;i<ur;i++)
        cout<<endl<<uniq[i];

    cout<<endl<<endl;

    cout<<"clm111 ="<<clm111<<" clm222 ="<<clm222<<" temp1 ="<<temp1<<" temp2 ="<<temp2<<endl;
    cout<<"col_1 ="<<col_1<<" col_2 ="<<col_2<<" col_3 ="<<col_3<<" ur ="<<ur<<endl;

    cout<<endl<<"Check table"<<endl;
    for(i=0;i<ur;i++)
        cout<<endl<<check[i];

    cout<<endl<<"Result of division of tables:"<<endl;
    cout<<col11<<endl;
    for (i=0;i<ur;i++){
        if (check[i]>=r2)
        cout<<uniq[i]<<endl;
}
    cout<<endl<<endl;
    system("PAUSE");
   return 0; }
