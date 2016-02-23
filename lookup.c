#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HASHSIZE 101
//list structure
struct nlist{
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtable[HASHSIZE];
unsigned hash1(char *);//hash function prototype
struct nlist *install_lookup(char *,char *);

struct nlist *lookup1(char *);

int main(){
	struct nlist *harisu_test;
	char name[20],definition[20];
		printf("name, definition\n");
		scanf("%s",definition);
		scanf("%s",name);
		harisu_test=install_lookup(name,definition);

	return 0;
}


//generate the index to be used in the lookup table for storing the name and definition of the string *s
unsigned hash1(char *s){
	unsigned hash_value;
	for(hash_value=0;*s != '\0';s++)
		hash_value += *s + 31 ;
	return hash_value % HASHSIZE;

}
//searches the lookup table for the presence of the string s if available the pointer to that structure is return else NULL
struct nlist *lookup1(char *s){

	struct nlist *np;
	unsigned num=hash1(s);
	np=hashtable[num];
	if(np==NULL)
	return NULL;
	for ( ;np != NULL;np=np->next)
		if(strcmp(np->name,s)==0)
			return np;
		else 
			return NULL;	
}
//function to insert a name and it definition into the lookup table
struct nlist *install_lookup(char *name,char *definition){
	unsigned hashvalue;
	struct nlist *np;
	np=lookup1(name);
	if(np==NULL){
		np=(struct nlist *)malloc(sizeof(*np));
		if(np==NULL|| (np->name=strdup(name))==NULL){
			return NULL;

		}
		hashvalue=hash1(name);
		np->next = hashtable[hashvalue];
		hashtable[hashvalue] = np;
	} else
/* already there */
		free((void *) np->defn);
/*free previous defn */
		if ((np->defn = strdup(definition)) == NULL)
		return NULL;
		return np;
}
