#include <stdio.h>
#include "Menu.h"
#include "User.h"
int login=0;
User u;
int smallFunc;
int func;
void func1(FILE* f) {
	do {
		system("cls");
		printf("===========================================================================\n");
		if (login == 0)
		{
			printf("Tinh trang : Chua dang nhap\n");
		}
		else
		{
			printf("Tinh trang : Da dang nhap\n");
			printf("Xin chao, %s \n", u.name);
			printf("Tham quyen tai khoan cua ban la : ");
			switch (u.type)
			{
			case 1:
			{
				printf("Chuyen vien \n");
				break;
			}
			case 2:
			{
				printf("Quan ly \n");
				break;
			}
			case 3:
			{
				printf("Admin \n");
				break;
			}
			default:
				break;
			}
		}
		printf("===========================================================================\n");
		printf("Chuc nang 1: ...\n");
		printf("===========================================================================\n");
		printf("1. Dang nhap\n");
		printf("2. Dang xuat\n");
		printf("3. Thay doi mat khau\n");
		printf("4. Cap nhat thong tin ca nhan\n");
		printf("5. Tao nguoi dung\n");
		printf("6. Phan quyen nguoi dung\n");
		printf("0. Quay lai\n");
		printf("===========================================================================\n");
		printf("Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);

		switch (smallFunc) {
		case 1: {
			if (login != 0) {
				printf("Ban da dang nhap roi!\n");
				system("pause");
				break;
			}
			else {
				login=loginUser(u, f);
				system("pause");
				break;
			}
		}
		case 2: {
			if (login == 0) {
				printf("Ban chua dang nhap\nKhong the su dung chuc nang nay\n");
				system("pause");
				break;
			}
			else {
				logoutUser(u, login);
				system("pause");
				break;
			}
		}
		case 3: {
			if (login == 0) {
				printf("Ban chua dang nhap\nKhong the su dung chuc nang nay\n");
				break;
			}
			else if (login < 3)
			{
				printf("Ban khong du tham quyen\nKhong the su dung chuc nang nay\n");
				break;
			}
			else {
				printf("Goi ham doi pass\n"); //goi ham doi pass
				break;
			}
		}
		case 4: {
			if (loginUser(u,f) == 0) {
				printf("Ban chua dang nhap\nKhong the su dung chuc nang nay\n");
				break;
			}
			else {
				printf("Goi ham doi personal info\n"); //goi ham doi info
				break;
			}
		}
		case 5: {
			if (login == 3) {
				//ham function 5
			}
			break;
		}
		case 0: {
			return;
		}
		}
	} while (smallFunc != 0);
}

void welcome(FILE* f) {
	do {
		system("cls");
		printf("                               ***** Welcome! *****                        \n\n");
		printf("===========================================================================\n");
		printf("Chuc nang 1: ...\n");
		printf("Chuc nang 2: Quan ly doc gia\n");
		printf("Chuc nang 3: Quan ly sach\n");
		printf("Chuc nang 4: Lap phieu muon sach\n");
		printf("Chuc nang 5: Lap phieu tra sach\n");
		printf("Chuc nang 6: Cac thong ke co ban\n");
		printf("Chuc nang 0: Thoat chuong trinh\n");
		printf("===========================================================================\n");
		printf("Ban chon chuc nang: ");
		scanf_s("%d", &func);

		switch (func) {
		case 1: {
			func1(f);
			break;
		}
		case 0: {
			return;
		}
		}
	} while (func != 0);


}