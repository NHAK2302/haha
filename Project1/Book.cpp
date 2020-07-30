#include "Book.h"
Book b;

int findBookByISBN(char* ISBN, FILE* f, int* result) { // tim sach theo ISBN
	if (f == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return -1;
	}
	int k = 0;
	char trash[LENGTH_MAX];
	int ord;
	char ISBN_temp[LENGTH_MAX];
	rewind(f);
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%d,%[^,],", &ord, &ISBN_temp);
		if (_stricmp(ISBN, ISBN_temp) == 0)
		{
			result[k++] = ord;
		}
		fscanf(f, "%[^\n]\n", trash);
	}
	rewind(f);
	return k;
}

int findBookByName(char* name, FILE* f, int* result) {
	if (f == NULL)
	{
		printf(".csv not found! findUser failed \n");
		return -1;
	}
	int k = 0;
	char trash[LENGTH_MAX];
	int ord;
	char name_temp[LENGTH_MAX];
	rewind(f);
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%d,%[^,],%[^,],", &ord, &trash, &name_temp);
		if (_stricmp(name, name_temp) == 0)
		{
			result[k++] = ord;
		}
		fscanf(f, "%[^\n]\n", trash);
	}
	rewind(f);
	return k;
}

int findBookByType(char* type, FILE* f, int* result) {
	if (f == NULL)
	{
		printf(".csv not found! findUser failed \n");
		return -1;
	}
	int k = 0;
	char trash[LENGTH_MAX];
	int ord;
	char type_temp[LENGTH_MAX];
	rewind(f);
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],", &ord, &trash, &trash, &trash, &trash, &trash, &type_temp);
		if (_stricmp(type, type_temp) == 0)
		{
			result[k++] = ord;
		}
		fscanf(f, "%[^\n]\n", trash);
	}
	rewind(f);
}


void readBook(Book& b, int ord, FILE* f) {
	if (f == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return;
	}
	char temp[LENGTH_MAX];
	int n; fscanf(f, "%d\n", &n); // dong da`u
	for (int i = 1; i <= ord - 1; i++)
	{
		fscanf(f, "%[^\n]\n", temp);
	}
	fscanf(f, "%d,", &b.ord_numb);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, b.ISBN);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, b.name);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, b.author);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, b.pub_company);
	fscanf(f, "%d,", &b.pub_year);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, b.type);
	fscanf(f, "%d,%d\n", &b.price, &b.amount);
	rewind(f);
}

void writeBook(Book& b, FILE*& f) {
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX * 4] = "\0";
	FILE* temp_f = fopen("temp.txt", "w+");
	int line = 0;
	int n; fscanf(f, "%d\n", &n);
	if (n < b.ord_numb)
	{
		n++;
	}
	fprintf(temp_f, "%d\n", n);
	while (!feof(f))
	{
		fscanf(f, "%[^\n]\n", temp_string);
		line++;
		if (line == b.ord_numb)
		{
			fprintf(temp_f, "%d,%s,%s,%s,%s,%d,%s,%d,%d\n"
				, b.ord_numb, b.ISBN, b.name, b.author, b.pub_company, b.pub_year, b.type, b.price, b.amount);
		}
		else
		{
			fprintf(temp_f, "%s\n", temp_string);
		}
	}
	while (line < b.ord_numb)
	{
		line++;
		if (line == b.ord_numb)
			fprintf(temp_f, "%d,%s,%s,%s,%s,%d,%s,%d,%d\n"
				, b.ord_numb, b.ISBN, b.name, b.author, b.pub_company, b.pub_year, b.type, b.price, b.amount);
		else
			fprintf(temp_f, "\n");
	}
	fclose(f);
	fclose(temp_f);
	remove(fBOOK);
	rename("temp.txt", fBOOK);
	f = fopen(fBOOK, "r+t");
}

