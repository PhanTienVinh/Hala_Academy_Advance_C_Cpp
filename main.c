#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char *error_code = "Không có lỗi! \n";

#define TRY                                if((exception_code = setjmp(buf)) == 0)
#define CATCH(value)                       else if(exception_code == value)
#define THROW(value, error)                error_code = error; longjmp(buf, value);


enum ErrorCodes
{
    NO_ERROR = 1,
    FILE_ERROR = 2,
    NETWORK_ERROR = 3,
    CALCULATION_ERROR = 4
};


void readFile()
{
    printf("Doc file ...!\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại!\n");
}

void networkOperation()
{
    printf("Dang ket noi ...!\n");
    THROW(NETWORK_ERROR, "Lỗi kết nối: Mất kết nối!\n");
}

void calculateData()
{
    printf("Dang tinh toan ...!\n");
    THROW(CALCULATION_ERROR, "Lỗi tính toán: Tràn dữ liệu!\n");
}

int main(void)
{
    TRY
    {
        readFile();
        networkOperation();
        calculateData();
        THROW(NO_ERROR, "Khong co loi! \n");
    }
    CATCH(FILE_ERROR)
    {
        printf("%s\n", error_code);
    }
    CATCH(NETWORK_ERROR)
    {
        printf("%s\n", error_code);
    }
    CATCH(CALCULATION_ERROR)
    {
        printf("%s\n", error_code);
    }
    CATCH(NO_ERROR)
    {
        printf("%s\n", error_code);
    }
    
    


    return 0;
}