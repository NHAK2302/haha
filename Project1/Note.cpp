#include"Note.h"
extern FILE* fReader;
extern FILE* fBook;

void createNote(FILE* f)
{
	if (f == NULL)
	{
		printf(".csv not found! writeUser failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX*4];
	int n_Note,n_book;
	fscanf(f, "%d", &n_Note); n_Note++;
	// prepare new file
	{
		FILE* temp_f = fopen("temp.txt", "w+t");
		fprintf(temp_f, "%d\n", n_Note);
		while (!feof(f))
		{
			fscanf(f, "%[^\n]\n", temp_string);
			fprintf(temp_f, "%s\n", temp_string);
		}
		fclose(f);
		fclose(temp_f);
		remove(fREADER);
		rename("temp.txt", fREADER);
		f = fopen(fREADER, "r");
	}
	Reader r;
	Book b;
	Date date; char* date_string;
	fillReader(r, fReader);
	fprintf(f, "%s,", r.ID);
	printf("Nhap ngay muon sach :\n");
	printf("Ngay: ");
	scanf("%d", &date.d);
	printf("Thang: ");
	scanf("%d", &date.m);
	printf("Nam: ");
	scanf("%d", &date.y);
	date_string=convertDatetoString(date);
	fprintf(f, "%s,", date_string);
	printf("Nhap ngay tra sach du kien :\n");
	printf("Ngay: ");
	scanf("%d", &date.d);
	printf("Thang: ");
	scanf("%d", &date.m);
	printf("Nam: ");
	scanf("%d", &date.y);
	date_string = convertDatetoString(date);
	fprintf(f, "%s,", date_string);
	printf("Nhap ngay tra sach  :\n");
	printf("Ngay: ");
	scanf("%d", &date.d);
	printf("Thang: ");
	scanf("%d", &date.m);
	printf("Nam: ");
	scanf("%d", &date.y);
	date_string = convertDatetoString(date);
	fprintf(f, "%s,", date_string);
	printf("Nhap so cuon sach muon : "); scanf("%d", &n_book);
	for (int i = 0; i < n_book; i++)
	{
		fillBook(b, fBook);
		fprintf(f, "%s\n", b.ISBN);
	}

}