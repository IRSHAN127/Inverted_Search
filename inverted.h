#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<ctype.h>
#include<errno.h>

//defining macros
#define FAILURE -1
#define SUCCESS  0
#define FNAME_SIZE 15
#define WORD_SIZE 10
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4

//structure for file list
typedef char data_t;

typedef struct file_node
{
	int check_database;
	data_t file_name[FNAME_SIZE];
	struct file_node *link;
}Flist;

//structure for link table
typedef struct linkTable_node
{
	int word_count;
	data_t file_name[FNAME_SIZE];
	struct linkTable_node *table_link;
}Ltable;

//structure to store word count
typedef struct word_node
{
	int file_count;
	data_t word[WORD_SIZE];
	Ltable * Tlink;
	struct word_node *link;
}Wlist;

//checking file in valid
void file_validation_n_file_list(Flist **f_head, char *argv[]);
//checking file
int isFileEmpty(char *filename);
//create list
int to_create_list_of_files(Flist **f_head,char *name);
//create database Wlist Tlist by flist
void create_database(Flist *f_head, Wlist *head[]);
//read contents of a file
Wlist* read_datafile(Flist *file, Wlist *head[], char *filename);
//create word_list
int insert_at_last(Wlist **head, data_t *data);
//update linktable
int update_link_table(Wlist **head);
//update word
int update_word_count(Wlist **head,char *file_name);
//print_word_count
int print_word_count(Wlist *head);
//searching a word
void search(Wlist *head, char *word);
//display
void display_database(Wlist *head[]);
//save_database
void save_database(Wlist *head[]);
//write data in file
void write_databasefile(Wlist *head, FILE* databasefile);
//update
void update_database(Wlist *head[], Flist **f_head);

#endif
