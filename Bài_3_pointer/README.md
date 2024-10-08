# Bài 3: Pointer
- Con trỏ là 1 biến chứa địa chỉ của 1 biến khác.
- Sử dụng con trỏ để truyền vào 1 hàm (truyền tham chiếu) sẽ giúp ta thay đổi giá trị của 1 biến nằm ngoài hàm đó.
- Cách khai báo con trỏ:
~~~~
  int *ptr; //trong đó int là kiểu dữ liệu mà con trỏ đó trỏ tới.
~~~~
- Con trỏ trong hệ điều hành 64 bit sẽ có kích thước là 8 bytes, để có thể chứa đủ địa chỉ của 1 biến trong hệ điều hành đó.
- Như vậy, các con trỏ như: char *ptr hay int *ptr hay double *ptr đều có kích thước là 8 bytes.
- Tuy nhiên, tùy vào kiểu dữ liệu khi khai báo (int, char, double) thì hệ điều hành sau khi truy cập vào địa chỉ lưu trong con trỏ, sẽ tiến hành lấy số bytes cần thiết.
~~~~
  int a = 10;
  int *ptr = &a;
  printf("Gia tri cua a la: %d", *ptr); //lệnh *ptr sẽ khiến hệ điều hành truy cập đến 0x01 lấy 4 bytes.
~~~~
- Con trỏ void.
~~~~
  void *ptr; //là con trỏ có thể trỏ tới các kiểu dữ liệu khác nhau
  int a;
  double b;
  float c;
  void ptr1[] = {&a, &b, &c}; //ta có thể tạo 1 mảng void *ptr với a, b, c mang các kiểu dữ liệu khác nhau.
~~~~
- Khi tạo 1 mảng con trỏ void như trên sẽ giúp ta dễ dàng trong việc truy cập tới các phần tử.
- Tuy nhiên, khi lấy giá trị cần lưu ý, do mang kiểu void, nên khi truy cập đến địa chỉ lưu trong con trỏ, hệ điều hành sẽ không biết phải lấy báo nhiêu bytes bộ nhớ.
vậy nên, ta cần phải ép kiểu dữ liệu cho phù hợp.
~~~~
  int a;
  void *ptr = &a;
  printf("Gia tri cua bien a la: %d", *(int *)ptr);
~~~~
- Con trỏ còn có thể trỏ tới hàm, khai báo như sau:
~~~~
  (return value) (*ptr)(parameter types) = tên hàm; //Có thể sử dụng con trỏ như 1 hàm bình thường.
~~~~
- con trỏ hằng: con trỏ trỏ tới 1 biến hằng số:
~~~~
  const int *ptr; //hay int const *ptr; giá trị của biến mà con trỏ đó trỏ tới sẽ không thể thay đổi.
~~~~
- hằng con trỏ: con trỏ này chỉ trỏ tới 1 biến mà thôi.
~~~~
  int *const ptr = 0x01; //địa chỉ mà nó chứa khi khai báo sẽ không thay đổi trong chương trình
~~~~
- Con trỏ còn có thể trỏ đến 1 con trỏ khác, con trỏ này sẽ chứa địa chỉ của con trỏ mà nó trỏ đến: 
~~~~
  int a = 10;
  int *ptr = &a;
  int **ptr1 = &ptr;
  printf("gia tri cua bien a la: %d", **ptr1); //**ptr1 trả về giá trị mà biến ptr trỏ đến.
  printf("dia chi cua bien a la: %p", *ptr1); //*ptr1 trả về địa chỉ của biến mà ptr trỏ đến.
~~~~
- Khi khai báo con trỏ, thì để tránh con trỏ chứa 1 giá trị rác, ta sẽ gán giá trị cho con trỏ đó là NULL
~~~~
  int *ptr =  NULL; //con trỏ này sẽ trỏ đến 0x00.
~~~~
- Sau khi sử dụng xong con trỏ, ta cũng nên gán NULL để phòng tránh rắc rối xảy ra.
