# Bài 8: memory layout
## Phần 1: Giải thích sự khác nhau giữa malloc(), calloc() và realloc()
### malloc() 
- ta có thể sử dụng từ malloc để cấp phát động vùng nhớ cho 1 biến con trỏ nào đó.
- malloc trả về con trỏ kiểu void, chỉ đến địa chỉ của 1 khối vùng nhớ.
- malloc không gán giá trị cho các byte trong khối vùng nhớ đó, nên chúng sẽ mang giá trị rác.
~~~~
 int *ptr = (int *)malloc(5*sizeof(int));
 /* cái code này sẽ giúp cho biến con trỏ ptr trỏ đến 1 khối trong bộ nhớ có độ lớn 20 bytes */
 /* nếu không đủ vùng nhớ trong heap để cấp thì con trỏ sẽ mang giá trị NULL */
~~~~
### calloc()
- calloc cơ bản cũng giống như malloc.
- calloc thay vì cấp 1 khối lớn trong bộ nhớ, thì nó sẽ cấp những khối nhỏ liền kề nhau và mang 1 kiểu dữ liệu xác định
- khi khởi tạo malloc cũng sẽ tự gán 0 cho các byte trong các khối ô nhớ mà nó đã cấp
- Khi sử dụng calloc để cấp phát bộ nhớ động thì ngoài số bytes phải cấp phát theo yêu cầu thì nó cũng sẽ có thêm memory overhead, dùng cho việc quản lý
~~~~
 int *ptr = (int *)calloc(5, sizeof(int));
 /* cấp 1 dãy các khối liên tiếp, mỗi khối 4 bytes cho con trỏ ptr */
 /* nếu không đủ vùng nhớ trong heap để cấp thì con trỏ sẽ mang giá trị NULL */
~~~~
### realloc()
- Được sử dụng để thay đổi những vùng nhớ trước đó đã được cấp phát động bằng malloc hay calloc
- Những byte mới được thêm vào sẽ mang giá trị rác, giá trị trong những vùng nhớ đã được cấp phát động trước đó sẽ được giữ nguyên
~~~~
 int *ptr = (int *)malloc(5* sizeof(int));
 /*Một khối có độ rộng 20 bytes trong vùng nhớ heap vừa được cấp phát động cho biến ptr*/
 ptr = realloc(ptr, 10* sizeof(int));
 /*ptr vừa được cấp phát động thêm 20 bytes nữa, giờ khối ptr quản lý trong bộ nhớ rộng 40 bytes*/
~~~~
## Phần 2: Stack và Heap
### Stack
- Dùng để lưu biến cục bộ, các tham số truyền vào hàm.
- Biến sẽ tự được xóa khi kết thúc hàm.
- Khi khai báo quá nhiều biến cục bộ, hoặc do hàm đệ quy lặp quá nhiều sẽ không đủ vùng nhớ cung cấp gây ra stack overflow.
### Heap
- Dùng khi cấp phát vùng nhớ động.
- Không tự xóa vùng nhớ đã cấp phát sau khi hết chương trình, do đó cần người dùng tự xóa bằng các hàm free hay delete.
- Khi cấp phát quá nhiều, không đủ vùng nhớ để cung cấp sẽ gây ra hiện tượng heap overflow.
