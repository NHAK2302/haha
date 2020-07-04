#include <stdio.h>
#include "Menu.h"
#include "User.h"
User u;
int smallFunc;
int func;
void func1() {
	do {
		system("cls");
		printf("=======================================================================================================================\n");
		printf("Chuc nang 1: ...\n");
		printf("=======================================================================================================================\n");
		printf("1. Dang nhap\n");
		printf("2. Dang xuat\n");
		printf("3. Thay doi mat khau\n");
		printf("4. Cap nhat thong tin ca nhan\n");
		printf("5. Tao nguoi dung\n");
		printf("6. Phan quyen nguoi dung\n");
		printf("0. Quay lai\n");
		printf("=======================================================================================================================\n");
		printf("Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);

		switch (smallFunc) {
			case 1: {
				if (loginUser(u) != 0) {
					printf("\nBan da dang nhap\n");
					system("pause");
					break;
				}
				else {
					printf("Goi ham dn\n"); //goi ham dn
					system("pause");
					break;
				}
			}
			case 2: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Goi ham dx\n"); //goi ham dx
					system("pause");
					break;
				}
			}
			case 3: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Goi ham doi pass\n"); //goi ham doi pass
					system("pause");
					break;
				}
			}
			case 4: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Goi ham doi personal info\n"); //goi ham doi info
					system("pause");
					break;
				}
			}
			case 5: {
				if (loginUser(u) == 3) {
					printf("goi ham tao user\n"); //goi ham tao user
					system("pause");
					break;
				}
				else {
					printf("\nBan khong co quyen truy cap chuc nang nay\n");
					system("pause");
					break;
				}
			}
			case 6: {
				if (loginUser(u) == 3) {
					printf("Goi ham phan quyen user\n"); //goi ham phan quyen user
					system("pause");
					break;
				}
				else {
					printf("\nBan khong co quyen truy cap chuc nang nay\n");
					system("pause");
					break;
				}
			}
			case 0: {
				return;
			}
			default: {
				printf("\nKhong hop le\n");
				system("pause");
			}
		}
	} while (smallFunc != 0);
}

void func2() {
	do {
		system("cls");
		printf("=======================================================================================================================\n");
		printf("Chuc nang 2: Quan ly doc gia\n");
		printf("=======================================================================================================================\n");
		printf("1. Xem danh sach doc gia trong thu vien\n");
		printf("2. Them doc gia\n");
		printf("3. Chinh sua thong tin mot doc gia\n");
		printf("4. Xoa thong tin mot doc gia\n");
		printf("5. Tim kiem mot doc gia theo CMND\n");
		printf("6. Tim kiem sach theo ho ten\n");
		printf("0. Quay lai\n");
		printf("=======================================================================================================================\n");
		printf("Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);

		switch (smallFunc) {
			case 1: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //xem list reader
					system("pause");
					break;
				}
			}
			case 2: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //add reader
					system("pause");
					break;
				}
			}
			case 3: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //xem list reader
					system("pause");
					break;
				}
			}
			case 4: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (loginUser(u) != 3) {
					printf("\nBan khong co quyen truy cap chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //remove reader's info
					system("pause");
					break;
				}
			}
			case 5: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //find reader by cmnd
					system("pause");
					break;
				}
			}
			case 6: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //find books by full name
					system("pause");
					break;
				}
			}
			case 0: {
				return;
			}
			default: {
				printf("\nKhong hop le\n");
				system("pause");
			}
		}
	} while (smallFunc != 0);
}

void func3() {
	do {
		system("cls");
		printf("=======================================================================================================================\n");
		printf("Chuc nang 3: Quan ly sach\n");
		printf("=======================================================================================================================\n");
		printf("1. Xem danh sach cac sach trong thu vien\n");
		printf("2. Them sach\n");
		printf("3. Chinh sua thong tin mot quyen sach\n");
		printf("4. Xoa thong tin sach\n");
		printf("5. Tim kiem sach theo ISBN\n");
		printf("6. Tim kiem sach theo ten sach\n");
		printf("0. Quay lai\n");
		printf("=======================================================================================================================\n");
		printf("Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);

		switch (smallFunc) {
			case 1: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (loginUser(u) == 1) {
					printf("\nBan khong co quyen truy cap chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //show list of books
					system("pause");
					break;
				}
			}
			case 2: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (loginUser(u) == 1) {
					printf("\nBan khong co quyen truy cap chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //add book
					system("pause");
					break;
				}
			}
			case 3: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (loginUser(u) == 1) {
					printf("\nBan khong co quyen truy cap chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //update book's info
					system("pause");
					break;
				}
			}
			case 4: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (loginUser(u) == 1) {
					printf("\nBan khong co quyen truy cap chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //remove book's info
					system("pause");
					break;
				}
			}
			case 5: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //find books by ISBN
					system("pause");
					break;
				}
			}
			case 6: {
				if (loginUser(u) == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					printf("Chua co ham\n"); //find books by book's name
					system("pause");
					break;
				}
			}
			case 0: {
				return;
			}
			default: {
				printf("\nKhong hop le\n");
				system("pause");
			}
		}
	} while (smallFunc != 0);
}

