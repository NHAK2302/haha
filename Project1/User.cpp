#include "User.h"

int loginUser(User& u,FILE* f) //tra ve ti`nh trang log
{
	int ord,choice;
	char temp_string[LENGTH_MAX];
	printf("ID : ");
	scanf("%s", &temp_string);
	if ((ord = findUser(temp_string, f)) < 0)
	{
		printf("Tai khoan khong ton tai !\n");
		rewind(f);
		return 0;
	}
	printf("Password : ");
	scanf("%s", &temp_string);
	if (checkpassUser(ord, temp_string, f) == 0)
	{
		printf("Sai mat khau!\n");
		do
		{
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
	printf("Dang nhap thanh cong ! \n");
	return u.status;

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
	fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],", &trash, &trash, &pass_legit, &trash, &trash, &trash, &trash, &trash, &status);
	if (strcmp(pass_legit, pass) == 0)
	{
		if (status == 0) {
			printf("This account is already blocked\n");
			rewind(f);
			return 0;
		}
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
	fscanf(f, "%d,%d,%d\n", &u.sex,&u.status,&u.type);
	rewind(f);
}