#define ELEMENTS 1000

#define EMPLOYEE_EMPTY 0
#define EMPLOYEE_USED 1
#define EMPLOYEE_DELETE 2


typedef struct{
     int id;
     char name[51];
     char lastName[51];
     float salary;
     int sector;
     int isEmpty; /// Activo (1) o Inactivo (0)
}Employee;




int initEmployee(Employee* eEmpleado, int len);
int addEmployee(Employee* eEmpleado, int len,int id, int sector, char nombre[],char apellido[],float salary);
int appendEmployee(Employee* eEmpleado, int len);
int removeEmployee(Employee* eEmpleado, int len, int id);
Employee* findEmployeeById(Employee* eEmpleado, int len, int id);
int updateEmployee(Employee* eEmpleado, int len, int id, char* nombre, char* apellido,int sector, float salary);
int modifyEmployee(Employee* eEmpleado, int len);
int lowEmployee(Employee* eEmpleado, int len);
int sortEmployee(Employee* eEmpleado,int len);
int printEmployees(Employee* eEmpleado, int len);
float getAverageSalary(Employee* eEmpleado,int len);
int aboveAverageSalaryReport(Employee* eEmpleado,int len);



