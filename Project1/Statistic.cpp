#include "Statistic.h"
//Book b;
//Reader r;

int numbOfBooks_all(FILE* f) {
	if (f == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return -1;
	}
	Book b;
	char temp[LENGTH_MAX];
	int n;
	int result = 0;
	rewind(f);
	fscanf(f, "%d", &n);
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
		result += b.amount;
	}
	rewind(f);
	return result;
}

void numbOfBooks_type(FILE* f) {
	if (f == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return;
	}
	Book b;
	char* typeArr[LENGTH_MAX];
	int amountOfType = 0;
	int n;
	typeOfBooks(f, typeArr, amountOfType);
	rewind(f);
	fscanf(f, "%d", &n);
	int amountPerType[LENGTH_MAX] = { 0 };
	for (int i = 1; i <= n; i++) {
		readBook(b, i, f);
		for (int j = 0; j < amountOfType; j++) {
			if (_stricmp(b.type, typeArr[j]) == 0) {
				amountPerType[j] += b.amount;
			}
		}
	}
	printf("%12s|%9s|\n", "The loai", "So luong");
	for (int i = 0; i < amountOfType; i++) {
		printf("%12s|", typeArr[i]);
		printf("%9d|", amountPerType[i]);
		printf("\n");
	}
	rewind(f);
}

void typeOfBooks(FILE* f, char* typeArr[], int& amount) {
	if (f == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return ;
	}
	Book b;
	//char temp[LENGTH_MAX];
	int n;
	rewind(f);
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++) {
		readBook(b, i, f);
		strcpy(typeArr[i - 1], b.type);
	}
	amount = n;
	for (int i = 1; i < amount; i++) {
		for (int j = 0; j < i; j++) {
			if (_stricmp(typeArr[i], typeArr[j]) == 0) {
				for (int k = i; k < amount; k++) {
					strcpy(typeArr[k], typeArr[k + 1]);
					amount--;
					i--;
				}
			}
		}
	}
	rewind(f);
}

bool typeNotExist(char* typeArr[], int n, char* cur_type) {
	for (int i = 0; i < n; i++) {
		if (_stricmp(cur_type, typeArr[i]) == 0) {
			return false;
		}
	}
	return true;
}

int numbOfReaders_all(FILE* f) {
	if (f == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return -1;
	}
	int n;
	rewind(f);
	fscanf(f, "%d", &n);
	return n;
}

void numbOfReaders_sex(FILE* f) {
	if (f == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return;
	}
	Reader r;
	char temp[LENGTH_MAX];
	int n;
	int male = 0, female = 0;
	rewind(f);
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++)
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
		if (r.sex == 1) {
			male++;
		}
		else {
			female++;
		}
	}
	rewind(f);
	printf("Nam: %d\n", male);
	printf("Nu: %d\n", female);
}