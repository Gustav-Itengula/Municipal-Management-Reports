#include <stdio.h>
#include "reports.h"
#include "employee.h"
#include "budget.h"
#include "supplier.h"
#include "assets.h"

void employeeReport()
{
    int i;
    float totalBasicSalary = 0;
    float totalAllowances = 0;
    float totalGrossSalary = 0;

    printf("\n========== EMPLOYEE REPORT ==========\n");

    if (employeeCount == 0)
    {
        printf("No employees available.\n");
        return;
    }

    for (i = 0; i < employeeCount; i++)
    {
        float allowances;
        float grossSalary;

        allowances = employees[i].housingAllowence +
                     employees[i].transportAllowence;

        grossSalary = employees[i].basicSalary + allowances;

        totalBasicSalary += employees[i].basicSalary;
        totalAllowances += allowances;
        totalGrossSalary += grossSalary;
    }

    printf("Total Employees: %d\n", employeeCount);
    printf("Total Basic Salaries: %.2f\n", totalBasicSalary);
    printf("Total Allowances: %.2f\n", totalAllowances);
    printf("Total Gross Salaries: %.2f\n", totalGrossSalary);
}

void budgetReport()
{
    int i;
    float totalAllocated = 0;
    float totalExpenditure = 0;
    float totalRemaining = 0;

    printf("\n========== BUDGET REPORT ==========\n");

    if (budgetCount == 0)
    {
        printf("No budgets available.\n");
        return;
    }

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
        totalRemaining += calculateRemainingBudget(
            budgets[i].allocatedBudget,
            budgets[i].expenditure
        );
    }

    printf("Total Budgets: %d\n", budgetCount);
    printf("Total Allocated Budget: %.2f\n", totalAllocated);
    printf("Total Expenditure: %.2f\n", totalExpenditure);
    printf("Total Remaining Budget: %.2f\n", totalRemaining);
}

void supplierReport()
{
    printf("\n========== SUPPLIER REPORT ==========\n");

    printf("Registered Suppliers:\n\n");

    displaySuppliers();
}

void assetReport()
{
    printf("\n========== ASSET REPORT ==========\n");

    printf("Registered Municipal Assets:\n\n");

    displayAssets();
}

void reportsMenu()
{
    int option;

    do
    {
        printf("\n========== REPORTS ==========\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf("=============================\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                assetReport();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (option != 5);
}
