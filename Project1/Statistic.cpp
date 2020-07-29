#include "Statistic.h"

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
	char typeArr[20][LENGTH_MAX];
	char temp[LENGTH_MAX];
	int amountOfType = 0;
	int n;
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
		if (typeNotExist(typeArr, amountOfType, b.type)) {
			strcpy(typeArr[amountOfType++], b.type);
		}
	}
	rewind(f);
	int ord[100];
	int amountPerType[20] = {};
	int n_temp;
	for (int i = 0; i < amountOfType; i++) {  //kiem tra tung the loai
		n_temp = findBookByType(typeArr[i], f, ord);  //tim sach co the loai nhu tren
		for (int j = 0; j < n_temp; j++) {
			readBook(b, ord[j], f);
			amountPerType[i] += b.amount;
		}
	}
	for (int i = 0; i < amountOfType; i++) {
		printf("%s: %d\n", typeArr[i], amountPerType[i]);
	}
	rewind(f);
}

bool typeNotExist(char typeArr[100][LENGTH_MAX], int n, char* cur_type) {
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

int numbOfBooks_borrowed(FILE* f1, FILE* f2) {
	if (f1 == NULL || f2 == NULL)
	{
		printf(".csv not found! ReadCSV failed \n");
		return -1;
	}
	int bBor = 0, bRet = 0;
	int n1, n2;
	int a[100], b[100];
	char trash[LENGTH_MAX];
	rewind(f1); rewind(f2);
	fscanf(f1, "%d\n", &n1); //check file return.txt
	for (int i = 0; i < n1; i++) {
		fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%d\n", &trash, &trash, &trash, &trash, a[i]);
		for (int j = 0; j <= a[i]; j++) {
			fscanf(f1, "[^\n]\n", &trash);
		}
		bRet += a[i];
	}
	rewind(f1);
	fscanf(f2, "%d\n", &n2); // check file borrow.txt
	for (int i = 0; i < n2; i++) {
		fscanf(f1, "%[^,],%[^,],%[^,],%d\n", &trash, &trash, &trash, b[i]);
		for (int j = 0; j <= b[i]; j++) {
			fscanf(f1, "[^\n]\n", &trash);
		}
		bBor += b[i];
	}
	rewind(f2);
	return bRet - bBor;
}