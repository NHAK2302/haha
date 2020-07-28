#include "Reader.h"
Reader r;

void readReader(Reader& r, int ord, FILE* f) {
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
	fscanf(f, "%d,", &r.ord_numb);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, r.ID);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, r.name);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, r.identify_numb);
	fscanf(f, "%[^,],", &temp);
	r.birth = convertStringtoDate(temp);
	fscanf(f, "%d,", &r.sex);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, r.email);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, r.address);
	fscanf(f, "%[^,],", &temp);
	r.mfg = convertStringtoDate(temp);
	fscanf(f, "%[^\n]\n", &temp);
	r.exp = convertStringtoDate(temp);
	rewind(f);
}

void writeReader(Reader& r, FILE*& f) {
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
	if (n < r.ord_numb)
	{
		n++;
	}
	fprintf(temp_f, "%d\n", n);
	while (!feof(f)) {
		fscanf(f, "%[^\n]\n", temp_string);
		line++;
		if (line == r.ord_numb)
		{
			char* birth_string = convertDatetoString(r.birth);
			char* mfg_string = convertDatetoString(r.mfg);
			char* exp_string = convertDatetoString(r.exp);
			fprintf(temp_f, "%d,%s,%s,%s,%s,%d,%s,%s,%s,%s\n"
				, r.ord_numb, r.ID, r.name, r.identify_numb, birth_string, r.sex, r.email, r.address, mfg_string,exp_string);
		}
		else
		{
			fprintf(temp_f, "%s\n", temp_string);
		}
	}
	while (line < r.ord_numb) {
		line++;
		if (line == r.ord_numb)
		{
			char* birth_string = convertDatetoString(r.birth);
			char* mfg_string = convertDatetoString(r.mfg);
			char* exp_string = convertDatetoString(r.exp);
			fprintf(temp_f, "%d,%s,%s,%s,%s,%d,%s,%s,%s,%s\n"
				, r.ord_numb, r.ID, r.name, r.identify_numb, birth_string, r.sex, r.email, r.address, mfg_string, exp_string);
		}
		else
		{
			fprintf(temp_f, "\n");
		}
	}
	fclose(f);
	fclose(temp_f);
	remove(fREADER);
	rename("temp.txt", fREADER);
	f = fopen(fREADER, "r");
}

int findReaderByIdenNumb(char* ID, FILE* f,int* result) { //tim theo CMND, tra ve so luong , tra ve -1 neu file loi, 0 neu khong tim thay
	if (f == NULL||result==NULL)
	{
		printf(".csv not found or memory error! ReadCSV failed \n");
		return -1;
	}
	int k = 0;
	char trash[LENGTH_MAX];
	int ord;
	char ID_temp[LENGTH_MAX];
	rewind(f);
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%d,%[^,],%[^,],%[^,],", &ord, &trash, &trash, &ID_temp);
		if (_stricmp(ID, ID_temp) == 0)
		{
			result[k++] = ord;
		}
		fscanf(f, "%[^\n]\n", trash);
	}
	rewind(f);
	return k;
}

void findReaderByIdenNumb_interface(Reader& r,FILE* f)
{
	char ID_numb[LENGTH_MAX];
	int ord[100], n, choice; // 100 thang trung ten nhau la het co~
	Reader rArray[100];
	printf("Nhap CMND nguoi doc :"); cin.ignore(); scanf("%[^\n]%*c", ID_numb);
	if ((n = findReaderByIdenNumb(ID_numb,f,ord)) <= 0)
	{
		printf("Khong tim thay doc gia!");
		return;
	}
	readReader_array(f, ord, rArray, n);
	choice = chooseReader(rArray, n);
	readReader(r, ord[choice], f);
}

void findReaderByName_interface(Reader& r,FILE* f)
{
	char name[LENGTH_MAX];
	int ord[100], n, choice; // 100 thang trung ten nhau la het co~
	Reader rArray[100];
	printf("Nhap ho ten nguoi doc :"); cin.ignore(); scanf("%[^\n]%*c", name);
	if ((n = findReaderByName(name, f, ord)) <= 0)
	{
		printf("Khong tim thay doc gia!");
		return;
	}
	readReader_array(f, ord, rArray, n);
	choice = chooseReader(rArray, n);
	readReader(r, ord[choice], f);
}