void updateBookInfo(FILE*& f) {
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	/*int ord;
	char name[LENGTH_MAX];
	printf("Nhap ten quyen sach can thay doi thong tin: ");
	std::cin.ignore();
	fgets(name, sizeof(name), stdin);
	fflush(stdin);
	name[strlen(name) - 1] = '\0';
	ord = findBookByName(name, f);
	readBook(b, ord, f);*/
	int choice;
	fillBook(b, f);
	do {
		printf("Thong tin cua quyen sach: %s\n", b.name);
		printf("1. Ten sach       : %s\n", b.name);
		printf("2. ISBN           : %s\n", b.ISBN);
		printf("3. Tac gia        : %s\n", b.author);
		printf("4. Nha xuat ban   : %s\n", b.pub_company);
		printf("5. Nam xuat ban   : %d\n", b.pub_year);
		printf("6. The loai       : %s\n", b.type);
		printf("7. Gia sach       : %d\n", b.price);
		printf("8. So quyen       : %d\n", b.amount);
		printf("0. Quay lai\n");
		printf("============================================================\n\n");
		printf(" >> Chon thong tin ban muon cap nhat: ");
		fflush(stdout);
		scanf("%d", &choice);
		switch (choice) {
		case 1: {
			char temp_string[LENGTH_MAX];
			printf("Nhap ten sach moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, b.name);
			writeBook(b, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 2: {
			char temp_string[LENGTH_MAX];
			printf("Nhap ma sach moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, b.ISBN);
			writeBook(b, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 3: {
			char temp_string[LENGTH_MAX];
			printf("Nhap ten tac gia moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, b.author);
			writeBook(b, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 4: {
			char temp_string[LENGTH_MAX];
			printf("Nhap nha xuat ban moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, b.pub_company);
			writeBook(b, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 5: {
			printf("Nhap nam xuat ban moi: ");
			scanf("%d", &b.pub_year);
			writeBook(b, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 6: {
			char temp_string[LENGTH_MAX];
			printf("Nhap the loai moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, b.type);
			writeBook(b, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 7: {
			printf("Nhap gia sach moi: ");
			scanf("%d", &b.price);
			writeBook(b, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 8: {
			printf("Nhap so quyen sach moi: ");
			scanf("%d", &b.amount);
			writeBook(b, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 0: {
			return;
		}
		default: {
			printf("Nhap sai!\n");
			system("pause");
			break;
		}
		}
	} while (choice);
	rewind(f);
}

void createBook(FILE*& f) {
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX];
	int n;
	Book b_add, b_temp;
	fscanf(f, "%d\n", &n);
	printf("Nhap ID : ");
	std::cin.ignore();
	scanf("%[^\n]%*c", temp_string);
	copyString_statictodynamic(temp_string, b_add.ISBN);
	for (int i = 1; i <= n; i++) {
		readBook(b_temp, i, f);
		if (_stricmp(b_temp.ISBN, b_add.ISBN) == 0) {
			printf("Nguoi dung nay ton tai!\n");
			return;
		}
		fscanf(f, "%[^\n]\n", &temp_string);
	}
	printf("Nhap ten sach: "); scanf("%[^\n]%*c", temp_string); copyString_statictodynamic(temp_string, b_add.name);
	printf("Nhap ten tac gia: "); scanf("%[^\n]%*c", temp_string); copyString_statictodynamic(temp_string, b_add.author);
	printf("Nhap nha xuat ban:  "); scanf("%[^\n]%*c", temp_string); copyString_statictodynamic(temp_string, b_add.pub_company);
	printf("Nhap nam xuat ban: "); scanf("%d", &b_add.pub_year); cin.ignore();
	printf("Nhap the loai: "); scanf("%[^\n]%*c", temp_string); copyString_statictodynamic(temp_string, b_add.type);
	printf("Nhap gia sach: "); scanf("%d", &b_add.price);
	printf("Nhap so quyen: "); scanf("%d", &b_add.amount);
	b_add.ord_numb = n + 1;
	writeBook(b_add, f);
	fseek(f, 0, SEEK_SET);
	fprintf(f, "%d", n + 1);
	printf("\nDa tao thong tin quyen sach co ma sach: %s\n", b_add.ISBN);
	rewind(f);
}

void readBook_array(FILE* f, int* ord, Book* arr, int n) {
	for (int i = 0; i < n; i++) {
		readBook(arr[i], ord[i], f);
	}
}

void outputBook(Book& b) {
	printf("%3d|", b.ord_numb);
	printf("%10s|", b.ISBN);
	printf("%30s|", b.name);
	printf("%25s|", b.author);
	printf("%20s|", b.pub_company);
	printf("%12d|", b.pub_year);
	printf("%15s|", b.type);
	printf("%10d|", b.price);
	printf("%9d|", b.amount);
	printf("\n");
}

int chooseBook(Book* arr, int n) {
	int choice;
	printf("Chon cac doc gia sau day :\n");
	for (int i = 0; i < n; i++)
	{
		printf("(%d)", i);
		outputBook(arr[i]);
	}
	scanf("%d", &choice);
	return choice;
}

void readBook_all(FILE* f) {
	if (f == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return;
	}
	Book b;
	char temp[LENGTH_MAX];
	int n;
	rewind(f);
	fscanf(f, "%d", &n);
	printf("%3s|%10s|%30s|%25s|%20s|%12s|%15s|%10s|%9s|\n", "STT", "ISBN", "Ten sach", "Tac gia", "Nha xuat ban", "Nam xuat ban", "The loai", "Gia sach", "So quyen");
	for (int i = 1; i <= n; i++) {
		fscanf(f, "%d,", &b.ord_numb);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, b.ISBN);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, b.name);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, b.author);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, b.pub_company);
		fscanf(f, "%d,", &b.pub_year);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, b.type);
		fscanf(f, "%d,%d\n", &b.price, &b.amount);
		outputBook(b);
	}
	rewind(f);
}

void findBookByISBN_interface(Book& b,FILE* f) {
	char ISBN_numb[LENGTH_MAX];
	int ord[100], n, choice; // 100 thang trung ten nhau la het co~
	Book bArray[100];
	printf("Nhap ma sach: "); cin.ignore(); scanf("%[^\n]%*c", ISBN_numb);
	if ((n = findBookByISBN(ISBN_numb, f, ord)) <= 0)
	{
		printf("Khong tim thay sach!");
		return;
	}
	readBook_array(f, ord, bArray, n);
	choice = chooseBook(bArray, n);
	readBook(b, ord[choice], f);
}

void findBookByISBN_interface(Book& b, FILE* f,char* ISBN_numb) {
	
	int ord[100], n, choice; // 100 thang trung ten nhau la het co~
	Book bArray[100];
	if ((n = findBookByISBN(ISBN_numb, f, ord)) <= 0)
	{
		printf("Khong tim thay sach!");
		return;
	}
	readBook_array(f, ord, bArray, n);
	choice = chooseBook(bArray, n);
	readBook(b, ord[choice], f);
}
void findBookByName_interface(Book& b, FILE* f) {
	char name[LENGTH_MAX];
	int ord[100], n, choice; // 100 thang trung ten nhau la het co~
	Book bArray[100];
	printf("Nhap ten sach: "); cin.ignore(); scanf("%[^\n]%*c", name);
	if ((n = findBookByName(name, f, ord)) <= 0)
	{
		printf("Khong tim thay sach!");
		return;
	}
	readBook_array(f, ord, bArray, n);
	choice = chooseBook(bArray, n);
	readBook(b, ord[choice], f);
}

void freeBook() {
	free(b.ISBN); b.ISBN = NULL;
	free(b.name); b.name = NULL;
	free(b.author); b.author = NULL;
	free(b.pub_company); b.pub_company = NULL;
	free(b.type); b.type = NULL;
}

void fillBook(Book& b, FILE* f) {
	int choice = 0;
	if (b.name != NULL)
	{
		printf("Ban co muon tiep tuc thao tac sa'ch da chon khong?(0 - no)(1 - yes)\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
		{
			freeBook();
			break;
		}
		default:
			break;
		}
	}
	while (b.name == NULL) {
		printf("Vui long lua chon sach de tiep tuc bang cac cach sau :\n");
		printf("(1) Chon sach dua vao ten sach \n");
		printf("(2) Chon sach dua vao ma sach \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: {
			findBookByName_interface(b,f);
			break;
		}
		case 2: {
			findBookByISBN_interface(b,f);
			break;
		}
		default:
			break;
		}
	}
}

void deleteBook(Book b, FILE* f) {
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX * 4] = "\0";
	FILE* temp_f = fopen("temp.txt", "w+");
	int line = 0; int ord;
	int n; fscanf(f, "%d\n", &n);
	n--;
	fprintf(temp_f, "%d\n", n);
	while (!feof(f)) {
		fscanf(f, "%d,%[^\n]\n", &ord, temp_string);
		line++;
		if (line == b.ord_numb)
		{
			line--;
			continue;
		}
		else
		{
			fprintf(temp_f, "%d,%s\n", line, temp_string);
		}
	}
	//while (line < r.ord_numb) {
	//	line++;
	//	if (line == r.ord_numb)
	//	{
	//		char* birth_string = convertDatetoString(r.birth);
	//		char* mfg_string = convertDatetoString(r.mfg);
	//		char* exp_string = convertDatetoString(r.exp);
	//		fprintf(temp_f, "%d,%s,%s,%s,%s,%d,%s,%s,%s,%s\n"
	//			, r.ord_numb, r.ID, r.name, r.identify_numb, birth_string, r.sex, r.email, r.address, mfg_string, exp_string);
	//	}
	//	else
	//	{
	//		fprintf(temp_f, "\n");
	//	}
	//}
	fclose(f);
	fclose(temp_f);
	remove(fBOOK);
	rename("temp.txt", fBOOK);
	f = fopen(fBOOK, "r");
}

void deleteBook_interface(FILE* f) {
	fillBook(b, f);
	deleteBook(b, f);
	freeBook();
	printf("Da xoa sach thanh cong!\n");
}