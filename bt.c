#include <stdio.h>

int main()
{
    int month, year, day;

    do
    {
        printf("Nhập tháng: ");

        if (scanf("%d", &month) != 1 || month < 1 || month > 12)
        {
            printf("Tháng không hợp lệ, vui lòng nhập lại.\n");
//            while (getchar() != '\n');
            month = 0;
        }
    }
    while (month < 1 || month > 12);

    do
    {
        printf("Nhập năm: ");

        if (scanf("%d", &year) != 1 || year < 1)
        {
            printf("Năm không hợp lệ, vui lòng nhập lại.\n");
            while (getchar() != '\n');
            year = 0;
        }
    }
    while (year < 1);



    if (month == 2)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            day = 29;
        else
            day = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        day = 30;
    }
    else
    {
        day = 31;
    }

    printf("Tháng %d năm %d có %d ngày\n", month, year, day);
    return 0;
}
