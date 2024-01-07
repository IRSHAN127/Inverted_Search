#include "inverted.h"

void update_database(Wlist *head[], Flist **f_head)
{
	//prompt the user to enter new file name
	char file_name[FNAME_SIZE];

	printf("Enter the filname to update database :\n");
	scanf("%s",file_name);

	//validate 
	int empty = isFileEmpty(file_name);
	
	if(empty == FILE_NOTAVAILABLE)
	{
		printf("File : %s is not avaliable\n",file_name);
		printf("Hence we are not adding into file linked list\n");
	}
	else if(empty == FILE_EMPTY)
	{
		printf("File : %s is not having any content in it\n",file_name);
		printf("Hence we are not adding into file linked list\n");
	}
	else
	{
		int ret_val = to_create_list_of_files(f_head,file_name);
		//return value of func
		if(ret_val == SUCCESS)
		{
			printf("Successfull : insering the filename : %s into file linked list\n",file_name);
		}
		else if(ret_val == REPEATATION)
		{
			printf("This file name : %s is repeated . So do not add more than once\n",file_name);
			return ;
		}
		else
		{
			printf("FAILURE\n");
			return ;
		}
	}
	
	//add data in database for file if it validate and not repeated
	//call create database to add in data base
	while(*f_head)
	{
		if(!(strcmp((*f_head)->file_name,file_name)))
		{
			create_database(*f_head , head);
		}
			*f_head = (*f_head)->link;
	}

}
