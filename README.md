# Cấu trúc dữ liệu & Thuật toán bằng C

Kho lưu trữ các bài thực hành C về những cấu trúc dữ liệu và thuật toán cơ bản. Mỗi tệp là một phần cài đặt hoặc ví dụ riêng, phù hợp để học tập, tham khảo và luyện tập.

---

## Nội dung

| Tệp | Chủ đề |
|---|---|
| `ArrayList.c` | Danh sách tuyến tính dùng mảng: tìm kiếm, chèn, xóa, tách chẵn/lẻ, gộp danh sách và đếm số nguyên tố |
| `LinkedList.c` | Danh sách liên kết đơn: chèn, tìm kiếm, xóa, tách chẵn/lẻ, gộp danh sách và tính trung bình số âm |
| `Stack-Array.c` | Ngăn xếp dùng mảng: push/pop, chèn/xóa theo vị trí, thao tác đáy ngăn xếp và đổi thập phân sang nhị phân |
| `Stack-Pointer.c` | Ngăn xếp dùng danh sách liên kết: các thao tác cơ bản và mở rộng |
| `Queue-Array.c` | Hàng đợi dùng mảng: enqueue/dequeue và thao tác tại đầu, cuối hoặc vị trí |
| `Queue-Pointer.c` | Hàng đợi dùng danh sách liên kết: enqueue/dequeue và các thao tác mở rộng |
| `BinaryTree-Pointer.c` | Cây nhị phân liên kết: duyệt cây, tìm kiếm, thống kê và xóa nút/nhánh |
| `BinarySearchTree-Pointer.c` | Cây nhị phân tìm kiếm: chèn, tìm kiếm, duyệt, thống kê và xóa nút |
| `generateBinaryInputLength.c` | Sinh tất cả dãy nhị phân có độ dài `n` bằng đệ quy |
| `generateBinaryStringABInputLength.c` | Sinh tất cả xâu từ `A` và `B` có độ dài `n` bằng đệ quy |
| `generateNextBinarySameLength.c` | Tìm dãy nhị phân kế tiếp có cùng độ dài |

---

## Biên dịch và chạy

Các tệp là ví dụ riêng, không phải một chương trình thống nhất. Biên dịch tệp cần chạy bằng trình biên dịch C, ví dụ:

```bash
gcc -std=c99 generateBinaryInputLength.c -o generateBinaryInputLength
```

Một số tệp chỉ chứa phần cài đặt hàm, chưa có hàm `main`; cần bổ sung chương trình kiểm thử trước khi biên dịch thành tệp thực thi. Tùy tệp, có thể cần liên kết thư viện toán học bằng tùy chọn `-lm`.

---

## Mục đích

- Ôn tập cách biểu diễn cấu trúc dữ liệu bằng mảng và con trỏ.
- Thực hành các thao tác cơ bản trên danh sách, ngăn xếp, hàng đợi và cây.
- Làm quen với đệ quy thông qua bài toán sinh chuỗi nhị phân.