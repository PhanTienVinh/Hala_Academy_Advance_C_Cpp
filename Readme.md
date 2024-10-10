# Bài 1: Compiler - Macro
## Quá trình biên dịch
- Gồm 4 giai đoạn:
  - Preprocessor:
    - Thay thế các macro
    - Xóa các comment
    - Thay thế các lệnh include
    - Sau quá trình này từ các file .c và .h, ta sẽ có các file .i
  - Compiler
    - Chuyển file .i thành file assembly .s
  - Assembler
    - Chuyển file .s thành file chứa mã máy .o
  - Linker
    - Kết nối các file .o từ các file.c hay .lib trước đó để tạo thành 1 file thực thi .exe
## Các chỉ thị tiền xử lý
- #include
  - Dùng để chèn code của các file khác vào trong chương trình
- #define
  - Có thể dùng để định nghĩa hằng số
  ~~~~
  #define PI 3.16
  ~~~~
  - Có thể dùng để thay thế các câu lệnh lặp lại
  ~~~~
  #define TONG_HAI_SO(a,b) a+b
  ~~~~
  - Khi muốn thay thế cho nhiều câu lệnh có thể viết như sau
  ~~~~
  #define GIOI_THIEU_BAN_THAN()          \
  printf("Toi ten Vinh");                \
  printf("nam sinh: 2004");
  ~~~~
  - Khi sử dụng macro để thay thể các câu lệnh, chúng ta có thể để trong vòng lập while(0) để tránh những câu lệnh đó ảnh hưởng lên nhau, hoặc ảnh hưởng phần còn lại của chương trình
- #ifdef, #ifndef
  - Dùng để kiểm tra xem 1 macro đã được định nghĩa hay chưa, có thể sử dụng trong các file .h để tránh việc vòng lặp trong gọi file .h
  ~~~~
  #ifndef TINHTONG
  #define TINHTONG
  /* Code của file TINHTONG*/
  #endif
  ~~~~
- #if, #elif, #else, #endif
  - Nếu if đúng thì thực hiện, nếu không thì bỏ qua đoạn code đi tới elif, nếu tất cả đều không đúng thì đến else, tất cả sẽ kết thúc bằng #endif
  - Thường được sử dụng khi muốn nạp code cho nhiều con vi điều khiển khác nhau, khi đó chỉ cần thay đổi dòng #define thì code tương ứng sẽ được nạp
  ~~~~
  #define STM32 0
  #define PIC   1
  #define VDK STM32
  
  #if VDK == PIC
  /* Code cho AVR */
  #elif VDK = STM32
  /* Code cho STM32 */
  #endif
  ~~~~
## Một số toán tử trong Macro
- Toán tử ##
  - Toán tử này dùng để ghép hai chuỗi
  ~~~~
  #define HO_VA_TEN(ten, ho) ten##ho
  ~~~~
- Toán tử #
  - Toán tử này dùng để chuẩn hóa chuỗi
  ~~~~
  #define NHAP_TEN(a) printf("Ban ten la: %s, #a);
  ~~~~
- Toán tử 
