#include"Note.h"
extern FILE* fReader;
extern FILE* fBook;
extern FILE* fBorrow;
void createBorrowNote(FILE*& f)
{
	if (f == NULL)
	{
		printf("required file not found! action failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX*4];
	int n_Note,n_book;
	fscanf(f, "%d\n", &n_Note); n_Note++;
	// prepare new file
	FILE* temp_f = fopen("temp.txt", "w+t");
	{
		fprintf(temp_f, "%d\n", n_Note);
		while (!feof(f))
		{
			fscanf(f, "%[^\n]\n", temp_string);

			fprintf(temp_f, "%s\n", temp_string);
		}

	}
	Reader r;
	r.name = NULL;
	Book b;
	b.name = NULL;
	Date date; char* date_string;
	fillReader(r, fReader);
	fprintf(temp_f, "%s,", r.ID);
	printf("Nhap ngay muon sach :\n");
	printf("Ngay: ");
	scanf("%d", &date.d);
	printf("Thang: ");
	scanf("%d", &date.m);
	printf("Nam: ");
	scanf("%d", &date.y);
	date_string=convertDatetoString(date); 
	fprintf(temp_f, "%s,", date_string);
	date = sau_k_ngay(date, 7);
	date_string = convertDatetoString(date);
	fprintf(temp_f, "%s,", date_string);

	printf("Nhap so cuon sach muon : "); scanf("%d", &n_book);
	fprintf(temp_f, "%d\n", n_book);
	for (int i = 0; i < n_book; i++)
	{
		fillBook(b, fBook);
		b.name = NULL;
		fprintf(temp_f, "%s\n", b.ISBN);
	}
	fclose(f);
	fclose(temp_f);
	remove(fBORROW);
	rename("temp.txt", fBORROW);
	f = fopen(fBORROW, "r+t");
}
void createReturnNote(FILE*& f)
{
	if (f == NULL)
	{
		printf("required file not found! action failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX * 4];
	int n_Note, n_book;
	fscanf(f, "%d\n", &n_Note); n_Note++;
	// prepare new file
	FILE* temp_f = fopen("temp.txt", "w+t");
	{
		fprintf(temp_f, "%d\n", n_Note);
		while (!feof(f))
		{
			fscanf(f, "%[^\n]\n", temp_string);

			fprintf(temp_f, "%s\n", temp_string);
		}

	}
	Note n; n.reader_ID = NULL;
	Date date; char* date_string;
	printf("Lap phieu tra sach dua tren phieu muon sach co tu truoc :\n");
	while(n.reader_ID==NULL)
		fillNote(n, fBorrow);
	fprintf(temp_f, "%s,", n.reader_ID);
	date_string = convertDatetoString(n.bor_date);
	fprintf(temp_f, "%s,", date_string);
	date_string = convertDatetoString(n.expe_date);
	fprintf(temp_f, "%s,", date_string);
	printf("Nhap ngay tra sach :\n");
	printf("Ngay: ");
	scanf("%d", &n.real_date.d);
	printf("Thang: ");
	scanf("%d", &n.real_date.m);
	printf("Nam: ");
	scanf("%d", &n.real_date.y);
	date_string = convertDatetoString(n.real_date);
	fprintf(temp_f, "%s,", date_string);
	fprintf(temp_f, "%d\n", n.book_number);
	int pay = 0,lose_all = 0;
	if ((_2dateDistanceByday(n.expe_date, n.real_date)) > 7)
	{
		printf("Da tren han qua 7 ngay, coi nhu tat ca cac sach dang muon bi mat!");
		lose_all = 1;
	}
	else
		printf("Cac ma sach sau day co bi mat khong? ((1) Co / (0)Khong\n");
	for (int i = 0; i < n.book_number; i++)
	{
		int lose = lose_all;
		if (lose == 0) {
			printf("Sach co ma ISBN %s :", n.book_ISBN[i]); scanf("%d", &lose);
		}
		if (lose == 1)
		{
			Book b;
			printf("Xac nhan sach bi ma^'t :\n");
			findBookByISBN_interface(b, fBook, n.book_ISBN[i]);
			pay += b.price * 2;
		}
		fprintf(temp_f, "%s,%d\n", n.book_ISBN[i], lose);
	}
	if (checkdate(n.expe_date,n.real_date)&&lose_all==0)
	{
		pay += _2dateDistanceByday(n.expe_date, n.real_date)*5;
	}
	printf("Tong so tien phai de`n : %d", pay);
		fprintf(temp_f,"%d\n",pay);
	fclose(f);
	fclose(temp_f);
	remove(fRETURN);
	rename("temp.txt", fRETURN);
	f = fopen(fRETURN, "r+t");
}
int findNote(char* name,FILE* f,Note* result)
{
	if (f == NULL) 
	{
		printf("required file not found! action failed \n");
		return -1;
	}
	rewind(f);
	Note check;
	int k=0;
	char trash[LENGTH_MAX * 4];
	char ID_temp[LENGTH_MAX];
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%[^,],%d/%d/%d,%d/%d/%d,%d\n", ID_temp, &check.bor_date.d, &check.bor_date.m, &check.bor_date.y, &check.expe_date.d, &check.expe_date.m, &check.expe_date.y, &check.book_number);

		if (_stricmp(name, ID_temp) == 0)
		{
			copyString_statictodynamic(ID_temp, check.reader_ID);
			result[k] = check;
			result[k].book_ISBN = (char**)calloc(check.book_number, sizeof(char*));
			for (int j = 0; j < check.book_number ; j++)
			{
				fscanf(f, "%[^\n]\n", trash);
				copyString_statictodynamic(trash, result[k].book_ISBN[j]);
			}
			k++;
		}
		else 
		{
			for (int j = 0; j < check.book_number ; j++)
			{
				fscanf(f, "%[^\n]\n", trash);
			}
		}
	}
	return k;
}
void fillNote(Note& n,FILE*f)
{
	char name[LENGTH_MAX];
	Note arr[100];int k, choice; // 100 thang trung ten nhau la het co~
	Reader rArray[100];
	printf("Nhap ma doc gia muon lap phieu tra sach :"); cin.ignore(); scanf("%[^\n]%*c", name);
	if ((k = findNote(name,f,arr)) <= 0)
	{
		printf("Khong tim thay phieu muon sach tu doc gia nay!\n");
		return;
	}
	readNote_array(arr, k);
	choice = chooseNote(arr, k);
	n = arr[choice];
}
void readNote_array(Note* arr,int n)
{
	char* temp_string=NULL;
	for (int i = 0; i < n; i++)
	{
		temp_string = convertDatetoString(arr[i].bor_date);
		printf("(%d)\nMa doc gia : %s\nNgay muon sach : %s\tNgay du kien tra sach: ",i,arr[i].reader_ID,temp_string);
		temp_string = convertDatetoString(arr[i].expe_date);
		printf("%s,so sach muon : %d \n", temp_string,arr[i].book_number);
		for (int j = 0; j < arr[i].book_number; j++)
		{
			printf("%s\n", arr[i].book_ISBN[j]);
		}
	}
	free((void*)temp_string);
}
int chooseNote(Note* arr, int n)
{
	int result;
	printf("Chon phieu muon sach tuong ung de tiep tuc :");
	scanf("%d", &result);
	return result;
}