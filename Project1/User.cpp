#include "User.h"

int loginUser(User& u,FILE* f) //tra ve ti`nh trang log
{
	int ord,choice;
	char temp_string[LENGTH_MAX];
	printf("ID : ");
	scanf("%s", &temp_string);
	if ((ord = findUser(temp_string, f)) < 0)
	{
		printf("Tai khoan khong ton tai!\n");
		rewind(f);
		return 0;
	}
	printf("Password : ");
	scanf("%s", &temp_string);
	if (checkpassUser(ord, temp_string, f) == 0)
	{
		do
		{
			printf("Sai mat khau!\n");
			printf("Ban co muon nhap lai mat khau? (1 : co / 0 : khong) : ");
			scanf("%d", &choice);
			if (!choice)
			{
				rewind(f);
				return 0;
			}
			printf("Password : ");
			scanf("%s", &temp_string);
		} while (checkpassUser(ord, temp_string, f) == 0);
	}
	readUser(u, ord, f);
	if (u.status == 0)
	{
		printf("Tai khoan cua ban da bi khoa! Vui long dang nhap lai bang tai khoan khac! \n");
		return 0;
	}
	printf("Dang nhap thanh cong ! \n");
	return u.type;

}
void logoutUser(User& u, int& log)
{
	free(u.ID);
	free(u.password);
	free(u.name);
	free(u.identify_numb);
	free(u.address);
	log = 0;
}
int findUser(char* name,FILE* f) //tra ve number(STT), -1 la khong tim thay
{
	if (f == NULL)
	{
		printf(".csv not found! findUser failed \n");
		return -1;
	}
	char trash[LENGTH_MAX];
	int ord;
	char name_temp[LENGTH_MAX];
	rewind(f);
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%d,%[^,],", &ord, &name_temp);
		if (strcmp(name, name_temp) == 0)
		{
			rewind(f);
			return ord;
		}
		fscanf(f, "%[^\n]\n", trash);
	}
	rewind(f);
	return -1;
}
int checkpassUser(int ord,char* pass, FILE* f) //chua xong
{
	if (f == NULL) {
		printf(".csv not found! checkpassUser failed \n");
		return 0;
	}
	rewind(f);
	char trash[LENGTH_MAX];
	int n, status;
	char pass_legit[LENGTH_MAX];
	fscanf(f,"%d\n", &n);
	// di den line ord
	for (int i = 1; i <= ord-1; i++)
	{
		fscanf(f, "%[^\n]\n", trash);
	}
	fscanf(f, "%[^,],%[^,],%[^,]", &trash, &trash, &pass_legit);
	if (strcmp(pass_legit, pass) == 0)
	{
		rewind(f);
		return 1;
	}
	else
	{
		rewind(f);
		return 0;
	}
}
void readUser(User& u,int ord, FILE* f)
{
	if (f == NULL)
	{
		printf(".csv not found! ReadUser failed \n");
		return;
	}
	char temp[LENGTH_MAX];
	int n; fscanf(f, "%d\n", &n); // dong da`u
	for (int i = 1; i <= ord - 1; i++)
	{
		fscanf(f, "%[^\n]\n", temp);
	}
	fscanf(f, "%d,", & u.ord_numb);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, u.ID);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, u.password);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, u.name);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, u.identify_numb);
	fscanf(f, "%[^,],", &temp);
	copyString_statictodynamic(temp, u.address);
	fscanf(f, "%[^,],", &temp);
	u.birth=convertStringtoDate(temp);
	fscanf(f, "%d,%d,%d", &u.sex,&u.status,&u.type);
	rewind(f);
}
void writeUser(User& u, FILE*& f)
{
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX * 4] = "\0";
	FILE* temp_f = fopen("temp.txt", "w+t");
	int line = 0;
	int n; fscanf(f, "%d\n", &n);
	if (n < u.ord_numb)
	{
		n++;
	}
	fprintf(temp_f, "%d\n", n);
	while (!feof(f))
	{
		fscanf(f, "%[^\n]\n", temp_string);
		line++;
		if (line == u.ord_numb)
		{
			fprintf(temp_f, "%d,%s,%s,%s,%s,%s,%d/%d/%d,%d,%d,%d\n"
				, u.ord_numb, u.ID, u.password, u.name, u.identify_numb, u.address, u.birth.d, u.birth.m, u.birth.y,u.sex,u.status,u.type);
		}
		else
		{
			fprintf(temp_f, "%s\n", temp_string);
		}
	}
	while (line < u.ord_numb)
	{
		if (line == u.ord_numb)
			fprintf(temp_f, "%d,%s,%s,%s,%s,%s,%d/%d/%d,%d,%d,%d\n"
				, u.ord_numb, u.ID, u.password, u.name, u.identify_numb, u.address, u.birth.d, u.birth.m, u.birth.y, u.sex, u.status, u.type);
		else
			fprintf(temp_f, "\n");
		line++;
	}
	fclose(f);
	fclose(temp_f);
	remove(fUSER);
	rename("temp.txt", fUSER);
	f = fopen(fUSER, "r+t");
}
void updateUserInfo(User& u, FILE* &f) {
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	
	int choice;
	do {
		printf("Nhung thong tin co the duoc cap nhat\n");
		printf("1. Ho ten        : %s\n",u.name);
		printf("2. Ngay sinh     : %d/%d/%d\n",u.birth.d,u.birth.m,u.birth.y);
		printf("3. CMND          : %s\n",u.identify_numb);
		printf("4. Dia chi       : %s\n",u.address);
		printf("5. Gioi tinh     : ");
		if (u.sex) {
			printf("Nam\n");
		}
		else {
			printf("Nu\n");
		}
		printf("6. Tinh trang    : ");
		if (u.status) {
			printf("Activated\n");
		}
		else {
			printf("Blocked\n");
		}
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
			temp_string[strlen(temp_string)-1] = '\0';
			copyString_statictodynamic(temp_string, u.name);
			writeUser(u, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}

		case 2: {
			printf("Nhap ngay sinh moi:\n");
			printf("Ngay: ");
			scanf("%d", &u.birth.d);
			printf("Thang: ");
			scanf("%d", &u.birth.m);
			printf("Nam: ");
			scanf("%d", &u.birth.y);
			// chua xong
			writeUser(u, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 3: {
			char temp_string[LENGTH_MAX];
			printf("Nhap CMND moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, u.identify_numb);
			writeUser(u, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 4: {
			char temp_string[LENGTH_MAX];
			printf("Nhap dia chi moi: ");
			std::cin.ignore();
			fgets(temp_string, sizeof(temp_string), stdin);
			fflush(stdin);
			temp_string[strlen(temp_string) - 1] = '\0';
			copyString_statictodynamic(temp_string, u.address);
			writeUser(u, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 5: {
			printf("Chon gioi tinh (1: Nam/ 0: Nu)\n");
			scanf("%d", &u.sex);
			writeUser(u, f);
			printf("Cap nhat thanh cong\n");
			system("pause");
			break;
		}
		case 6: {

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

	} while (choice != 0);
	rewind(f);
}
void updatePass(User& u, FILE* f) { //con 1 ty bug
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX];
	int ord, choice;
	printf("Nhap mat khau hien tai: ");
	scanf("%s", &temp_string);
	ord = findUser(u.name, f);
	if (checkpassUser(ord, temp_string, f) == 0)
	{
		do
		{
			printf("Sai mat khau!\n");
			printf("Ban co muon nhap lai mat khau? (1 : co / 0 : khong) : ");
			scanf("%d", &choice);
			if (!choice)
			{
				rewind(f);
				return;
			}
			printf("Nhap mat khau hien tai : ");
			scanf("%s", &temp_string);
		} while (checkpassUser(ord, temp_string, f) == 0);
	}
	printf("Nhap mat khau moi: ");
	std::cin.ignore();
	fgets(temp_string, sizeof(temp_string), stdin);
	fflush(stdin);
	temp_string[strlen(temp_string) - 1] = '\0';
	copyString_statictodynamic(temp_string, u.password);
	writeUser(u, f);
	printf("Da thay doi mat khau thanh cong!\n");
	rewind(f);
} 
//chua xong

void giveUser_status(User& u, FILE* f) {
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	int ord;
	char name[LENGTH_MAX];
	printf("Nhap ten nguoi dung ban muon phan quyen: ");
	std::cin.ignore();
	fgets(name, sizeof(name), stdin);
	fflush(stdin);
	name[strlen(name) - 1] = '\0';
	ord = findUser(name, f);
	printf("Nguoi nay se co chuc vu gi: (1: Chuyen vien/ 2: Quan ly): ");
	scanf("%d", &u.status);
	writeUser(u, f);
	rewind(f);
} 
// chua debug