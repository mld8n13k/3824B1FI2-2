
#include <stdio.h>

#define MAX_FILES 10
#define MAX_FILENAME_LEN 256
#define MAX_FOLDERS 5

typedef struct {
	char name[MAX_FILENAME_LEN];
	int size;
} File;

typedef struct {
	char folder_name[MAX_FILENAME_LEN];
	File files[MAX_FILES];
	int file_count;
} Folder;


void BubbleSort(File files[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n - i - 1; j++) {
			if (files[j-1].size > files[j].size) {
				File tmp = files[j-1];
				files[j-1] = files[j];
				files[j] = tmp;
			}
		}
	}

}

void Selection(File files[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			if (files[j].size > files[min].size) {
				min = j;
			}
		}
		File tmp = files[i];
		files[i] = files[min];
		files[min] = tmp;

	}
}

void display_files(Folder folder) {
	printf("Files in folder '%s':\n", folder.folder_name);
	for (int i = 0; i < folder.file_count; i++) {
		printf("  %s - %d byte\n", folder.files[i].name, folder.files[i].size);
	}
}


int main(void) {
	int mode, folder_choice;

	Folder folders[MAX_FOLDERS] = {
		{"Folder 1", {{"text-123.txt", 100}, {"code-lab.txt", 800}, {"passwords.txt", 200}, {"logins.txt", 250}, {"programms.txt", 1500}}, 5},
		{"New folder", {{"report.txt", 2100}, {"project.txt", 1500}, {"python.txt", 100}, {"c++.txt", 900}, {"c#.txt", 1250}}, 5},
		{"CodeForces", {{"Task1.txt", 600}, {"Task2.txt", 500}, {"Task3.txt", 900}, {"Task4.txt", 400}, {"Task5.txt", 300}}, 5},
		{"Recipes", {{"Meat.txt", 1400}, {"Milkshake.txt", 500}, {"Burger.txt", 1000}, {"Chicken wings.txt", 350}, {"pilaf.txt", 1700}}, 5},
		{"Workout", {{"Bench press.txt", 750}, {"Armrestling.txt", 700}, {"pull-ups.txt", 500}, {"Block.txt", 300}, {"leg press.txt", 600}}, 5},
	};

	printf("Choose folder (0-4):\n");
	for (int i = 0; i < MAX_FOLDERS; i++) {
		printf("%d: %s\n", i, folders[i].folder_name);
	}
	scanf_s("%d", &folder_choice);

	if (folder_choice < 0 || folder_choice >= MAX_FOLDERS) {
		printf("Uncorrect choice.\n");
		return 1;
	}

	int n = folders[folder_choice].file_count;
	display_files(folders[folder_choice]);

	printf("Choose mode (1 - buble sort, 2 - selection sort):\n");
	scanf_s("%d", &mode);

	if (mode == 1) {
		BubbleSort(folders[folder_choice].files, n);
	}
	else if (mode == 2) {
		Selection(folders[folder_choice].files, n);
	}
	else {
		printf("mode 1 or mode 2 \n");
		return 1;
	}
	printf("Files sorted:\n");
	display_files(folders[folder_choice]);

	return 0;
}
