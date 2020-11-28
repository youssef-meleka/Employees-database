#include <stdio.h>
#include <stdlib.h>

void id_input( int *ID_of_employees, int number_of_employees)
{
    int i, employee_label=1;

    printf("fill the IDs for the following employees: \n"
           "--------NOTE: IDs can't be repeated----------- \n");

    for (i=0; i<number_of_employees; i++)   //filling in the IDs of employees and saving them into the array
        {
            printf("employee number %d ID:",employee_label);
            scanf("%d",&ID_of_employees[i]);
            employee_label++;
       }
    return 0;
}
void salary_input(float *salary, int number_of_employees)
{
   int i, employee_label=1;

    printf("fill the salary for each of the following employees: \n");

    for (i=0; i<number_of_employees; i++)
        {                               //filling in salaries of employees and saving them into the array
            printf("employee's salary:");
            scanf("%f",&salary[i]);
            employee_label++;
       }
    return 0;
}

void exceeded_salaries(float *salary,int *ID_of_employees,int number_of_employees)
{
    float specified_salary;
    int i,i_specified,flag=0; //flag here for handling different case of input

    printf("enter a limit value to show any exceeded salary values above this limit: ");
    scanf("%f",&specified_salary);
    printf("employee(s)' salary that exceeds the specified value: \n");

    for (i=0; i<number_of_employees; i++)
        {
           if(salary[i]>specified_salary)
           {
                flag++;         //printing exceeded salaries
                i_specified=i;
                printf("employee with the ID: %d  has a salary of %.2f \n",ID_of_employees[i_specified],salary[i]);
           }

        }
        if (flag==0)
        {                       //in case of user entered a higher value that doesn't exist
            printf("there is no higher salary than the value you entered");
        }

     return 0;
}

void salary_rise(float *salary,int *ID_of_employees,int number_of_employees)
{
    int num,specified_ID,i;
    float percentage;

      printf("enter the ID of employee to calculate rise: ");
      scanf("%d",&specified_ID);

      printf("enter value of the rise (in percentage ) : ");
      scanf("%f",&percentage);

      for(i=0;i<number_of_employees;i++)
      {                                         //calculating rise and adding it to the old value
         if(specified_ID == ID_of_employees[i])
         {
             salary[i] = salary[i]+(salary[i]*(float)percentage/100.0);

             printf("salary of employee with ID: %d after rise is %.2f $ \n",specified_ID,salary[i]);
         }

      }

}

void printing_compny_list(float *salary,int *ID_of_employees,int number_of_employees)
{
     int i,employee_label=1;
                                                    //printing list of the company: ID & salary
    printf("List of employees of the company: \n");
    for (i=0; i<number_of_employees; i++)
        {
          printf("employee %d ID is: %d \t salary is: %.2f $ \n",employee_label,ID_of_employees[i],salary[i]);
          employee_label++;
        }
}

int main()
{
    int number_of_employees,employee_label=1,i,user_option_choice;


    printf("----------------WELCOME-------------------- \n");
    printf("please enter number of employees in the company: ");
    scanf("%d",&number_of_employees);
                                                                    //allocationg each 1D array with the specified space by user
    int  *ID_of_employees = (int*)malloc(number_of_employees * sizeof(int));
    float *salary   = (float*)malloc(number_of_employees* sizeof(float));

    while(1)
    {
            printf("----------------------------------------------- \n"
                   "From the following menu, choose an option: \n"
                    "----------------------------------------------- \n"
                    " 1. Enter employees IDs (RECOMMENDED FIRST) \n"
                    " 2. Enter employees' salaries \n"
                    " 3. State a value to find any exceeded salaries \n"
                    " 4. Make a salary rise \n"
                    " 5. displaying company list (after any edits) \n"
                    " 0. Done \n");

            printf("your choice is number: ");
            scanf("%d",&user_option_choice);


            switch(user_option_choice)
             {

                case 1:
                                                            //input of IDs
                    id_input(ID_of_employees,number_of_employees);
                    break;

                case 2:
                                                            //input of salaries
                    salary_input(salary,number_of_employees);
                    break;

                case 3:
                                                            //finding any exceeded salaries
                    exceeded_salaries(salary,ID_of_employees,number_of_employees);
                    break;


                case 4:
                                                            //giving a rise for a specific employee
                    salary_rise(salary,ID_of_employees,number_of_employees);
                    break;


                case 5:
                                                            //printing the final company list
                    printing_compny_list(salary,ID_of_employees,number_of_employees);
                    break;


                case 0:
                                                           // exiting the program on command
                    printf("exiting the program...");
                    exit(0);

             }

    }


    return 0;
}
