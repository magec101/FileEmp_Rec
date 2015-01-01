#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct employee
{ int id;
  char name[10];
  float sal;
} EMP; 

void init_emp_rec(EMP out_rec[]);
void print_emp_rec(EMP out_rec[]);

void fileEmp_RecMain(int argc, const char** argv, EMP emp_rec[])
{
	//EMP emp_rec[4];
	
	int i,j;
	
	i=0;
	j=1;
  
    //printf("Inside emp_recordMain\n");
    
    //printf("Val is %d\n", atoi(argv[i+1]));
   
    if (argc < 2)
    {
    	for (i=0; i<4; i++)
    	{
    		scanf("%d", &emp_rec[i].id);
    		scanf("%s", emp_rec[i].name);
    		scanf("%f", &emp_rec[i].sal);
    	}
    
    }
    else
    {
    	while (argv[j] != NULL && i < 4)
		{
	
			emp_rec[i].id = atoi(argv[j]);
			j++;
			strcpy(emp_rec[i].name, argv[j]);
			j++;
			emp_rec[i].sal = atof(argv[j]);
			j++;
		
//			printf("Emp id is %d\n", emp_rec[i].id);
			i++;
		}
    }

	/*
	j=0;
	
	for (i=0; i<4; i++)
	{
		if (emp_rec[i].sal >= 10000)
		{
			out_rec[j] = emp_rec[i];
			j++;
		}
	}
	*/

}

void init_emp_rec(EMP out_rec[])
{
	int i;
	
    memset(out_rec, 0, sizeof(EMP)*4);
    
 /*
    printf("After init id is %d \n", out_rec[0].id);
    printf("After init name is %s\n", out_rec[0].name);
    printf("After init sal is %f\n", out_rec[0].sal);
 */ 
	
}
void print_emp_rec_file(EMP out_rec[], int record_no, FILE *fp)
{
	int i;
	
	static int j;
	
	for (i=0; i<record_no; i++)
	{
		if (out_rec[i].id == 0)
			return;
		if (j == 0)
		{
		//	printf("The employees with Salary greater than 10000 are:\n");
			j++;
		}
		fprintf (fp, "%d %s %f\n", out_rec[i].id, out_rec[i].name,out_rec[i].sal);
		//printf ("%d %s %f\n", out_rec[i].id, out_rec[i].name, out_rec[i].sal);
	}
}

void read_file (EMP emp_rec[], int *record_no, FILE *fp)
{
	int i =0;
/*	for (i=0; i<4; i++)
    {
		fscanf(fp, "%d %s %f", &emp_rec[i].id, emp_rec[i].name, &emp_rec[i].sal);
    }
*/

	fscanf(fp, "%d %s %f", &emp_rec[i].id, emp_rec[i].name, &emp_rec[i].sal);
    
    while (!feof(fp))
    {
    	printf ("%d %s %f\n", emp_rec[i].id, emp_rec[i].name, emp_rec[i].sal);
    	i++;
    	fscanf(fp, "%d %s %f", &emp_rec[i].id, emp_rec[i].name, &emp_rec[i].sal);
	   
    }


    *record_no = i;
}

#ifndef __CXX_TEST_MAIN__

int main(int argc, const char** argv){
    
    EMP out_rec[4];
    FILE *fp;
    int rec_no;
	
	init_emp_rec(out_rec);
	
	fp = fopen("EMP", "w+");
	
	if (fp == NULL)
		printf("\nError Opening file\n");
	
	fileEmp_RecMain(argc, argv, out_rec);
	
//	printf("Id is %d", out_rec[0].id);

	print_emp_rec_file(out_rec, 4, fp);

	fseek(fp, 0, 0);
	
	init_emp_rec(out_rec);
//	printf("\n2.Id is %d", out_rec[0].id);

	read_file(out_rec, &rec_no, fp);
/*	
	print_emp_rec_file(out_rec, rec_no, stdout);

    //printf("%s\n", fileEmp_RecMain(argc, argv));
  */
    return 0;
}

#endif