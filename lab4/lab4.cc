#include <stdio.h>

int main() {
    char employeeID[11];         // เก็บรหัสพนักงาน (สูงสุด 10 ตัวอักษร)
    int workingHours;            // จำนวนชั่วโมงที่ทำงาน
    float salaryPerHour;         // รายได้ต่อชั่วโมง
    float totalSalary;           // รายได้รวม

    // รับข้อมูล
    printf("Input the Employees ID(Max. 10 chars): \n");
    scanf("%s", employeeID);

    printf("Input the working hrs: \n");
    scanf("%d", &workingHours);

    printf("Salary amount/hr: \n");
    scanf("%f", &salaryPerHour);

    // คำนวณรายได้รวม
    totalSalary = workingHours * salaryPerHour;

    // แสดงผล
    printf("Employees ID = %s\n", employeeID);
    printf("Salary = U$ %.2f\n", totalSalary);

    return 0;
}
