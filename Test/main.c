#include <stdio.h>
#include <stdlib.h>
#include "libxlsxwriter/include/xlsxwriter.h"

int main()
{
    printf("Hello world!\n");
    lxw_workbook  *workbook  = workbook_new("tutorial01.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    int row = 0;
    int col = 1;
    worksheet_write_string (worksheet, row, col,     "Total",       NULL);
    worksheet_write_formula(worksheet, row, col + 1, "=SUM(B1:B4)", NULL);
    return 0;
}
