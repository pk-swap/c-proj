#include<stdio.h>
	int balance[]={50000,60000,70000,800000,900000};
	
	int bal_check(int account)
	{

	printf("Your current balance is: %d\n", balance[account]);	
	};
	int cas_dep(int account)
	{
		int amount;//printf
		printf("enter the amount to be deposited=\n");
	scanf("%d",&amount);
	balance[account]=balance[account]+amount;
	printf("Your new balance is %d\n",balance[account]);//problem here	
	}	
	;
	int cas_withdr(int account)
	{
		int amount;//printf
		printf("enter the amount to be withdrawn=\n");
    scanf("%d", &amount); 
		if(amount<=balance[account])
		{
	balance[account]=balance[account]-amount;//problem here
	printf("Transaction is successful. Please collect your money.\n");	
	}
	else{
		printf("Insufficient balance so transaction failure.\n");
	}
	};
	int pin_cha()
	{
		char choice;
		int new,old,otp;
			printf("Do You Want To Change Your Password ? y/n=\n");
			scanf(" %c",&choice);
		if(choice=='y'||choice=='Y')
		{
			printf("Enter your previous pin=\n ");
			scanf("%d",&old);
			printf("Fill the otp number=\n");//scanf
			scanf("%d",&otp);
			printf("Now enter the new pin=\n");
			scanf("%d",&new);
			printf("Pin change process  now is complete.\n");
		}
		else
		{
			printf("Pin change process is canceled.\n");
		}
	};
	
	
	int save_balance()
{
    FILE *fptr ;
	fptr= fopen("atm.txt", "w+");
    if (fptr == NULL) {
        printf("Error!\n");
        return 1;
    }
    else
    {
    	printf("file opened successfully\n");
	}
    
    for (int i = 0; i < 5; i++) {
        fprintf(fptr, "%d %d\n", i, balance[i]);
    }
    fclose(fptr);
}

	
	
	
	
	int load_balance()
{
    FILE *fp;
	fp = fopen("atm.txt", "r");
    if (fp == NULL) {
        printf("Error while opening file.\n");
        return 1;
    }
    else
    {
    printf("File opened successfully for reading\n");
	}

    int acc_num, bal;
    while (fscanf(fp, "%d %d\n", &acc_num, &bal) != EOF) {
        balance[acc_num] = bal;
    }
    fclose(fp);
}
	
	
	
	int main()
	{
	
	int choice=0;
	int pin,acc_num,valid=0,account;
	int valid_acc[]={1234,2345,3456,4567,5678};
	int valid_pin[]={1001,1002,1003,1004,1105};
	
	load_balance();
	
	printf("enter your account number=\n");
	scanf("%d",&acc_num);
	printf("Enter your  four digit pin code=");
	scanf("%d",&pin);
	for (int i = 0; i < 5; i++) {
				if(valid_pin[i]==pin && valid_acc[i]==acc_num)
	{
	
	valid = 1;
	account=i;
            break;
        }
	}
         if (valid) {
		printf("Connected to your account\n");	
	

	while (choice!=5)
	{
	
	//Main Menu
	printf("                    ATM Menu              \n");
	printf("1. Balance Inquery\n");
	printf("2.Cash Withdwral\n");
	printf("3.Deposit\n");
	printf("4. Change pin\n");//scanf bakichha
	printf("5. Exit\n");//correct
	
	printf("enter your choice=\n");
	if(scanf("%d",&choice)!=1)
	{
		printf("invalid imput.enter number=\n");
		while(getchar()!='n');
		continue;
	}
	
	switch(choice)
	{
	case 1:
		bal_check(account);
		
				//balancecheck
				break;
	case 2:
		cas_withdr(account);//problem here
				//cash withdrawl
				break;
	case 3:
		cas_dep(account);
					//cash deposit//update data problem
					break;
	case 4:
		pin_cha();
					//pin change
					break;
	
	case 5:
	printf("Thank you for choosing our ATM.\n Please visit again\n");	
		
		save_balance();				//exit
	return 0;					
	default:
	printf("Invalid choice ! Please choose the option again");
	}

    }
	}
	 else
	{
		printf("Invalid account number or pin.\n");
	}
return 0;}