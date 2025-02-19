#include <stdio.h>
#include <string.h>


int func1(char* username){
	printf("Please enter your username: ");
	scanf("%s", username);
	return 0;
}


int func2(char* password)
{
	printf("Please enter your initial password: ");
	scanf("%s", password);
	return 0;
}

int func3(char* password){
	char enteredPassword[24];

	printf("Please re-enter your password: ");

	scanf("%s", enteredPassword);

	int rax = strcmp(enteredPassword, password);

	return rax;
}

int main()
{
	char username[16];
	char password[24];

	func1(username);
	func2(password);

	int rax = strcmp(username, password);
	if (rax == 0){
		puts("Usernames and passwords cannot be the same. Please enter a new initial password.");
	}
	else{
		int rax = func3(password);
		if (rax == 0)
		{
			puts("Your passwords matched. Congratulations!");
		}
		else
		{
			puts("Your passwords did not match. Try again.");
		}
	}
	return 0;
}
