#include <stdio.h>
#include "Menu.h"
extern User u;
extern Book b;
extern Reader r;
int login=0;
int smallFunc;
int func;
FILE* fUser ;
FILE* fReader ;
FILE* fBook ;
FILE* fBorrow = fopen(fBORROW, "r+t");
FILE* fReturn = fopen(fRETURN, "r+t");
void func1() {
	do {
		system("cls");
		printf("=======================================================================================================================\n");
		printf("Chuc nang 1: Quan ly nguoi dung\n");
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
					login=loginUser(fUser);
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
					logoutUser(login);
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
				else {
					system("cls");
					updateUser_pass(fUser);
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
					system("cls");
					updateUserInfo(fUser);
					system("pause");
					break;
				}
			}
			case 5: {
				if (login == 3) {
					system("cls");
					createUser(fUser);
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
					system("cls");
					giveUser_status(fUser); //goi ham phan quyen user
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
		printf("6. Tim kiem mot doc gia theo ho ten\n");
		printf("0. Quay lai\n");
		if (login == 0) {
			printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
			system("pause");
			return;
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
					system("cls");
					readReader_all(fReader);
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
					system("cls");
					createReader(fReader);
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
					system("cls");
					updateReaderInfo(fReader);
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
					system("cls");
					deleteReader_interface(fReader);
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
					system("cls");
					findReaderByIdenNumb_interface(r,fReader);
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
					system("cls");
					findReaderByName_interface(r,fReader);
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
		if (login == 0) {
			printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
			system("pause");
			return;
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
					system("cls");
					readBook_all(fBook);
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
					system("cls");
					createBook(fBook);
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
					system("cls");
					updateBookInfo(fBook);
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
					system("cls");
					deleteBook_interface(fBook);
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
					system("cls");
					findBookByISBN_interface(b,fBook);
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
					system("cls");
					findBookByName_interface(b,fBook);
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
	if (login == 0) {
		printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
		system("pause");
		return;
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
	createBorrowNote(fBorrow);
	system("pause");
	return;
}

void func5() {
	system("cls");
	printf("=======================================================================================================================\n");
	printf("Chuc nang 5: Lap phieu tra sach\n");
	printf("=======================================================================================================================\n");
	if (login == 0) {
		printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
		system("pause");
		return;
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
	createReturnNote(fReturn);
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
		if (login == 0) {
			printf("\nBan chua dang nhap\nKhong the su dung chuc nang nay\n");
			system("pause");
			return;
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
		printf(" >> Ban chon chuc nang: ");
		scanf_s("%d", &smallFunc);
		switch (smallFunc) {
			case 1: {
				system("cls");
				printf("So sach co trong thu vien: %d", numbOfBooks_all(fBook));
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				numbOfBooks_type(fBook);
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				printf("Tong so doc gia trong thu vien: %d", numbOfReaders_all(fBook));
				system("pause");
				break;
			}
			case 4: {
				system("cls");
				numbOfReaders_sex(fReader);
				system("pause");
				break;
			}
			case 5: {
				system("cls");
				numbOfBooks_borrowing_interface(fReturn, fBorrow);
				system("pause");
				break;
			}
			case 6: {
				system("cls");
				late(fReturn);
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
		printf("======================================================================================================================\n");
		printf(" Chuc nang 1: Quan ly nguoi dung                                                                                      \n");
		printf(" Chuc nang 2: Quan ly doc gia                                                                                         \n");
		printf(" Chuc nang 3: Quan ly sach                                                                                            \n");
		printf(" Chuc nang 4: Lap phieu muon sach                                                                                     \n");
		printf(" Chuc nang 5: Lap phieu tra sach                                                                                      \n");
		printf(" Chuc nang 6: Cac thong ke co ban                                                                                     \n");
		printf(" Chuc nang 0: Thoat chuong trinh                                                                                      \n");
		printf("======================================================================================================================\n");
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
	logoutUser(login); //sau khi thoat chuong trinh phai logout(xoa du lieu tren ram) de tranh tran bo nho
}

void start()
{
	Encryption(bUSER,fUSER);
	Encryption(bREADER,fREADER);
	Encryption(bBOOK,fBOOK);
	fUser = fopen(fUSER, "r+t");
	fReader = fopen(fREADER, "r+t");
	fBook = fopen(fBOOK, "r+t");
}
void end()
{
	fclose(fUser);
	fclose(fReader);
	fclose(fBook);
	logoutUser(login);
	freeReader(r);
	freeBook(b);
	Decryption(fUSER,bUSER );
	Decryption(fREADER,bREADER);
	Decryption( fBOOK,bBOOK);
	remove(fUSER);
	remove(fREADER);
	remove(fBOOK);
}