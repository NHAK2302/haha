#include <stdio.h>
#include "Menu.h"
#include "User.h"
#include"Reader.h"
#include"Book.h"
int login=0;
User u;
int smallFunc;
int func;
FILE* fUser = fopen(fUSER,"r+t");
FILE* fReader = fopen(fREADER, "r+t");
FILE* fBook = fopen(fBOOK, "r+t");
void func1(FILE* &fUser) {
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
		printf("=======================================================================================================================\n\n\n");
		printf(" >> Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);

		switch (smallFunc) {
			case 1: {
				if (login != 0) {
					printf("Ban da dang nhap roi!\n");
					system("pause");
					break;
				}
				else {
					login=loginUser(u, fUser);
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
					system("pause");
					break;
				}
				else if (login < 3)
				{
					printf("Ban khong du tham quyen\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					updateUser_pass(u, fUser);
					system("pause");
					break;
				}
			}
			case 4: {
				if (login == 0) {
					printf("Ban chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else {
					updateUserInfo(u, fUser);
					system("pause");
					break;
				}
			}
			case 5: {
				if (login == 3) {
					//ham function 5
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
				if (login == 3) {
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

void func2(FILE* &f) {
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
		printf("=======================================================================================================================\n\n\n");
		printf(" >> Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);

		switch (smallFunc) {
			case 1: {
				if (login == 0) {
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
				if (login == 0) {
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
				if (login == 0) {
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
				if (login == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (login < 3) {
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
				if (login == 0) {
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
				if (login == 0) {
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

void func3(FILE* &f) {
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
		printf("=======================================================================================================================\n\n\n");
		printf(" >> Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);

		switch (smallFunc) {
			case 1: {
				if (login == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (login == 1) {
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
				if (login == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (login == 1) {
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
				if (login == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (login == 1) {
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
				if (login == 0) {
					printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
					system("pause");
					break;
				}
				else if (login == 1) {
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
				if (login == 0) {
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
				if (login == 0) {
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

void func4(FILE* &f) {
	system("cls");
	printf("=======================================================================================================================\n");
	printf("Chuc nang 4: Lap phieu muon sach\n");
	printf("=======================================================================================================================\n");
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
	printf("=======================================================================================================================\n\n\n");
	printf("do something ....\n"); //lap phieu muon sach
	system("pause");
	return;
}

void func5(FILE* &f) {
	system("cls");
	printf("=======================================================================================================================\n");
	printf("Chuc nang 5: Lap phieu tra sach\n");
	printf("=======================================================================================================================\n");
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
	printf("=======================================================================================================================\n\n\n");
	printf("do something ....\n"); //lap phieu tra sach
	system("pause");
	return;
}

void func6(FILE* &f) {
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
		printf("=======================================================================================================================\n\n\n");
		printf(" >> Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);

		if (login == 0) {
			printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
			system("pause");
			return;
		}
		if (login == 1) {
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

void welcome(FILE* &f) {
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
		printf(" >> Ban chon chuc nang: ");
		scanf_s("%d", &func);

		switch (func) {
		case 1: {
			func1(f);
			break;
		}
		case 2: {
			func2(f);
			break;
		}
		case 3: {
			func3(f);
			break;
		}
		case 4: {
			func4(f);
			break;
		}
		case 5: {
			func5(f);
			break;
		}
		case 6: {
			func6(f);
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
	logoutUser(u, login); //sau khi thoat chuong trinh phai logout(xoa du lieu tren ram) de tranh tran bo nho
}