pointer:
1:
*p3 = B, p3 = 0x5678
*p3 = A, p3 = 0x1234
*p1 = B, p1 = 0x1234

2:
*p = 5;

3:
double *p là con trỏ của kiểu double, nó sẽ quản lý 8 bytes chứ ko phải 1 byte

gán *p = &c đồng nghĩa việc 7 bytes đằng sau c chưa được cấp phát sẽ bị truy cập -> lỗi