void func4() {
	system("cls");
	printf("=======================================================================================================================\n");
	printf("Chuc nang 4: Lap phieu muon sach\n");
	printf("=======================================================================================================================\n");
	printf("do something ....\n"); //lap phieu muon sach
	system("pause");
	return;
}

void func5() {
	system("cls");
	printf("=======================================================================================================================\n");
	printf("Chuc nang 5: Lap phieu tra sach\n");
	printf("=======================================================================================================================\n");
	printf("do something ....\n"); //lap phieu tra sach
	system("pause");
	return;
}

void func6() {
	do {
		system("cls");
		printf("=======================================================================================================================\n");
		printf("Chuc nang 6: Cac thong ke co ban\n");
		printf("=======================================================================================================================\n");
		printf("1. Thong ke so luong sach trong thu vien\n");
		printf("2. Thong ke so luong sach theo the loai\n");
		printf("3. Thong ke so luong doc gia\n");
		printf("4. Thong ke so luong doc gia theo gioi tinh\n");
		printf("5. Thong ke so sach dang duoc muon\n");
		printf("6. Thong ke danh sach doc gia bi tre han\n");
		printf("0. Quay lai\n");
		printf("=======================================================================================================================\n");
		printf("Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);

		if (loginUser(u) == 0) {
			printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
			system("pause");
			return;
		}
		if (loginUser(u) == 1) {
			printf("\nBan khong co quyen truy cap chuc nang nay\n");
			system("pause");
			return;
		}

		switch (smallFunc) {
			case 1: {
				printf("CHua co ham\n");
				system("pause");
				break;
			}
			case 2: {
				printf("CHua co ham\n");
				system("pause");
				break;
			}
			case 3: {
				printf("CHua co ham\n");
				system("pause");
				break;
			}
			case 4: {
				printf("CHua co ham\n");
				system("pause");
				break;
			}
			case 5: {
				printf("CHua co ham\n");
				system("pause");
				break;
			}
			case 6: {
				printf("CHua co ham\n");
				system("pause");
				break;
			}
			case 0: {
				return;
			}
			default: {
				printf("\nKhong hop le\n");
				system("pause");
			}
		}
	} while (smallFunc != 0);
}

void welcome() {
	do {
		system("cls");
		printf("                                                   ***** Welcome! *****                         \n\n");
		printf("|======================================================================================================================|\n");
		printf("| Chuc nang 1: ...                                                                                                     |\n");
		printf("| Chuc nang 2: Quan ly doc gia                                                                                         |\n");
		printf("| Chuc nang 3: Quan ly sach                                                                                            |\n");
		printf("| Chuc nang 4: Lap phieu muon sach                                                                                     |\n");
		printf("| Chuc nang 5: Lap phieu tra sach                                                                                      |\n");
		printf("| Chuc nang 6: Cac thong ke co ban                                                                                     |\n");
		printf("| Chuc nang 0: Thoat chuong trinh                                                                                      |\n");
		printf("|======================================================================================================================|\n");
		printf("Ban chon chuc nang: ");
		scanf_s("%d", &func);

		switch (func) {
			case 1: {
				func1();
				break;
			}
			case 2: {
				func2();
				break;
			}
			case 3: {
				func3();
				break;
			}
			case 4: {
				func4();
				break;
			}
			case 5: {
				func5();
				break;
			}
			case 6: {
				func6();
				break;
			}
			case 0: {
				printf("\nChuong trinh ket thuc\n\n");
				return;
			}
			default: {
				printf("\nKhong hop le\n");
				system("pause");
			}
		}
	} while (func != 0);
}