int findReaderByName(char* name, FILE* f, int* result)
{ //tim theo ho ten, tra ve so ket qua?
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

void updateReaderInfo(FILE*& f)
{
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	//int ord;
	//char name[LENGTH_MAX];
	//printf("Nhap ho ten doc gia can thay doi thong tin: ");
	//std::cin.ignore();
	//fgets(name, sizeof(name), stdin);
	//fflush(stdin);
	//name[strlen(name) - 1] = '\0';
	//ord = findReaderByName(name, f);
	//readReader(r, ord, f);
	int choice = 0;
	fillReader(r, f);

	do {
		printf("Thong tin cua doc gia: %s\n", r.name);
		printf("1. Ho ten        : %s\n", r.name);
		printf("2. CMND          : %s\n", r.identify_numb);
		printf("3. Ngay sinh     : %d/%d/%d\n", r.birth.d, r.birth.m, r.birth.y);
		printf("4. Gioi tinh     : ");
		if (r.sex) {
			printf("Nam\n");
		}
		else {
			printf("Nu\n");
		}
		printf("5. Email         : %s\n", r.email);
		printf("6. Dia chi       : %s\n", r.address);
		printf("0. Quay lai\n");
		printf("============================================================\n\n");
		printf(" >> Chon thong tin ban muon cap nhat: ");
		fflush(stdout);
		scanf("%d", &choice);
		switch (choice) {
		case 1: {
			char temp_string[LENGTH_MAX];
			printf("Nhap ho ten moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, r.name);
			writeReader(r, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 2: {
			char temp_string[LENGTH_MAX];
			printf("Nhap CMND moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, r.identify_numb);
			writeReader(r, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 3: {
			printf("Nhap ngay sinh moi:\n");
			printf("Ngay: ");
			scanf("%d", &r.birth.d);
			printf("Thang: ");
			scanf("%d", &r.birth.m);
			printf("Nam: ");
			scanf("%d", &r.birth.y);
			writeReader(r, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 4: {
			printf("Chon gioi tinh (1: Nam/ 0: Nu)\n");
			scanf("%d", &r.sex);
			writeReader(r, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 5: {
			char temp_string[LENGTH_MAX];
			printf("Nhap email moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, r.email);
			writeReader(r, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 6: {
			char temp_string[LENGTH_MAX];
			printf("Nhap CMND moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, r.address);
			writeReader(r, f);
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

void createReader(FILE*& f) {
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX];
	int n;
	Reader r_add, r_temp;
	fscanf(f, "%d\n", &n);
	printf("Nhap ma doc gia : ");
	cin.ignore();
	scanf("%[^\n]%*c", temp_string);
	copyString_statictodynamic(temp_string, r_add.ID);
	for (int i = 1; i <= n; i++) {
		readReader(r_temp, i, f);
		if (_stricmp(r_temp.ID, r_add.ID) == 0) {
			printf("Nguoi dung nay da ton tai!\n");
			return;
		}
		fscanf(f, "%[^\n]\n", &temp_string);
	}
	printf("Nhap ho ten: "); scanf("%[^\n]%*c", temp_string); copyString_statictodynamic(temp_string, r_add.name);
	printf("Nhap CMND: "); scanf("%[^\n]%*c", temp_string); copyString_statictodynamic(temp_string, r_add.identify_numb);
	printf("Nhap ngay sinh \n");
	printf("Ngay: ");
	scanf("%d", &r_add.birth.d);
	printf("Thang: ");
	scanf("%d", &r_add.birth.m);
	printf("Nam: ");
	scanf("%d", &r_add.birth.y);	
	printf("Nhap gioi tinh ( 0- Nu / 1 - Nam) : "); scanf("%d", &r_add.sex); cin.ignore();
	printf("Nhap email: "); scanf("%[^\n]%*c", temp_string); copyString_statictodynamic(temp_string, r_add.email);
	printf("Nhap dia chi: "); scanf("%[^\n]%*c", temp_string); copyString_statictodynamic(temp_string, r_add.address);
	printf("Nhap ngay lap the: \n"); 	
	printf("Ngay: ");
	scanf("%d", &r_add.mfg.d);
	printf("Thang: ");
	scanf("%d", &r_add.mfg.m);
	printf("Nam: ");
	scanf("%d", &r_add.mfg.y);
	printf("Nhap ngay het han the: \n"); 
	printf("Ngay: ");
	scanf("%d", &r_add.exp.d);
	printf("Thang: ");
	scanf("%d", &r_add.exp.m);
	printf("Nam: ");
	scanf("%d", &r_add.exp.y);
	r_add.ord_numb = n + 1;
	writeReader(r_add, f);
	//fseek(f, 0, SEEK_SET);
	//fprintf(f, "%d", n + 1);
	printf("\nDa tao doc gia co ma doc gia: %s\n", r_add.ID);
	rewind(f);
}

void readReader_all(FILE* f) {
	if (f == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return;
	}
	Reader r;
	char temp[LENGTH_MAX];
	int n; 
	rewind(f);
	fscanf(f, "%d", &n); // dong da`u
	printf("%3s|%10s|%25s|%12s|%12s|%3s|%25s|%22s|%12s|%12s|\n","STT","Ma doc gia", "Ho ten", "CMND","Ngay sinh","Sex","Email","Dia chi","Ngay lap the","Ngay het han");
	for (int i = 1; i <= n ; i++)
	{
		fscanf(f, "%d,", &r.ord_numb);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, r.ID);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, r.name);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, r.identify_numb);
		fscanf(f, "%[^,],", &temp);
		r.birth = convertStringtoDate(temp);
		fscanf(f, "%d,", &r.sex);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, r.email);
		fscanf(f, "%[^,],", &temp);
		copyString_statictodynamic(temp, r.address);
		fscanf(f, "%[^,],", &temp);
		r.mfg = convertStringtoDate(temp);
		fscanf(f, "%[^\n]\n", &temp);
		r.exp = convertStringtoDate(temp);
		outputReader(r);
	}
	rewind(f);
}

void outputReader(Reader& r)
{
	printf("%3d|", r.ord_numb);
	printf("%10d|", r.ID);
	printf("%25s|", r.name);
	printf("%12s|", r.identify_numb);
	char* date_string = convertDatetoString(r.birth);
	printf("%12s|", date_string);
	if (r.sex)
		printf("%3s|","nam");
	else
		printf("%3s|","nu");
	printf("%25s|", r.email);
	printf("%22s|", r.address);
	date_string = convertDatetoString(r.mfg);
	printf("%12s|", date_string);
	date_string = convertDatetoString(r.exp);
	printf("%12s|", date_string);
	printf("\n");
}

void readReader_array(FILE* f, int* ord, Reader* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		readReader(arr[i], ord[i], f);
	}
}

int chooseReader(Reader* arr, int n)
{
	int choice;
	printf("Chon cac doc gia sau day :\n");
	for (int i = 0; i < n; i++)
	{
		printf("(%d)", i);
		outputReader(arr[i]);
	}
	scanf("%d", &choice);
	return choice;
}

void freeReader()
{
	free(r.ID);
	free(r.name);
	free(r.identify_numb);
	free(r.email);
	free(r.address);
}

void deleteReader_interface(FILE* f)
{
	fillReader(r,f);
	deleteReader(r, f);
	freeReader();
	printf("Xoa doc gia thanh cong!\n");
}

void deleteReader(Reader r,FILE* f)
{
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
		fscanf(f, "%d,%[^\n]\n",&ord, temp_string);
		line++;
		if (line == r.ord_numb)
		{
			line--;
			continue;
		}
		else
		{
			fprintf(temp_f, "%d,%s\n",line, temp_string);
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
	remove(fREADER);
	rename("temp.txt", fREADER);
	f = fopen(fREADER, "r");
}

void fillReader(Reader& r,FILE* f)
{
	int choice = 0;
	if (r.name != NULL)
	{
		printf("Ban co muon tiep tuc thao tac doc gia da chon khong?(0 - no)(1 - yes)\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
		{
			freeReader();
			break;
		}
		default:
			break;
		}
	}
	while (r.name == NULL) {
		printf("Vui long lua chon doc gia de tiep tuc bang cac cach sau :\n");
		printf("(1) Chon doc gia dua vao Ho ten \n");
		printf("(2) CHon doc gia dua vao so CMND \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: {
			findReaderByName_interface(r,f);
			break;
		}
		case 2: {
			findReaderByIdenNumb_interface(r,f);
			break;
		}
		default:
			break;
		}

	}
}
